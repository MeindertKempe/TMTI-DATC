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
 * Exercise 1-2 Credit Card number validator
 *
 * Credit card numbers follow certain pattern. A credit card number must have
 * between 13 and 16 digits. The number must start with the following:
 *
 *     * 4 for Visa cards
 *     * 5 for MasterCard cards
 *     * 37 for American Express cards
 *     * 6 for Discover cards
 *
 * In 1954 Hans Luhn of IBM proposed an algorithm for validating credit card
 * numbers. The algorithm is useful to determine whether a card number is
 * entered correctly or is scanned correctly by a scanner. Almost all credit
 * card numbers are generated following this validity check, commonly known as
 * the Luhn check or the Mod 10 check. It can be destribed as follows. (For
 * illustration, consider the card number 4388576018402626.)
 *
 *     1. Double every second digit from the right to left. IF doubling of a
 *     digit results in a two-digit number, add the two digits to get a single
 *     digit number. Example CC
 *     2. Now add all single-digit numbers from Step 1.
 *     4 + 4 + 8 + 2 + 3 + 1 + 7 + 8 = 37
 *     3. Add all digits in the odd places from right to left in the card
 *     number. 6 + 6 + 0 + 8 + 0 + 7 + 8 + 3 = 38
 *     4. Sum the results from Step 2 and Step 3. 37 + 38 = 75
 *     5. If the result from Step 4 is divisable by 10, the card number is
 *     valid; otherwise, it is invalid. For example 4388576018402626 is invalid,
 *     but the number 4388576018410707 is valid.
 *
 * Write a program that prompts the user to enter a credit card number as a
 * string. Display whether the number is valid. Design your program using the
 * following methods:
 *
 *     // Return true if the card number is valid
 *     bool isValid(const std::string& cardNumber);
 *
 *     // Get the result from Step 2
 *     int sumOfDoubleEvenPlace(const std::string& cardNumber);
 *
 *     // Return this number if it is a single digit, otherwise,
 *     // return the sum of the two digits
 *     int getDigit(int number);
 *
 *     // Return sum of odd-place digits in the card number
 *     int sumOfOddPlace(const std::string& cardNumber);
 *
 *     // Return true if substr is the prefix for cardNumber
 *     bool startsWith(const std::string& cardNumber, const std::string&
 *                     substr);
 *
 * Write a test program that prompts the user to enter the string and character
 * and display if the character is found.
 */

#include <iostream>
#include <stdexcept>
#include <string>

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number) {
	if (number < 0 || number > 99)
		throw std::out_of_range(
		    "number should be between 0 and 99 (inclusive)");

	if (number < 10) return number;

	return (number / 10) + (number % 10);
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string &cardNumber) {
	int sum = 0;
	for (size_t i = 0; i < cardNumber.length(); i += 2) {
		sum += getDigit((cardNumber.at(i) - '0') * 2);
	}
	return sum;
}

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string &cardNumber) {
	int sum = 0;
	for (size_t i = 1; i < cardNumber.length(); i += 2) {
		sum += cardNumber.at(i) - '0';
	}
	return sum;
}

// Return true if substr is the prefix for cardNumber
// What even is the point of this function????
bool startsWith(const std::string &cardNumber, const std::string &substr) {
	return cardNumber.substr(0, substr.length()) == substr;
}

// Return true if the card number is valid
bool isValid(const std::string &cardNumber) {
	int sum = sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber);
	if (sum % 10 == 0) return true;
	else return false;
}

int main() {
	std::string s;
	std::cout << "Card number: ";
	getline(std::cin, s);
	bool res = isValid(s);
	if (res) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	return !res;
}
