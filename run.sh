#!/bin/zsh

if [[ $# != 1 ]]; then
    echo "対象の問題番号を指定してね [a-f]"
    exit 1
else
    clang++ $1.cc -o test -std=c++17 -stdlib=libc++
    ./test    
    rm ./test
fi
