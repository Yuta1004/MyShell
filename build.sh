#!/bin/bash

# Build Original Libraries
## Str
echo -n "Building \"Str\" Lib..." &&
cd ./str &&
gcc -g -static   -c -o replace.o replace.c &&
gcc -g -static   -c -o split.o split.c &&
ld -r replace.o split.o -o libstr.o &&
echo "OK" &&

## Vector
echo -n "Building \"Vector\" Lib..." &&
cd ../vector &&
gcc -g -static   -c -o vector.o vector.c &&
ld -r vector.o -o libvector.o &&
echo "OK"

## Command
echo -n "Building \"Command\" Lib..." &&
cd ../command &&
gcc -g -static   -c -o command.o command.c &&
gcc -g -static   -c -o convert.o convert.c &&
gcc -g -static   -c -o default_func.o default_func.c &&
gcc -g -static   -c -o exec.o exec.c &&
ld -r command.o convert.o default_func.o exec.o -o libcommand.o &&
echo "OK" &&

# Build Original Commands
echo -n "Building Original Commands..." &&
cd ../bin &&
gcc -o help help.c &&
gcc -o rabbit rabbit.c &&
echo "OK" &&

# Build Executable File
echo -n "Building Executable File..." &&
cd ../ &&
gcc -g -static -c -o main.o main.c
gcc -o myshell_i17027 main.o command/libcommand.o str/libstr.o vector/libvector.o &&
echo "OK" &&
echo "Complete!" &&
echo "Usage: ./myshell_i17027"
