#@author Sabe
#@category RatDecomp

import os

script_dir = os.path.dirname(getSourceFile().getAbsolutePath())
output_dir = os.path.join(script_dir, "sinits")

if not os.path.exists(output_dir):
    os.makedirs(output_dir)

font_symbols = currentProgram.getSymbolTable().getSymbols("fontName")

for symbol in font_symbols:
    label_addr = symbol.getAddress()
    references = getReferencesTo(label_addr)

    for ref in references:
        from_addr = ref.getFromAddress()
        function = getFunctionContaining(from_addr)

        if function and "sinit" in function.getName():
            name = function.getName()
            prefix = "__sinit_"
            suffix = "_cpp"

            if name.startswith(prefix) and name.endswith(suffix):
                file_base = name[len(prefix):-len(suffix)]
                file_name = file_base + ".cpp"
                full_path = os.path.join(output_dir, file_name)

                cpp_code = '#include "Names.h"'

                with open(full_path, "a") as f:
                    f.write(cpp_code)

                print("Appended code to: {}".format(full_path))
