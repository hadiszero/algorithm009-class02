// 189. Rotate Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//static void rotate(vector<int>& nums, int k) {
	//	if (nums.size() <= 1)
	//		return;

	//	k = k % nums.size();

	//	reverseVector(nums, 0, nums.size() - 1);
	//	reverseVector(nums, 0, k - 1);
	//	reverseVector(nums, k, nums.size() - 1);
	//}

	//static void reverseVector(vector<int>& nums, int iBeginIndex, int iEndIndex)
	//{
	//	for (; iBeginIndex < iEndIndex; ++iBeginIndex, --iEndIndex)
	//	{
	//		swap(nums[iBeginIndex], nums[iEndIndex]);
	//	}
	//}

	static void rotate(vector<int>& nums, int k) {
		int iNumSize = nums.size();
		if (iNumSize <= 1)
			return;

		k = k % iNumSize;

		int iMovedCnt = 0;
		int iBeginMoveIndex = 0;
		int iCurMoveIndex = 0;
		int iPrevBk = nums[iBeginMoveIndex];
		while (true)
		{
			int iTarIndex = (iCurMoveIndex + k) % iNumSize;
			int iTmp = nums[iTarIndex];
			nums[iTarIndex] = iPrevBk;
			iPrevBk = iTmp;

			if (++iMovedCnt == iNumSize)
				return;

			iCurMoveIndex = iTarIndex;
			if (iBeginMoveIndex == iCurMoveIndex)
			{
				iCurMoveIndex = ++iBeginMoveIndex;
				iPrevBk = nums[iBeginMoveIndex];
			}
		}
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	//nums.push_back(8);
	//nums.push_back(9);
	//nums.push_back(10);

	//nums.push_back(-1);

	Solution::rotate(nums, 2);

	
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
