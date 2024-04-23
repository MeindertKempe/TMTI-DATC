/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2024 Meindert Kempe
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Exercise 2-1 Stopwatch
 *
 * Design a class named StopWatch. The class contains:
 *
 *     * Private data fields startTime and endTime, including getters.
 *     * A constructor without any parameters that initialize the startTime with
 * the current time.
 *     * Method void start() thats reset the startTime to the current time.
 *     * Method void stop that sets the endTime to the current time.
 *     * Method getElapsedTime() that returns the elapsed time for the stopwatch
 * in miliseconds.
 *
 * Implement the class. Write a test program that measure the execution time of
 * sorting 100000 numbers using [sort]
 * (http://www.cplusplus.com/reference/algorithm/sort/).
 *
 * hint: Take a look at the high [resolution clock]
 * (https://en.cppreference.com/w/cpp/chrono/high_resolution_clock).
 */

#include "StopWatch.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <iostream>

#define COUNT 100000

int main() {
	int32_t *nums = new int32_t[COUNT];
	std::default_random_engine en;
	std::uniform_int_distribution<int32_t> dist(INT32_MIN, INT32_MAX);
	for (size_t i = 0; i < COUNT; ++i) { nums[i] = dist(en); }
	StopWatch sw;
	sw.start();
	std::sort(nums, nums + COUNT);
	sw.stop();
	std::cout << sw.getElapsedTime().count() << std::endl;
	delete[] nums;
	return 0;
}
