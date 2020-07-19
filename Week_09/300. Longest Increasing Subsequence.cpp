// 300. Longest Increasing Subsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLISDP(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		vector<int> DP(nums.size(), 1);
		int iRlt = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
				if (nums[j] < nums[i]) DP[i] = max(DP[i], DP[j] + 1);

			iRlt = max(iRlt, DP[i]);
		}

		return iRlt;
	}

	int lengthOfLISBS(vector<int>& nums) {
		vector<int> rlt;
		for (int val : nums)
		{
			auto itr = rlt.size() == 0 ? rlt.end() : lower_bound(rlt.begin(), rlt.end(), val);
			if (itr == rlt.end()) rlt.push_back(val);
			else *itr = val;
		}

		return rlt.size();
	}
};

int main()
{
	//[10, 9, 2, 5, 3, 7, 101, 18]
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(101);
	nums.push_back(18);

	Solution sln;
	auto rlt = sln.lengthOfLISDP(nums);
	rlt = sln.lengthOfLISBS(nums);

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
