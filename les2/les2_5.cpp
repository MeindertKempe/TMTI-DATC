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
 * Exercise 2-5 Largest block
 *
 * Given a square matrix with elements 0 or 1, write a program that find a
 * maximum square submatrix whose elements are all 1`s. Your program should
 * prompt the user to enter the number of rows in the matrix and then the matrix
 * and displays the location of the first element in the maximum square
 * submatrix and the number of the rows in the submatrix. Assume the maximum
 * number of rows is 100.
 *
 * Here is a sample run:
 *
 *     Enter the number of rows for the matrix: 5
 *     Enter the matrix row by row:
 *     1 0 1 0 1
 *     1 1 1 0 1
 *     1 0 1 1 1
 *     1 0 1 1 1
 *     1 0 1 1 1
 *     The maximum square submatrix is at (2, 2) with size 3
 *
 * Your program should implement and use the following function to find the
 * maximum square matrix:
 *
 *     std::vector<int> findLargestBlock(const std::vector<std::vector<int>>&
 *                                       m);
 *
 * The return value is a vector that consists of three values. The first values
 * are the row and column indices for the first element in the submatrix and the
 * third value is the number of rows in the submstrix.
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> findLargestBlock(const std::vector<std::vector<int>> &m) {
	// iterate over matrix
	size_t max_x = -1, max_y = -1, max_s = 0;
	for (size_t y = 0; y < m.size(); ++y) {
		for (size_t x = 0; x < m[y].size(); ++x) {
			// iterate over squares
			bool zero = false; // to detect if we hit the edges of the matrix.
			for (size_t i = 0; i < (m.size() - std::max(x, y)); ++i) {
				for (size_t j = 0; j <= i; ++j) {
					if (m[y + j][x + i] == 0 || m[y + i][x + j] == 0) {
						zero = true;
						if (i > max_s) {
							max_s = i;
							max_x = x;
							max_y = y;
						}
						goto next;
					}
				}
			}
		next:
			size_t max_i = m.size() - std::max(x, y);
			if (!zero && max_i > max_s) {
				max_s = max_i;
				max_x = x;
				max_y = y;
			}
		}
	}
	return { static_cast<int>(max_x), static_cast<int>(max_y),
		     static_cast<int>(max_s) };
}

int main() {
	std::cout << "Enter the number of rows for the matrix: ";
	size_t rows;
	std::cin >> rows;
	std::cout << "Enter the matrix row by row:" << std::endl;
	std::vector<std::vector<int>> matrix;
	matrix.reserve(rows);
	for (size_t i = 0; i < rows; ++i) {
		std::vector<int> row;
		row.reserve(rows);
		for (size_t j = 0; j < rows; ++j) {
			int val;
			std::cin >> val;
			row.push_back(val);
		}
		matrix.push_back(row);
	}
	std::vector<int> res = findLargestBlock(matrix);

	std::cout << "The maximum square submatrix is at (" << res[0] << ", "
	          << res[1] << ") with size " << res[2] << std::endl;
	return 0;
}
