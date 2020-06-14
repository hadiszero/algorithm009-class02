// 860. Lemonade Change.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		if (bills.size() == 0) return true;

		int i5(0), i10(0);
		for (int val : bills)
		{
			if (val == 5) ++i5;
			else if (val == 10) { --i5; ++i10; }
			else if (val == 20)
			{
				if (i10 > 0) { --i10; --i5; }
				else i5-= 3;
			}

			if (i5 < 0 || i10 < 0) return false;
		}

		return true;
	}
};

int main()
{
	vector<int> iaTest;
	iaTest.push_back(5);
	iaTest.push_back(5);
	iaTest.push_back(5);
	iaTest.push_back(10);
	iaTest.push_back(20);

	//iaTest.push_back(10);
	//iaTest.push_back(10);

	Solution sln;
	auto a = sln.lemonadeChange(iaTest);

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
