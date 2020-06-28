// 647. Palindromic Substrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		auto dp = vector<vector<bool>>(s.length(), vector<bool>(s.length(), false));
		const char* pStr = s.c_str();

		int ans = 0;
		for (int j = 0; j < s.length(); ++j)
		{
			for (int i = 0; i <= j; ++i)
			{
				if (pStr[i] == pStr[j] && (j - i < 2 || dp[i + 1][j - 1]))
				{
					dp[i][j] = true;
					ans++;
				}
			}
		}

		return ans;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.countSubstrings("abc");
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
