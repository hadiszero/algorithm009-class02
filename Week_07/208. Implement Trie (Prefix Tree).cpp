// 208. Implement Trie (Prefix Tree).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Trie {
public:
	Trie* m_pNext[26] = {nullptr};
	bool m_bIsString = false;
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* pRoot = this;
		for (char c : word)
		{
			if (!pRoot->m_pNext[c - 'a']) pRoot->m_pNext[c - 'a'] = new Trie();
			pRoot = pRoot->m_pNext[c - 'a'];
		}

		pRoot->m_bIsString = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* pRoot = this;
		for (char c : word)
		{
			if (!pRoot->m_pNext[c - 'a']) return false;
			pRoot = pRoot->m_pNext[c - 'a'];
		}

		return pRoot->m_bIsString ? true : false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* pRoot = this;
		for (char c : prefix)
		{
			if (!pRoot->m_pNext[c - 'a']) return false;
			pRoot = pRoot->m_pNext[c - 'a'];
		}

		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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
