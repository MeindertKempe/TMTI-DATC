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
 * Exercise 1-4 Matrix sum
 *
 * Write a method that returns the sum of all the elements in a specific column
 * in a matrix using the following header:
 *
 *     const int SIZE = 4;
 *     double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);
 *
 * Write a test program that reads a 3-by-4 matrix and displays the sum of each
 * column. Here is a sample run:
 *
 *     Enter a 3-by-4 matrix row by row:
 *     1.5 2 3 4
 *     5.5 6 7 8
 *     9.5 1 3 1
 *     Sum of the elements at column 0 is 16.5
 *     Sum of the elements at column 1 is 9
 *     Sum of the elements at column 2 is 13
 *     Sum of the elements at column 3 is 13
 */

#include <iostream>

const int SIZE = 4;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
	double sum = 0;
	for (int i = 0; i < rowSize; ++i) { sum += m[i][columnIndex]; }
	return sum;
}

double matrix[3][SIZE];
int main() {
	std::cout << "Enter a 3-by-4 matrix row by row:" << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < SIZE; ++j) { std::cin >> matrix[i][j]; }
	}
	for (int i = 0; i < SIZE; ++i) {
		std::cout << "Sum of the elements at column " << i << " is "
		          << sumColumn(matrix, 3, i) << '\n';
	}
}
