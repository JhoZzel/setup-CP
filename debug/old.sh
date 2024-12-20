#!/bin/bash

g++ Gen.cpp -o Gen
g++ Checker.cpp -o Checker
g++ Correct.cpp -o Solution
g++ a.cpp -o Bad

ver="Accepted"
tt=500 # test cases
for ((i = 1; i <= $tt; i++)); do
    ./Gen > input
    echo "Running on test $i"
    ./Solution < input > out1
    timeout 20 ./Bad < input > out2
    ./Checker input out2 out1 ver
    ver=$(cat ver)
    if [ "$ver" != "Accepted" ]; then
        break
    fi
done

echo "$ver"
