// 221. Maximal Square.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

		int iMaxLen = 0;
		int iH(matrix.size()), iW(matrix[0].size());
		auto dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < iH; ++i)
		{
			for (int j = 0; j < iW; ++j)
			{
				if (matrix[i][j] == '1')
				{
					if (i == 0 || j == 0) dp[i][j] = 1;
					else dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;

					iMaxLen = max(iMaxLen, dp[i][j]);
				}
			}
		}

		return iMaxLen * iMaxLen;
	}
};

int main()
{
	vector<vector<char>> matrix;
	vector<char> line1;
	line1.push_back('1');
	line1.push_back('0');
	line1.push_back('1');
	line1.push_back('0');
	line1.push_back('0');

	vector<char> line2;
	line2.push_back('1');
	line2.push_back('0');
	line2.push_back('1');
	line2.push_back('1');
	line2.push_back('1');

	vector<char> line3;
	line3.push_back('1');
	line3.push_back('1');
	line3.push_back('1');
	line3.push_back('1');
	line3.push_back('1');

	vector<char> line4;
	line4.push_back('1');
	line4.push_back('0');
	line4.push_back('0');
	line4.push_back('1');
	line4.push_back('0');

	matrix.push_back(line1);
	matrix.push_back(line2);
	matrix.push_back(line3);
	matrix.push_back(line4);

	Solution sln;
	auto rlt = sln.maximalSquare(matrix);

    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   '1'. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
