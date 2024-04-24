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
 * Exercise 2-4 Hangman
 *
 * Write a hangman games that randomly generates a word and prompts the user to
 * guess one letter at a time, as shown in the sample run. Each letter in the
 * word is displayed in an asterik. When the user makes a correct guess, the
 * actual letter is then displayed. When the user finishes a word, display the
 * number of misses and ask the user whether to continue for another word.
 * Declare an array to store the words as follows:
 *
 *     std::vector<std::string> words = {"write", "that", "school, ...};
 *
 *     (Guess) Enter a letter in the word ******* > p
 *     (Guess) Enter a letter in the word p****** > r
 *     (Guess) Enter a letter in the word pr**r** > p
 *          p is already in the word
 *     (Guess) Enter a letter in the word pr**r** > o
 *     (Guess) Enter a letter in the word pro*r** > g
 *     (Guess) Enter a letter in the word progr** > n
 *          n is not in the word
 *     (Guess) Enter a letter in the word progr** > m
 *     (Guess) Enter a letter in the word progr*m > a
 *     The word is program. You missed 1 time.
 *
 *     Do you want to guess for another word? enter y or n >
 */

#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

std::vector<std::string> words = { "write", "that", "school", "program" };

enum hm_res {
	HM_FALSE = 0,
	HM_TRUE,
	HM_DOUBLE,
	HM_COMPLETE,
};

enum hm_res try_char(std::string &word, std::string &disp, char c) {
	if (word.length() != disp.length())
		throw std::invalid_argument("word and disp differ in length");

	enum hm_res res  = HM_FALSE;
	bool in_word     = false;
	bool is_complete = true;
	for (size_t i = 0; i < word.length(); ++i) {
		if (disp[i] == '*' && word[i] != c) is_complete = false;
		if (word[i] != c) continue;
		if (disp[i] == c) in_word = true;
		disp[i] = c;
		res     = HM_TRUE;
	}
	if (in_word) res = HM_DOUBLE;
	if (is_complete) res = HM_COMPLETE;
	return res;
}

int main() {
	std::default_random_engine en;
	std::uniform_int_distribution<size_t> dist(0, words.size() - 1);
	std::string word = words[dist(en)];
	std::string disp(word.length(), '*');

	size_t misses{ 0 };

	for (;;) {
		std::cout << "(Guess) Enter a letter in the word " << disp << " > ";
		char in;
		std::cin >> in;
		enum hm_res res = try_char(word, disp, in);
		if (res == HM_FALSE) {
			misses++;
			std::cout << "    " << in << " is not in the word\n";
		} else if (res == HM_DOUBLE)
			std::cout << "    " << in << " is already in the word\n";
		else if (res == HM_COMPLETE) {
			std::cout << "The word is " << word << ". You missed " << misses
			          << " time.\n";
			for (;;) {
				std::cout
				    << "\nDo you want to guess for another word? enter y or "
				       "n >";
				std::cin >> in;
				if (in == 'n') goto end;
				else if (in == 'y') {
					misses = 0;
					word   = words[dist(en)];
					disp   = std::string(word.length(), '*');
					break;
				}
			}
		}
	}
end:
	return 0;
}
