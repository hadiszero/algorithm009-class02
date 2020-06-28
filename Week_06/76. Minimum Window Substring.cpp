// 76. Minimum Window Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> count;
		for (auto c : t) count[c] ++;
		int len = 0, n = s.size();
		int minlen = n;
		string ans = "";
		int l = 0, r = 0;
		for (; r < n; r++)
		{
			count[s[r]]--;
			if (count[s[r]] >= 0) len++;
			while (len == t.size())
			{
				if (r - l + 1 <= minlen)
				{
					minlen = r - l + 1;
					ans = s.substr(l, r - l + 1);
				}

				count[s[l]]++;
				if (count[s[l]] > 0) len--;
				l++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.minWindow("ADOBECODEBANC", "ABC");
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
