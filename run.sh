#!/bin/bash

mkdir -p bin obj

# Compile C files

find src/$1 -type f -name *.c | while read -r f; do
    echo "Compiling: $f"
    output="obj/$(basename ${f%.c}).o"
    gcc -c $f -o $output -lm -lGL -lGLU -lglut
done

# Link object files

echo "Linking object files"
gcc obj/*.o -o bin/$1 -lm -lGL -lGLU -lglut

# Remove object files

rm obj/*.o

# Run

if [ $# -gt 1 ]; then
    ./bin/$1 "${@:1}"
else
    ./bin/$1
fi
