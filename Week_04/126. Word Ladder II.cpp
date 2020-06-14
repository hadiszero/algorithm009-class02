// 126. Word Ladder II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	const int INF = 1 << 20;
	unordered_map<string, int> wordId;
	vector<string> idWord;
	vector<vector<int>> edges;

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
	{
		int id = 0;
		for (const string& word : wordList)
		{
			if (!wordId.count(word))
			{
				wordId[word] = id++;
				idWord.push_back(word);
			}
		}

		if (!wordId.count(endWord)) return {};

		if (!wordId.count(beginWord))
		{
			wordId[beginWord] = id++;
			idWord.push_back(beginWord);
		}

		edges.resize(idWord.size());
		for (int i = 0; i < idWord.size(); i++)
		{
			for (int j = i + 1; j < idWord.size(); j++)
			{
				if (transformCheck(idWord[i], idWord[j]))
				{
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}

		const int dest = wordId[endWord];
		vector<vector<string>> res;
		queue<vector<int>> q;
		vector<int> cost(id, INF);
		q.push(vector<int>{wordId[beginWord]});
		cost[wordId[beginWord]] = 0;
		while (!q.empty())
		{
			vector<int> now = q.front(); q.pop();
			int last = now.back();
			if (last == dest)
			{
				vector<string> tmp;
				for (int index : now) tmp.push_back(idWord[index]);
				res.push_back(tmp);
			}
			else
			{
				for (int i = 0; i < edges[last].size(); i++)
				{
					int to = edges[last][i];
					if (cost[last] + 1 <= cost[to])
					{
						cost[to] = cost[last] + 1;
						vector<int> tmp(now);
						tmp.push_back(to);
						q.push(tmp);
					}
				}
			}
		}

		return res;
	}

	bool transformCheck(const string& str1, const string& str2)
	{
		int differences = 0;
		for (int i = 0; i < str1.size() && differences < 2; i++)
		{
			if (str1[i] != str2[i])
				++differences;
		}
		return differences == 1;
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
	auto rlt = sln.findLadders("hit", "cog", wordList);

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
