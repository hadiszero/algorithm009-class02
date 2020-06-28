// 403. Frog Jump.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canCross(vector<int>& stones) {
		int n = stones.size();
		vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int diff = stones[i] - stones[j];
				if (diff > i) continue;
				if (dp[j][diff] || dp[j][diff - 1] || diff < n - 1 && dp[j][diff + 1]) dp[i][diff] = true;
			}
		}

		for (int i = 1; i <= n; ++i)
			if (dp[n - 1][i]) return true;

		return false;
	}
};

int main()
{
	vector<int> stones;
	stones.push_back(0);
	stones.push_back(1);
	stones.push_back(3);
	stones.push_back(5);
	stones.push_back(6);
	stones.push_back(8);
	stones.push_back(12);
	stones.push_back(17);

	Solution sln;
	auto rlt = sln.canCross(stones);
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
