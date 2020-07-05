// 37. Sudoku Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		rows = vector<bitset<9>>(9, bitset<9>());
		cols = vector<bitset<9>>(9, bitset<9>());
		cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

		int cnt = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				cnt += (board[i][j] == '.');
				if (board[i][j] == '.') continue;
				int n = board[i][j] - '1';
				rows[i] |= (1 << n);
				cols[j] |= (1 << n);
				cells[i / 3][j / 3] |= (1 << n);
			}
		}
		dfs(board, cnt);
	}

	bool dfs(vector<vector<char>>& board, int cnt)
	{
		if (cnt == 0) return true;

		auto next = getNext(board);

		auto bits = getPossibleStatus(next[0], next[1]);
		if (bits.count() == 0) return false;

		for (int n = 0; n < bits.size(); n++)
		{
			if (!bits.test(n)) continue;
			fillNum(next[0], next[1], n, true);
			board[next[0]][next[1]] = n + '1';

			if (dfs(board, cnt - 1)) return true;
			fillNum(next[0], next[1], n, false);
			board[next[0]][next[1]] = '.';
		}
		return false;
	}

	vector<int> getNext(vector<vector<char>>& board)
	{
		vector<int> ret;
		int minCnt = 10;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] != '.') continue;
				auto cur = getPossibleStatus(i, j);
				if (cur.count() >= minCnt) continue;
				ret = { i, j };
				minCnt = cur.count();
			}
		}
		return ret;
	}

	bitset<9> getPossibleStatus(int x, int y)
	{
		return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
	}

	void fillNum(int x, int y, int n, bool fillFlag)
	{
		rows[x][n] = (fillFlag) ? (1) : (0);
		cols[y][n] = (fillFlag) ? (1) : (0);
		cells[x / 3][y / 3][n] = (fillFlag) ? (1) : (0);
	}
private:
	vector<bitset<9>> rows;
	vector<bitset<9>> cols;
	vector<vector<bitset<9>>> cells;
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
