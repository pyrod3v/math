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

#include <stdio.h>
#include <time.h>

long nums[10000];

long sqr_n_idx(const long n) {
    // x = n*n/2
    // finds the x value corresponding to the provided n value
    long x = (n + (n & 1)) >> 1;
    return x * x;
}

void find_squares(const int i) {
    // finds an i amount of square numbers
    int n = 3;
    int x = 1;
    for (int j = i; j > 0; j--) {
        x = n + x;
        nums[i - j] = x;

        //printf("n: %i, x: %i\n", n, x);

        // prepare n for next step
        n += 2;
    }
}

int main() {
    float start = (float)clock();
    find_squares(10000);
    float end = (float)clock();

    for (int i = 0; i < 10000; i++) {
        printf("%ld\n", nums[i]);
    }

    printf("Time: %fμs\n", (end - start));
}