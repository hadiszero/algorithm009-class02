// 91. Decode Ways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') return 0;
		int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
		for (int i = 1; i < s.size(); i++) {
			int tmp = curr;
			if (s[i] == '0')
				if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
				else return 0;
			else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
				curr = curr + pre;
			pre = tmp;
		}
		return curr;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.numDecodings("226");

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
