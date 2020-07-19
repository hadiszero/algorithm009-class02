// 205. Isomorphic Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;

		int hashTableS[256] = {};
		int hashTableT[256] = {};

		for (int i = 0; i < s.length(); ++i)
		{
			if (hashTableS[s[i]] == 0 && hashTableT[t[i]] == 0)
			{
				hashTableS[s[i]] = i + 1;
				hashTableT[t[i]] = i + 1;
			}
			else
				if (hashTableS[s[i]] != hashTableT[t[i]]) return false;
		}

		return true;
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
