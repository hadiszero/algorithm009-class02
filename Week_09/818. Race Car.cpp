// 818. Race Car.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
	int dp[10001];
	int racecar(int target) {
		if (dp[target] > 0) return dp[target];
		int n = floor(log2(target)) + 1;
		if (target + 1 == (1 << n)) dp[target] = n;
		else
		{
			dp[target] = n + 1 + racecar((1 << n) - 1 - target);
			for (int m = 0; m < n - 1; ++m) dp[target] = min(dp[target], n + m + 1 + racecar(target - (1 << (n - 1)) + (1 << m)));
		}

		return dp[target];
	}
};

int main()
{
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
