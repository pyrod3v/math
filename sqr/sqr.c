/*
Copyright 2025 pyrod3v
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <immintrin.h>

unsigned long sqr_n_idx(size_t n) {
    // x = n*n/2
    // finds the x value corresponding to the provided n value
    unsigned long x = (n + (n & 1)) >> 1;
    return x * x;
}

void find_squares(const int i, unsigned long *nums) {
    // finds an i amount of square numbers
    unsigned long n = 3;
    unsigned long x = 1;
    for (int j = i; j > 0; j--) {
        x = n + x;
        nums[i - j] = x;

        //printf("n: %i, x: %i\n", n, x);

        // prepare n for next step
        n += 2;
    }
}

void find_squares_simd(const size_t n, unsigned int *nums) {
    const size_t lanes = 8; // AVX2 is 256-bit / 32-bit -> 8 lanes
    const __m256i inc = _mm256_setr_epi32(0,1,2,3,4,5,6,7);

    for (size_t i = 0; i + lanes <= n; i += lanes) {
        __m256i base = _mm256_set1_epi32((int32_t)i + 2);
        __m256i n = _mm256_add_epi32(base, inc); // i+2, i+3, etc
        __m256i x  = _mm256_mullo_epi32(n, n);
        _mm256_storeu_si256((__m256i*)(nums + i), x);
    }

    for (int i = 0; i < n; ++i) {
        int32_t v = i + 2;
        nums[i] = v * v;
    }
}