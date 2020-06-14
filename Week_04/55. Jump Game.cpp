// 55. Jump Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1) return true;

		size_t curPos = nums.size() - 1;
		for (int i = nums.size() - 1; i > 0; --i)
		{
			int iTestIndex = i - 1;
			if (iTestIndex + nums[iTestIndex] >= curPos) curPos = iTestIndex;	
		}
		
		return curPos == 0 ? true : false;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	Solution sln;
	auto rlt = sln.canJump(nums);

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
