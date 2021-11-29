cd analysis
bison -Wno-conflicts-sr -d ./parser.y
flex ./scanner.l
cd ..
gcc -o ./compiler ./*.c ./*/*.c ./*/*/*.c ./*/*/*/*.c -lfl -Wall