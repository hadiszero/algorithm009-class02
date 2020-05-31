// 49. Group Anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	static vector<vector<string>> groupAnagrams(vector<string>& strs) {
		char iaHash[27];
		map<string, vector<string>> mTmpRlt;
		for (string& rStr : strs)
		{
			memset(iaHash, 1, sizeof(iaHash));
			iaHash[26] = '\0';

			for (char& rChar : rStr)
				iaHash[rChar - 'a']++;

			string sKey;
			//for (int iVal : iaHash)
			sKey.append(iaHash);

			auto iItr = mTmpRlt.find(sKey);
			if (iItr == mTmpRlt.end())
			{
				vector<string> saInsert;
				saInsert.push_back(rStr);
				mTmpRlt.insert(make_pair(sKey, saInsert));
			}
			else
			{
				iItr->second.push_back(rStr);
			}
		}


		vector<vector<string>> saaRlt;
		for (auto& iItr : mTmpRlt)
			saaRlt.push_back(iItr.second);

		return saaRlt;
	}
};

int main()
{
	vector<string> saTest;
	saTest.push_back("eat");
	saTest.push_back("tea");
	saTest.push_back("tan");
	saTest.push_back("ate");
	saTest.push_back("nat");
	saTest.push_back("bat");

	auto rlt = Solution::groupAnagrams(saTest);

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
