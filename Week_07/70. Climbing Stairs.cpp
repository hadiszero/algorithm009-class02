// 70. Climbing Stairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		if (n < 3) return n;

		int iRlt(0), iPrev(1), iPrev2(2);
		for (int i = 3; i <= n; ++i)
		{
			iRlt = iPrev + iPrev2;
			iPrev = iPrev2;
			iPrev2 = iRlt;
		}

		return iRlt;
	}
};

int main()
{
	Solution sln;
	auto a = sln.climbStairs(3);
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
