#!/bin/bash

# print the words in a file in alphabetical order

TARGET="words.txt"

if [ -n "$1" ]; then
    TARGET=$1
fi

if [ ! -f $TARGET ]; then
    echo "File $TARGET does not exist."
    exit 1
fi

echo `cat $TARGET | sort | uniq`