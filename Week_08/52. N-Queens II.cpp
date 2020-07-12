// 52. N-Queens II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	int rlt = 0;
	int totalNQueens(int n) {
		if (n < 1) return rlt;

		dfs(n, 0, 0, 0, 0);
		return rlt;
	}

	void dfs(int n, int row, int col, int ld, int rd)
	{
		if (row >= n)
		{
			++rlt;
			return;
		}

		int bits = (~(col | ld | rd)) & ((1 << n) - 1);
		while (bits > 0)
		{
			int p = bits & -bits;
			bits = bits & (bits - 1);
			dfs(n, row + 1, col | p, (ld | p) << 1, (rd | p) >> 1);
		}
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
