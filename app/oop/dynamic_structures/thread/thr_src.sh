#!/bin/bash
clang++ -std=c++17 thr_mutex.cpp -o thr_mutex # 17++
./thr_mutex
rm thr_mutex

