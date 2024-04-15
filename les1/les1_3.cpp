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
 * Exercise 1-3 Counting characters
 *
 * Write a method that counts the occurence of each letter in the string using
 * the following header:
 *
 *     void count(const char s[], int counts[]);
 *
 * Where counts is an array of 26 integers, counts[0], counts[1], ..., and
 * counts[25] count the occurence of a,b,…. and z, respectively. Letters are not
 * case-sensitive, i.e. letter A and a are counted the same as a.
 *
 * Write a test program that reds a string, invokes the count method, and
 * displays the non-zero counts. Here is a sample run of the program:
 *
 *     Enter a string: Welcome to New York!
 *     c: 1 times
 *     e: 3 times
 *     k: 1 times
 *     l: 1 times
 *     m: 1 times
 *     n: 1 times
 *     o: 3 times
 *     r: 1 times
 *     t: 1 times
 *     w: 2 times
 *     y: 1 times
 */

#include <cstddef>
#include <ctype.h>
#include <iostream>

void count(const char s[], int counts[]) {
	while (*s) {
		size_t c = tolower(*s) - 'a';
		if (c < 26) { counts[c]++; }
		s++;
	}
}

int main() {
	std::string s;
	std::cout << "Enter a string: ";
	getline(std::cin, s);
	int *counts = new int[26];
	count(s.c_str(), counts);
	for (size_t i = 0; i < 26; ++i) {
		if (!counts[i]) continue;
		std::cout << (char)('a' + i) << ": " << counts[i] << "times \n";
	}
	return 0;
}
