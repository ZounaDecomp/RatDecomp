import sys
import os

def make_guard(filename):
    base = os.path.splitext(os.path.basename(filename))[0]
    guard = f"_{base.upper()}_H_"
    return guard

with open(sys.argv[1], 'r') as f:
    lines = f.readlines()

for line in lines:
    line = line.strip()
    if not line or line.startswith("Sections:"):
        continue

    if line.endswith(":") and not line.lower().startswith("3rdparty"):
        fileName = f'src/{line[:-1]}'
        baseName = os.path.splitext(os.path.basename(fileName))[0]
        # Insert 'includes' after the parent directory
        src_dir = os.path.dirname(fileName)
        header_dir = os.path.join(src_dir, "includes")
        headerPath = os.path.join(header_dir, f"{baseName}.h")
        os.makedirs(os.path.dirname(fileName), exist_ok=True)
        os.makedirs(header_dir, exist_ok=True)
        if not os.path.exists(fileName):
            with open(fileName, 'w') as outf:
                outf.write(f'#include "{baseName}.h"\n')
                print(f"Creating {fileName}")
        if not os.path.exists(headerPath):
            with open(headerPath, 'w') as outf:
                outf.write(f'#ifndef {make_guard(baseName + ".h")}\n#define {make_guard(baseName + ".h")}\n#include "Types_Z.h"\n#endif // {make_guard(baseName + ".h")}\n')
            print(f"Creating {headerPath}")

