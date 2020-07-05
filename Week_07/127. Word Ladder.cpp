// 127. Word Ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	//int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	//	unordered_set<string> dict(wordList.begin(), wordList.end());
	//	if (dict.find(endWord) == dict.end()) return 0;

	//	unordered_set<string> beginSet, endSet, tmp, visited;
	//	beginSet.insert(beginWord);
	//	endSet.insert(endWord);
	//	int len = 1;

	//	while (!beginSet.empty() && !endSet.empty())
	//	{
	//		if (beginSet.size() > endSet.size()) swap(beginSet, endSet);

	//		unordered_set<string> tmp;
	//		for (string word : beginSet)
	//		{
	//			for (int i = 0; i < word.size(); i++)
	//			{
	//				char old = word[i];
	//				for (char c = 'a'; c <= 'z'; c++)
	//				{
	//					if (old == c) continue;
	//					word[i] = c;
	//					if (endSet.find(word) != endSet.end()) return len + 1;
	//					if (visited.find(word) == visited.end() && dict.find(word) != dict.end())
	//					{
	//						tmp.insert(word);
	//						visited.insert(word);
	//					}
	//				}

	//				word[i] = old;
	//			}
	//		}

	//		beginSet = tmp;
	//		len++;
	//	}

	//	return 0;
	//}









	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordHash(wordList.begin(), wordList.end());
		if (wordHash.find(endWord) == wordHash.end()) return 0;
		
		queue<string> bfsQueue;
		bfsQueue.push(beginWord);

		set<string> visited;
		visited.insert(beginWord);

		int iWordLen(static_cast<int>(beginWord.length())), iStep(1);
		while (!bfsQueue.empty())
		{
			int queueLen = static_cast<int>(bfsQueue.size());
			for (int queueIndex = 0; queueIndex < queueLen; ++queueIndex)
			{
				string testWord = bfsQueue.front(); bfsQueue.pop();
				char* pTestWord = const_cast<char*>(testWord.c_str());
				string sOriginWord = pTestWord;
				for (int wordIndex = 0; wordIndex < iWordLen; ++wordIndex)
				{
					char cOriginChar = pTestWord[wordIndex];
					for (char atoz = 'a'; atoz <= 'z'; ++atoz)
					{
						if (atoz == cOriginChar) continue;
						pTestWord[wordIndex] = atoz;
						if (testWord == endWord) return ++iStep;
						if (wordHash.find(testWord) == wordHash.end()) continue;
						if (visited.find(testWord) == visited.end())
						{
							bfsQueue.push(testWord);
							visited.insert(testWord);
						}
					}
					testWord = sOriginWord;
				}
			}
			++iStep;
		}

		return 0;
	}

	int ladderLengthBiBFS(string beginWord, string endWord, vector<string>& wordList)
	{
		unordered_set<string> wordHash(wordList.begin(), wordList.end());
		if (wordHash.find(endWord) == wordHash.end()) return 0;

		set<string> beginQueue;			//	We need to find something in the queue, so we use set instead of queue
		beginQueue.insert(beginWord);

		set<string> endQueue;
		endQueue.insert(endWord);

		unordered_set<string> visited;
		visited.insert(beginWord);
		visited.insert(endWord);

		int iWordLen = static_cast<int>(beginWord.size());
		int iStep = 1;

		while (!beginQueue.empty() && !endQueue.empty())
		{
			if (beginQueue.size() > endQueue.size()) swap(beginQueue, endQueue);

			set<string> nextLevelQueue;
			for (auto& rQueueWord : beginQueue)
			{
				//	for better performance, we'll manipulate buffer directly, you could use the copy of char buffer
				char* pQueueWordBuf = const_cast<char*>(rQueueWord.c_str());
				for (int iEnumingCharIndex = 0; iEnumingCharIndex < iWordLen; ++iEnumingCharIndex)
				{
					char cCharBK = pQueueWordBuf[iEnumingCharIndex];
					for (char atoz = 'a'; atoz <= 'z'; ++atoz)
					{
						if (atoz == cCharBK) continue;
						pQueueWordBuf[iEnumingCharIndex] = atoz;
						if(wordHash.find(rQueueWord) == wordHash.end()) continue;
						if (endQueue.find(rQueueWord) != endQueue.end()) return iStep + 1;
						if (visited.find(rQueueWord) != visited.end()) continue;
					
						visited.insert(rQueueWord);
						nextLevelQueue.insert(rQueueWord);
					}

					pQueueWordBuf[iEnumingCharIndex] = cCharBK;
				}
			}

			beginQueue = nextLevelQueue;
			++iStep;
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

	//wordList.push_back("hot");
	//wordList.push_back("dot");
	//wordList.push_back("tog");
	//wordList.push_back("cog");

	Solution sln;
	auto rlt = sln.ladderLength("hit", "cog", wordList);
	rlt = sln.ladderLengthBiBFS("hit", "cog", wordList);

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
