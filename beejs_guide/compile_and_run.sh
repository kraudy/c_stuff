#!/bin/bash

# Check if a source file argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <source_file.c>"
    exit 1
fi

# Assign the input argument to a variable
SOURCE_FILE="$1"

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: File '$SOURCE_FILE' not found!"
    exit 1
fi

# Extract the base name (without .c extension)
BASE_NAME="${SOURCE_FILE%.c}"

# Compile the source file with clang
echo "Compiling $SOURCE_FILE with clang..."
clang "$SOURCE_FILE" -o "$BASE_NAME"

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Error: Compilation failed!"
    exit 1
fi

# Run the compiled program
echo "Running $BASE_NAME..."
./"$BASE_NAME"

# Delete the compiled binary
echo "Deleting compiled binary $BASE_NAME..."
rm -f "$BASE_NAME"

echo "Done!"