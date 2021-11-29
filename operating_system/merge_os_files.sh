sh generate_compiler.sh
../compiler ./STORE_LOAD.txt 3
../compiler ./so.txt
../compiler ./JUMP0.txt 3
../compiler ./p1.txt
../compiler ./p2.txt
cat STORE_LOAD/binaryCode.txt so/binaryCode.txt JUMP0/binaryCode.txt p1/binaryCode.txt p2/binaryCode.txt > mergedBinary.txt