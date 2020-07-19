// 115. Distinct Subsequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		auto dp = vector<vector<long>>(t.length() + 1, vector<long>(s.length() + 1, 0));
		for (long j = 0; j < s.length() + 1; j++) dp[0][j] = 1;
		for (long i = 1; i < t.length() + 1; i++)
		{
			for (long j = 1; j < s.length() + 1; j++)
			{
				if (t[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				else dp[i][j] = dp[i][j - 1];
			}
		}

		return dp[t.length()][s.length()];
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
