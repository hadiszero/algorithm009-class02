// 1. Two Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	//static vector<int> twoSum(vector<int>& nums, int target) {
	//	map<int, set<int>> mHash;	//	key, value; val, set of index has same value
	//	for (size_t i = 0; i < nums.size(); ++i)
	//	{
	//		auto pos = mHash.find(nums[i]);
	//		if (pos != mHash.end())
	//		{
	//			pos->second.insert(i);
	//		}
	//		else
	//		{
	//			set<int> indexSet;
	//			indexSet.insert(i);
	//			mHash.insert(make_pair(nums[i], indexSet));
	//		}
	//	}

	//	vector<int> rlt;
	//	for (size_t i = 0; i < nums.size(); ++i)
	//	{
	//		int iValToFind = target - nums[i];
	//		auto pos = mHash.find(iValToFind);
	//		if (pos != mHash.end())
	//		{
	//			if (iValToFind == nums[i])
	//			{
	//				if (pos->second.size() >= 2)
	//				{
	//					rlt.push_back(*(pos->second.begin()));
	//					rlt.push_back(*(++(pos->second.begin())));
	//				}
	//				else
	//				{
	//					continue;
	//				}
	//			}
	//			else
	//			{
	//				rlt.push_back(i);
	//				rlt.push_back(*(pos->second.begin()));
	//			}

	//			return rlt;
	//		}
	//	}

	//	return rlt;
	//}

	static vector<int> twoSum(vector<int>& nums, int target) {
		//	according to the context, we can always find a result, 
		//	don't need to make edge condition check here

		map<int, int> mHash;
		vector<int> rlt;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			auto pos = mHash.find(target - nums[i]);
			if (pos == mHash.end())
			{
				mHash.insert(make_pair(nums[i], i));
			}
			else
			{
				rlt.push_back(i);
				rlt.push_back(pos->second);
				return rlt;
			}
		}

		return rlt;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	auto rlt = Solution::twoSum(nums, 6);

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
