// 438. Find All Anagrams in a String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

//	6.49, 100

using namespace std;

class Solution {
public:
	map<char, int> pHashMap, sHashMap;
	inline bool CheckAnagram()
	{
		auto itr = pHashMap.begin();
		while (itr != pHashMap.end())
		{
			if (sHashMap[itr->first] != itr->second) return false;

			++itr;
		}

		return true;
	}

	vector<int> findAnagrams(string s, string p) {
		vector<int> rlt;
		
		for (char c : p) ++pHashMap[c];

		int iWinSize = p.length();
		int iBeginIndex = 0, iEndIndex = 0;
		for (; iEndIndex < s.length();)
		{
			if (iEndIndex - iBeginIndex < iWinSize)
			{
				++sHashMap[s[iEndIndex++]];
				continue;
			}

			if (CheckAnagram()) rlt.push_back(iBeginIndex);

			--sHashMap[s[iBeginIndex++]];
			++sHashMap[s[iEndIndex++]];
		}

		if (CheckAnagram()) rlt.push_back(iBeginIndex);

		return rlt;
	}
};


int main()
{
	Solution sln;

	auto rlt = sln.findAnagrams("abab", "ab");
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
