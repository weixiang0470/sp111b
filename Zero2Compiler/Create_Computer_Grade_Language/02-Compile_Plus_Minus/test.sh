#!/bin/bash
try() {
    expected="$1"
    input="$2"

    ./wwx02 "$input" > tmp.s
    gcc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}

try 201 "5+200-4"
try 0 0
try 42 42

echo ok
