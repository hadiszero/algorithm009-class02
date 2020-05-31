// 347. Top K Frequent Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct CompareByVal {
	bool operator()(const pair<int, int>& rL, const pair<int, int>& rR) {
		return rL.second < rR.second;
	}
};

class Solution {
public:

	static vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mHash;
		for (int val : nums)
			++mHash[val];
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, CompareByVal> iPQ;
		for (auto& p : mHash)
		{
			iPQ.push(p);
		}

		vector<int> iaRlt;
		for (int i = 0; i < k; ++i)
		{
			iaRlt.push_back(iPQ.top().first);
			iPQ.pop();
		}

		return iaRlt;
	}
};

int main()
{
	vector<int> iaTest;
	iaTest.push_back(1);
	iaTest.push_back(2);
	iaTest.push_back(3);
	iaTest.push_back(1);
	iaTest.push_back(3);
	iaTest.push_back(1);

	auto rlt = Solution::topKFrequent(iaTest, 2);

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
