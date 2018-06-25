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
                function += "// " + code.to_s + "\n"
            end
        }

        function += "}\n"
        functions[i] = function
    }

    functions
end