// 46. Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> rlt;
	//vector<vector<int>> permute(vector<int>& nums) {
	//	vector<int> subRlt;
	//	permuteHelper(nums, subRlt);
	//	return rlt;
	//}

	//void permuteHelper(vector<int>& rNums, vector<int>& rSub)
	//{
	//	if (rNums.empty()) {
	//		rlt.push_back(rSub);
	//		return;
	//	}

	//	for (int i = 0; i < rNums.size(); ++i) {
	//		int iValTmp = rNums[0];
	//		rSub.push_back(iValTmp);
	//		rNums.erase(rNums.begin());
	//		permuteHelper(rNums, rSub);

	//		rNums.push_back(iValTmp);
	//		rSub.pop_back();
	//	}
	//}


	vector<vector<int>> permute(vector<int>& nums) {
		permuteHelper(nums, 0, nums.size() - 1);
		return rlt;
	}

	void permuteHelper(vector<int>& rNums, int iBegin, int iEnd)
	{
		if (iBegin == iEnd) {
			rlt.push_back(rNums);
			return;
		}

		for (int i = iBegin; i < rNums.size(); ++i) {
			swap(rNums[iBegin], rNums[i]);
			permuteHelper(rNums, iBegin + 1, iEnd);
			swap(rNums[iBegin], rNums[i]);
		}
	}
};

int main()
{
	Solution oSln;

	vector<int> iaTest;
	iaTest.push_back(1);
	iaTest.push_back(2);
	iaTest.push_back(3);
	auto rlt = oSln.permute(iaTest);

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
