#!/bin/bash
clang++ -std=c++17 $1.cpp -o $1 
./$1
rm $1

