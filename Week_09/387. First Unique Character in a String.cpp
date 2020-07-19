// 387. First Unique Character in a String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int nums[26] = {};
		for (char c : s) ++nums[c - 'a'];

		const char* pBuf = s.c_str();
		for (int i = 0; i < s.length(); ++i)
			if (nums[pBuf[i] - 'a'] == 1) return i;

		return -1;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.firstUniqChar("leetcode");
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
