#include <stdio.h>
#include <time.h>

#include "sqr.h"

inline long long elapsed_ns(const struct timespec start, const struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000LL +
           (end.tv_nsec - start.tv_nsec);
}

int main() {
    unsigned long nums[10000]; uint32_t nums_simd[10000];

    struct timespec t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);
    find_squares(10000, nums);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    long long time = elapsed_ns(t1, t2);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    find_squares_simd(10000, nums_simd);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    long long time_simd = elapsed_ns(t1, t2);

    for (int i = 0; i < 10000; i++) {
        printf("%ld - %i\n", nums[i], nums_simd[i]);
    }

    printf("Time:\n  Naive: %fμs\n  SIMD: %fμs\n", (double)time/1000, (double)time_simd/1000);
}