// 5. Longest Palindromic Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	string centerSpread(string s, int left, int right) {
		int size = s.size(), i = left, j = right;
		while (i >= 0 && j < size)
		{
			if (s[i] == s[j])
			{
				i--;
				j++;
			}
			else break;
		}

		return s.substr(i + 1, j - i - 1);
	}

	string longestPalindrome(string s) {
		int size = s.size();
		if (size < 2) return s;

		int maxLen = 1;
		string res = s.substr(0, 1);

		for (int i = 0; i < size - 1; i++)
		{
			string oddStr = centerSpread(s, i, i);
			string evenStr = centerSpread(s, i, i + 1);
			string maxLenStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;
			if (maxLenStr.length() > maxLen)
			{
				maxLen = maxLenStr.size();
				res = maxLenStr;
			}
		}
		return res;
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
