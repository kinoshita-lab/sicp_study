def label_to_function label
    s = "void #{label}()"
end

def output_function_prototypes labels
    File.open("compiled.out.function_prototypes.h", "w") { |f|
        f.puts("#pragma once")
        labels.each { |label|
            f.puts(label_to_function(label) + ";")
        }
    }
end

def labelToSource label
    s = "\tif(strLabel == \"#{label.upcase}\") return #{label}();"
end

def output_goto_with_label labels
    File.open("goto_with_label.cpp", "w") { |f|
        f.puts <<-EOS
#include <string>
#include "types.h"
#include "goto_with_label.h"
#include "compiled.out.function_prototypes.h"

void goto_with_label(const char* label)
{
    const auto strLabel = std::string(label);
EOS

        labels.each {|label|
            f.puts labelToSource label
        }
        f.puts <<-EOS2
    if (strLabel == "return") {
        throw "finished";
    }
}

void goto_with_label(const SchemeDataType* reg)
{
    if (reg->type == SchemeDataType::TypeId::String) {
        return goto_with_label(reg->stringValue);
    }

    if (reg->type == SchemeDataType::TypeId::CompiledProcedure)
    {
        return (*reg->compiledProcedure)();
    }

    return;
}
EOS2
    }
end

class FunctionCodeGenerator
    def initialize labels, codes
        @labels = labels
        @codes = codes
        @labelIndex = -1
        @outputFile = "compiled.out.converted.cpp"
    end

    def generate
        File.open(@outputFile, "w") {|f|
            @codes.each {|code|
                f.puts code2Cpp(code) + "// #{code}"
            }
            f.puts "}"
        }

    end

    def initialLabel code
        @labelIndex += 1
        s = label_to_function @labels[@labelIndex]
        s += "\{\n"
        s += code2Cpp(code)
    end

    def label? code
        return code.class === "String"
    end

    def label code
        @labelIndex += 1
        nextIsEntry = @labels[@labelIndex] =~ /entry/
        nextIsPrimitive = @labels[@labelIndex] =~ /primitive/
        nextIsFalse = @labels[@labelIndex] =~ /false/
        if (@labelIndex != 1 && !nextIsEntry && !nextIsPrimitive && !nextIsFalse)
            s = "#{@labels[@labelIndex]}();\n}\n"
        else
            s = "\n}\n"
        end

        s += "#{label_to_function(@labels[@labelIndex])}\n{"
    end

    def restore? code
        car(code) === "restore"
    end

    def restore code
        reg = cadr(code)
        s = "s.restore(#{reg.upcase});"
    end

    def save? code
        car(code) === "save"
    end

    def save code
        reg = cadr(code)
        s = "s.save(#{reg.upcase});"
    end

    def goto? code
        car(code) === "goto"
    end

    def goto code
        dest = cdr(code)
        
        label_or_reg = car(cdr(car(dest)))

        if (car(car(dest)) === 'label')
            return "goto_with_label(\"#{label_or_reg.upcase}\");"
        end

        # reg otherwise
        return "goto_with_label(registers[#{label_or_reg.upcase}]);"
    end

    def arg1 code
        "registers[#{cadr(car(cdr(cdr(code)))).upcase}]"
    end


    def opcode opname, code
        case opname
        when 'primitive_procedure_p'
            return "primitive_procedure_p(#{arg1(code)})"
        when 'false_p'
            return "false_p(#{arg1(code)})"
        when 'make_compiled_procedure'
            label = cadr(cadr(code))
            return "make_compiled_procedure(\"#{label.upcase}\", #{label}, registers[ENV])"
        when 'compiled_procedure_env'
            return "compiled_procedure_env(PROC)"
        when 'list'
            return "list(registers[VAL])"
        when 'apply_primitive_procedure'
            return "apply_primitive_procedure(registers[PROC], registers[ARGL])"
        when 'compiled_procedure_entry'
            return "compiled_procedure_entry(registers[PROC])"
        when 'cons'
            return "cons(registers[VAL], registers[ARGL])"
        when 'lookup_variable_value'
            symbol = cadr(cadr(code))
            return "lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, \"#{symbol}\"), registers[ENV])"
        when 'extend_environment'
            symbol = car(cadr(cadr(code)))
            symbol2 = cadr(cadr(code))
            s = []
            if symbol.nil?
                s << "extend_environment(new SchemeDataType(SchemeDataType::TypeId::Nil), registers[ARGL], registers[ENV])"
                return s
            end
            length = symbol2.length

            if length == 1
                return "extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, \"#{symbol}\"), registers[ARGL], registers[ENV])"
            end

            symbols = symbol2.to_s
            symbols.gsub!("(", "")
            symbols.gsub!(")", "")
            symbols = symbols.split(" ")

            ss = []
            
            symbols.each {|symbol|
                ss << "new SchemeDataType(SchemeDataType::TypeId::Symbol, \"#{symbol}\") "
            }

            l = ""
            ss.each_with_index { |s, i|
                l += s
                if i != ss.length - 1
                    l += ", "
                end
            }
            
            return "extend_environment(list(#{ss.length}, #{l}), registers[ARGL], registers[ENV])"
        else
            opname #
        end
    end

    def test? code
        car(code) === "test"
    end

    def test_ code
        # testの先は全部 opぽい
        opname = car(cdr(car(cdr(code))))
        "if ( #{opcode(opname, code)} ) {"
    end

    def branch? code
        car(code) === "branch"
    end

    def branch code
        label = car(cdr(cadr(code)))
        "return goto_with_label(\"#{label.upcase}\");\n}"
    end

    def assign? code
        car(code) === "assign"
    end

    def perform? code
        car(code) === "perform"
    end

    def number_only_string? s
        s =~/\A[0-9]+\z/
    end

    def const constcode, string=true
        val = cadr(constcode)

        if number_only_string? val
            return "new SchemeDataType(SchemeDataType::TypeId::Integer, #{val})"
        end

        if val.nil?
            return "new SchemeDataType(SchemeDataType::TypeId::Nil)"
        end

        val.gsub!("\"", "")
        if string
            return "new SchemeDataType(SchemeDataType::TypeId::String, \"#{val}\")"
        end

        return "new SchemeDataType(SchemeDataType::TypeId::Symbol, \"#{val}\")"
    end

    def assign code
        dest = cadr(code)
        rest = cddr(code)
        source = car(car(rest)) # なんか変
        s = ""
       
        case source
        when 'op'
            op  = opcode(cadr(car(rest)), rest)
            if op.class === "String"
                s = "#{opcode(cadr(car(rest)), rest)}"
            else
                op.each {|o|
                    s += "assign(#{dest.upcase}, #{o});\n"
                }
                return s
            end
            s = "#{opcode(cadr(car(rest)), rest)}"
        when 'const'
            s = const car(rest)
        when 'label'
            s = "new SchemeDataType(SchemeDataType::TypeId::String, \"#{cadr(car(rest)).upcase}\")"
        when 'reg'
            s = "registers[#{cadr(car(rest)).upcase}]"
        else
            s = "assign: unknown source #{source}"
        end

        "assign(#{dest.upcase}, #{s});"
    end

    def code2Cpp code
        if @labelIndex == -1
            return initialLabel code
        end

        if label? code
            return label code
        end

        if restore? code
            return restore code
        end

        if save? code
            return save code
        end

        if goto? code
            return goto code
        end

        if test? code
            return test_ code
        end

        if branch? code
            return branch code
        end

        if assign? code
            return assign code
        end

        if perform? code # define variableしかない
            name = cadr(caddr(code))
            return "define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, \"#{name}\"), registers[VAL], registers[ENV]);"
        end


        return "// #{code.to_s}"
    end
end