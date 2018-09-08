def generate_prototypes labeled_codes
    prototypes = Array.new
    labeled_codes.each {|l|
        prototype = "void " + l[0] + "();"
        prototypes << prototype
    }

    prototypes
end


def label? code
    code.is_a?(String)
end

def schemeCodeToCpp code
    case code
        when "(goto (reg continue))"
        return "\treturn;"
        when "(assign val (const 1))"
        return "\tassign(VAL, new SchemeDataType(SchemeDataType::Integer, 1));"
    else
        return code
    end
end

def generate_functions labeled_codes
    functions = generate_prototypes labeled_codes
    functions.each_with_index {|function, i|
        # remove ; from prorotype
        function_prorotype = function
        function.gsub!(";", "\n")
        function += "{\n"

        labeled_codes[i][1..-1].each{ |code|
            if label? code
                function += code + ":\n;\n"
            else
                function += schemeCodeToCpp(code.to_s) + "\n"
            end
        }

        function += "}\n"
        functions[i] = function
    }

    functions
end