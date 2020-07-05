// 130. Surrounded Regions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int iR = 0;
	int iC = 0;

	void solve(vector<vector<char>>& board) {
		iR = board.size();
		if (iR == 0) return;
		iC = board[0].size();
		if (iC == 0) return;

		for (int i = 0; i < iR; ++i)
			for (int j = 0; j < iC; ++j)
				if ((i == 0 || j == 0 || i == iR - 1 || j == iC - 1) && board[i][j] == 'O') dfs(board, i, j);

		for (int i = 0; i < iR; ++i)
			for (int j = 0; j < iC; ++j)
				if (board[i][j] == '#') board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
	}

	void dfs(vector<vector<char>>& board, int i, int j)
	{
		if (i < 0 || j < 0 || i >= iR || j >= iC || board[i][j] == 'X' || board[i][j] == '#') return;

		board[i][j] = '#';
		dfs(board, i - 1, j);
		dfs(board, i + 1, j);
		dfs(board, i, j + 1);
		dfs(board, i, j - 1);
	}
};

int main()
{
	vector<vector<char>> board;
	vector<char> line1;
	line1.push_back('X');
	line1.push_back('X');
	line1.push_back('X');
	line1.push_back('X');

	vector<char> line2;
	line2.push_back('X');
	line2.push_back('O');
	line2.push_back('O');
	line2.push_back('X');

	vector<char> line3;
	line3.push_back('X');
	line3.push_back('X');
	line3.push_back('O');
	line3.push_back('X');

	vector<char> line4;
	line4.push_back('X');
	line4.push_back('O');
	line4.push_back('X');
	line4.push_back('X');

	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);
	board.push_back(line4);

	Solution sln;
	sln.solve(board);

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
