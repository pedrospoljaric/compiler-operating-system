The modeling of both analysis and synthesis phases of the compiler can be found in the `modeling` folder.

To compile a C- code, run the script `generate_compiler.sh` with the code file you want to compile. Example:

```
sh generate_compiler.sh tests/sort.txt
```

The script will create a folder with the same name and location as the source code, where five output files can be found. Example:

If the file `sort.txt` is inside a folder called `tests`, a subfolder named `sort` will be created inside `tests`with the following output files:

- `./tests/sort/stab.txt` - contains a visual representation of the symbol table generated on the analysis phase

- `./tests/sort/ptree.txt` - contains a visual representation of the syntatic tree generated on the analysis phase

- `./tests/sort/intermediateCode.txt` - contains the intermediate code generated on the synthesis phase

- `./tests/sort/assemblyCode.txt` - contains the assembly code generated on the synthesis phase

- `./tests/sort/binaryCode.txt` - contains the final binary code generated on the synthesis phase

---

The `operating_system` folder contains files with the source code of the operating system developed in C-, along with a script that compiles and merges the parts to create the operating system binary file.
