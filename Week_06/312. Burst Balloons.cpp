// 312. Burst Balloons.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();

		vector<int> p(n + 2, 1);
		for (int i = 1; i <= n; i++) p[i] = nums[i - 1];

		vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
		for (int i = n + 1; i >= 0; i--) {
			for (int j = i; j <= n + 1; j++) {
				if (j - i < 2) f[i][j] = 0;
				for (int k = i + 1; k <= j - 1; k++) {
					f[i][j] = max(f[i][j], f[i][k] + f[k][j] + p[i] * p[k] * p[j]);
				}
			}
		}

		return f[0][n + 1];
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(8);

	Solution sln;
	auto rlt = sln.maxCoins(nums);
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
