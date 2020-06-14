// 127. Word Ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.find(endWord) == dict.end()) return 0;

		unordered_set<string> beginSet, endSet, tmp, visited;
		beginSet.insert(beginWord);
		endSet.insert(endWord);
		int len = 1;

		while (!beginSet.empty() && !endSet.empty())
		{
			if (beginSet.size() > endSet.size()) swap(beginSet, endSet);

			unordered_set<string> tmp;
			for (string word : beginSet)
			{
				for (int i = 0; i < word.size(); i++)
				{
					char old = word[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (old == c) continue;
						word[i] = c;
						if (endSet.find(word) != endSet.end()) return len + 1;
						if (visited.find(word) == visited.end() && dict.find(word) != dict.end())
						{
							tmp.insert(word);
							visited.insert(word);
						}
					}

					word[i] = old;
				}
			}

			beginSet = tmp;
			len++;
		}

		return 0;

	}
};

int main()
{
	vector<string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");

	Solution sln;
	auto rlt = sln.ladderLength("hit", "cog", wordList);

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
