// 32. Longest Valid Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int rlt = 0;
		vector<int> dp(s.size() + 1);
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == ')' && s[i - 1] == '(')
			{
				dp[i + 1] = dp[i - 1] + 2;
				rlt = max(rlt, dp[i + 1]);
			}
			else if (s[i] == ')' && s[i - 1] == ')' && dp[i] != 0)
			{
				int t = i - dp[i] - 1;
				if (t >= 0 && s[t] == '(') dp[i + 1] = dp[t] + dp[i] + 2;
				rlt = max(rlt, dp[i + 1]);
			}
		}

		return rlt;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.longestValidParentheses("()()((()()()()");
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
