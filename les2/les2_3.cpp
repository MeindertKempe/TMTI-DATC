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
 * Exercise 2-3 Check palindrome
 *
 * Write the following function to check whether a string is a palindrome
 * assuming the letters are case-insensitive:
 *
 *     bool isPalindrome(const std::string& s)
 *
 * Write a test rpograms that reads a string and display whether it is a
 * palindrome. Here are some sample runs:
 *
 *     Enter a string: ABa
 *     aba is a palindrome
 *
 *     Enter a string: AcBa
 *     acba is not a palindrome
 */

#include <iostream>

bool is_palindrome(std::string s) {
	for (size_t i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}

int main() {
	std::cout << "Enter a string: ";
	std::string s;
	std::getline(std::cin, s);
	for (size_t i = 0; i < s.length(); ++i) { s[i] = tolower(s[i]); }

	std::cout << s << " is" << (is_palindrome(s) ? " " : " not ")
	          << "a palindrome" << std::endl;

	return 0;
}
