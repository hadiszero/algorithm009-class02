// 72. Edit Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n(word1.length()), m(word2.length());
		if (n * m == 0) return n + m;

		auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i < n + 1; i++) dp[i][0] = i;
		for (int j = 0; j < m + 1; j++) dp[0][j] = j;

		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				int left = dp[i - 1][j] + 1;
				int down = dp[i][j - 1] + 1;
				int left_down = dp[i - 1][j - 1];
				if (word1[i - 1] != word2[j - 1]) left_down += 1;
				dp[i][j] = min(left, min(down, left_down));
			}
		}

		return dp[n][m];
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.minDistance("horse", "ros");
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
