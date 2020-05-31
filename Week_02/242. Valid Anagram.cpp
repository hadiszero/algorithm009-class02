// 242. Valid Anagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	static bool isAnagram(string s, string t) {
		int iSlen(s.length()), iTLen(t.length());
		if (iSlen != iTLen) return false;
		if (iSlen == 0) return true;

		int iaHashMap[26] = {};
		const char* pSPtr = s.c_str();
		while (*pSPtr != '\0')
			iaHashMap[(*pSPtr++) - 'a']++;

		const char* pTPtr = t.c_str();
		while (*pTPtr != '\0')
		{
			if (iaHashMap[*pTPtr++ - 'a']-- <= 0)
				return false;
		}

		return true;
	}
};

int main()
{
	Solution::isAnagram("abc", "cba");
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
