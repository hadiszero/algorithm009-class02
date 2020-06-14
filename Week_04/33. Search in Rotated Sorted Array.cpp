// 33. Search in Rotated Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;

		int iLeft(0), iRight(nums.size() - 1);
		while (iLeft <= iRight)
		{
			int iMid = iLeft + ((iRight - iLeft) >> 1);
			if (nums[iMid] == target) return iMid;

			if (nums[iMid] >= nums[iLeft])
			{
				if (target >= nums[iLeft] && target < nums[iMid]) iRight = iMid - 1;
				else iLeft = iMid + 1;
			}
			else
			{
				if (target > nums[iMid] && target <= nums[iRight]) iLeft = iMid + 1;
				else iRight = iMid - 1;
			}
		}

		return -1;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);

	Solution sln;
	auto rlt = sln.search(nums, 0);
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
