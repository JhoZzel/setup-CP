#!/bin/bash

g++ Gen.cpp -o Gen
g++ Checker.cpp -o Checker
g++ Correct.cpp -o Solution
g++ a.cpp

ver="Accepted"
tt=10 # test cases
for ((i = 1; i <= $tt; i++)); do
    ./Gen > In
    echo "Running on test $i"
    ./Solution < In > Out1
    timeout 20 ./a.out < In > Out2
    ./Checker In Out2 Out1 Verdict
    ver=$(cat ver)
    if [ "$ver" != "Accepted" ]; then
        break
    fi
done

echo "$ver"
