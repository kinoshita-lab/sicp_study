def generate_prototypes labeled_codes
    prototypes = Array.new
    labeled_codes.each {|l|
        prototype = "void " + l[0] + "();"
        prototypes << prototype
    }

    prototypes
end

def generate_functions labeled_codes
    functions = generate_prototypes labeled_codes
    functions.each_with_index {|function, i|
        # remove ; from prorotype
        function_prorotype = function
        function.gsub!(";", "\n")
        function += "{\n"

        labeled_codes[i][1..-1].each{ |code|
            function += "// " + code.to_s + "\n"
        }

        # for label handling: simply call next function
        if i != labeled_codes.length - 1
            next_function = functions[i + 1]
            next_function_call = next_function.gsub("void ", "")
            function += "\t" + next_function_call + "\n"
        else
            function += "\treturn; \n"
        end

        function += "}\n"
        functions[i] = function
    }

    functions
end