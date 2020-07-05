// 36. Valid Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][9] = {}, col[9][9] = {}, sub[9][9] = {};
		for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] != '.'
				&& (row[i][board[i][j] - '0' - 1]++
					|| col[j][board[i][j] - '0' - 1]++
					|| sub[(i / 3) * 3 + (j / 3)][board[i][j] - '0' - 1]++))
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
