#!/usr/bin/env bash

# This benchmark cannot be integrated into test.c
# because of branch prediction.
# When benchmarking, remove the printf statement
# that prints all computed numbers to make the
# benchmarking process faster.

naive_total=0
simd_total=0
runs=1000

for ((i=1; i<=runs; i++)); do
    output=$(../build/bin/sqr)

    naive=$(echo "$output" | grep "Naive" | awk '{print $2}' | sed 's/μs//')
    simd=$(echo "$output" | grep "SIMD"  | awk '{print $2}' | sed 's/μs//')

    naive_total=$(echo "$naive_total + $naive" | bc -l)
    simd_total=$(echo "$simd_total + $simd" | bc -l)
done

naive_avg=$(echo "$naive_total / $runs" | bc -l)
simd_avg=$(echo "$simd_total / $runs" | bc -l)

echo "Average over $runs runs:"
echo "  Naive: $naive_avg μs"
echo "  SIMD:  $simd_avg μs"
