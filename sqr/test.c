#include <stdio.h>
#include <time.h>

#include "sqr.h"

int main() {
    unsigned long nums[10000]; uint32_t nums_simd[10000];

    float start = (float)clock();
    find_squares(10000, nums);
    float end = (float)clock();
    float time = (end - start);

    start = (float)clock();
    find_squares_simd(10000, nums_simd);
    end = (float)clock();
    float time_simd = (end - start);

    for (int i = 0; i < 10000; i++) {
        printf("%ld - %i\n", nums[i], nums_simd[i]);
    }

    printf("Time:\n  Naive: %fμs\n  SIMD: %fμs\n", time, time_simd);
}