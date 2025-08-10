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

#ifndef SQR_H
#define SQR_H

#include <stdint.h>

long sqr_n_idx(const long n);
void find_squares(const int i, long *nums);
void find_squares_simd(size_t n, int32_t *nums);

#endif //SQR_H
