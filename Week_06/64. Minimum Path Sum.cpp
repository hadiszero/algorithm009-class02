// 64. Minimum Path Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int iH(grid.size()), iW(grid[0].size());

		vector<vector<int>> dp(vector<vector<int>>(iH, vector<int>(iW, 0)));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < iW; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
		for (int i = 1; i < iH; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
		for (int i = 1; i < iH; ++i)
		{
			for (int j = 1; j < iW; ++j)
				dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
		}

		return dp[iH - 1][iW - 1];
	}
};

int main()
{
	vector<vector<int>> grid;
	vector<int> line1;
	line1.push_back(1);
	line1.push_back(3);
	line1.push_back(1);

	vector<int> line2;
	line2.push_back(1);
	line2.push_back(5);
	line2.push_back(1);

	vector<int> line3;
	line3.push_back(4);
	line3.push_back(2);
	line3.push_back(1);

	grid.push_back(line1);
	grid.push_back(line2);
	grid.push_back(line3);

	Solution sln;
	auto rlt = sln.minPathSum(grid);

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
