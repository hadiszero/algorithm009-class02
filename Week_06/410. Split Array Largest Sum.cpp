// 410. Split Array Largest Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		long l = nums[0], h = 0;
		for (auto i : nums)
		{
			h += i;
			l = l > i ? l : i;
		}

		while (l < h)
		{
			long mid = (l + h) / 2;
			long temp = 0;
			int cnt = 1;
			for (auto i : nums)
			{
				temp += i;
				if (temp > mid)
				{
					temp = i;
					++cnt;
				}
			}

			if (cnt > m) l = mid + 1;
			else h = mid;
		}

		return l;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(8);

	Solution sln;
	auto rlt = sln.splitArray(nums, 2);

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
