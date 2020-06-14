// 122. Best Time to Buy and Sell Stock II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;

		int iMaxProfit = 0;

		for (size_t i = 0; i < prices.size() - 1; ++i)
		{
			if (prices[i] < prices[i + 1])
			{
				iMaxProfit += (prices[i + 1] - prices[i]);
				++i;
			}
		}

		return iMaxProfit;
	}
};

int main()
{
	//[7, 1, 5, 3, 6, 4]
	vector<int> iaTest;
	iaTest.push_back(7);
	iaTest.push_back(1);
	iaTest.push_back(5);
	iaTest.push_back(3);
	iaTest.push_back(6);
	iaTest.push_back(4);

	Solution sln;
	auto rlt = sln.maxProfit(iaTest);

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
