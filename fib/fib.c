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

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long n = strtoul(argv[1], NULL, 10);
    mpz_t fib;
    mpz_init(fib);
    
    if (n <= 1) {
        mpz_set_ui(fib, n);
    } else {
        mpz_t a, b, temp1, temp2;
        mpz_inits(a, b, temp1, temp2, NULL);
        mpz_set_ui(a, 0); // F(0)
        mpz_set_ui(b, 1); // F(1)
    
        // Count the number of bits in n
        int bits = 0;
        int t = n;
        while (t > 0) {
            bits++;
            t >>= 1;
        }

        for (int i = bits - 1; i >= 0; i--) {
            // F(2m) = a * (2*b - a)
            mpz_mul_2exp(temp1, b, 1);    // 2*b
            mpz_sub(temp1, temp1, a);     // 2*b - a
            mpz_mul(temp2, a, temp1);     // F(2m)

            // F(2m+1) = a^2 + b^2
            mpz_mul(temp1, a, a);         // a^2
            mpz_mul(a, b, b);             // b^2 (reuse a after its value is used)
            mpz_add(temp1, temp1, a);     // a^2 + b^2 = F(2m+1)
    
            // Update (a, b) based on the current bit
            if (n & (1 << i)) {
                // bit == 1: set a = F(2m+1), b = F(2m+2) = F(2m) + F(2m+1)
                mpz_set(a, temp1);
                mpz_add(b, temp2, temp1);
            } else {
                // bit == 0: set a = F(2m), b = F(2m+1)
                mpz_set(a, temp2);
                mpz_set(b, temp1);
            }
        }
    
        mpz_set(fib, a);
        mpz_clears(a, b, temp1, temp2, NULL);
    }

    gmp_printf("%Zd\n", fib);
    mpz_clear(fib);

    return EXIT_SUCCESS;
}