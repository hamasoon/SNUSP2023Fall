#!/bin/bash

# print the words in a file in alphabetical order

TARGET="."

if [ -n "$1" ]; then
    TARGET=$1
fi

if [ ! -d $TARGET ]; then
    echo "Dir $TARGET does not exist."
    exit 1
fi

echo "Total size of $TARGET is : `find $TARGET -type f -printf "%s\n" | paste -s -d+ | bc`"