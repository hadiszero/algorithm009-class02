// 264. Ugly Number II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int nthUglyNumber(int n) {
		vector<int> iaDP(n);
		iaDP[0] = 1;
		int iF2(0), iF3(0), iF5(0);
		for (int i = 1; i < n; ++i)
		{
			iaDP[i] = min(min(2 * iaDP[iF2], 3 * iaDP[iF3]), 5 * iaDP[iF5]);
			if (iaDP[i] == 2 * iaDP[iF2]) ++iF2;
			if (iaDP[i] == 3 * iaDP[iF3]) ++iF3;
			if (iaDP[i] == 5 * iaDP[iF5]) ++iF5;
		}
		return iaDP[n - 1];
	}
};

int main()
{
	auto rlt = Solution::nthUglyNumber(10);
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
