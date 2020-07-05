// 212. Word Search II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
	string word = "";
	vector<TrieNode*> nodes;
	TrieNode() :nodes(26, 0) {}
};

class Solution {
	int rows, cols;
	vector<string> res;

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		rows = board.size();
		cols = rows ? board[0].size() : 0;
		if (rows == 0 || cols == 0) return res;

		TrieNode* root = new TrieNode();
		for (string word : words) {
			TrieNode *cur = root;
			for (int i = 0; i < word.size(); ++i) {
				int idx = word[i] - 'a';
				if (cur->nodes[idx] == 0) cur->nodes[idx] = new TrieNode();
				cur = cur->nodes[idx];
			}
			cur->word = word;
		}

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				dfs(board, root, i, j);
			}
		}
		return res;
	}

	void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
		char c = board[x][y];
		if (c == '.' || root->nodes[c - 'a'] == 0) return;
		root = root->nodes[c - 'a'];
		if (root->word != "") {
			res.push_back(root->word);
			root->word = "";
		}

		board[x][y] = '.';
		if (x > 0) dfs(board, root, x - 1, y);
		if (y > 0) dfs(board, root, x, y - 1);
		if (x + 1 < rows) dfs(board, root, x + 1, y);
		if (y + 1 < cols) dfs(board, root, x, y + 1);
		board[x][y] = c;
	}
};

int main()
{
	vector<vector<char>> board;
	vector<char> line1;
	line1.push_back('o');
	line1.push_back('a');
	line1.push_back('a');
	line1.push_back('n');

	vector<char> line2;
	line2.push_back('e');
	line2.push_back('t');
	line2.push_back('a');
	line2.push_back('e');

	vector<char> line3;
	line3.push_back('i');
	line3.push_back('h');
	line3.push_back('k');
	line3.push_back('r');

	vector<char> line4;
	line4.push_back('i');
	line4.push_back('f');
	line4.push_back('l');
	line4.push_back('v');

	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);
	board.push_back(line4);

	vector<string> words;
	words.push_back("oath");
	words.push_back("pea");
	words.push_back("eat");
	words.push_back("rain");

	Solution sln;
	auto rlt = sln.findWords(board, words);

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
