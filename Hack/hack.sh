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
    ./Solution < In > OutOK
    timeout 20 ./a.out < In > Out
    ./Checker In Out OutOK Verdict
    ver=$(cat Verdict)
    if [ "$ver" != "Accepted" ]; then
        break
    fi
done

echo "$ver"
