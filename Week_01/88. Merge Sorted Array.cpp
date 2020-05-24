// 88. Merge Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//	if (m == 0)
	//	{
	//		nums1 = nums2;
	//		return;
	//	}
	//	else if (n == 0)
	//	{
	//		return;
	//	}

	//	int iCurWriteIndex = m + n - 1;
	//	int iNum1Index = m - 1;
	//	int iNum2Index = n - 1;

	//	while (iNum1Index >= 0 && iNum2Index >= 0)
	//	{
	//		nums1[iCurWriteIndex--] = nums1[iNum1Index] > nums2[iNum2Index] ? nums1[iNum1Index--] : nums2[iNum2Index--];
	//	}

	//	while (iNum2Index >= 0)
	//	{
	//		nums1[iCurWriteIndex--] = nums2[iNum2Index--];
	//	}
	//}

	static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int last = m + n - 1;
		while (n)
		{
			if (m == 0 || nums1[m - 1] <= nums2[n - 1])
			{
				nums1[last--] = nums2[--n];
			}
			else
			{
				nums1[last--] = nums1[--m];
			}
		}
	}
};

int main()
{
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);

	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(6);

	Solution::merge(nums1, 3, nums2, nums2.size());
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
