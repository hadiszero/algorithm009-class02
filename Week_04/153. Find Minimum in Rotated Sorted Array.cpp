// 153. Find Minimum in Rotated Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int iLeft(0), iRight(nums.size() - 1);
		while (iLeft <= iRight)
		{
			if (nums[iLeft] <= nums[iRight]) return nums[iLeft];
		
			int iMid = iLeft + ((iRight - iLeft) >> 1);
			if (nums[iLeft] <= nums[iMid]) iLeft = iMid + 1;
			else iRight = iMid;
		}

		return -1;
	}
};

int main()
{
	vector<int> nums;
	//nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	//nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	//nums.push_back(2);

	Solution sln;
	auto rlt = sln.findMin(nums);

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
