// 529. Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<char>> rlt;
	vector<vector<bool>> visited;
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		rlt = move(board);

		vector<bool> line(rlt[0].size(), false);
		visited = vector<vector<bool>>(rlt.size(), line);

		size_t stClickCnt = click.size() / 2;
		for (size_t i = 0; i < stClickCnt; i += 2)
		{
			updateBoardHelper(click[2 * i], click[2 * i + 1], false);
		}

		return move(rlt);
	}

	char calcNumberOfMineAround(int iRow, int iCol)
	{
		int iRlt(0);
		for (int i = iRow - 1; i <= iRow + 1; ++i)
		{
			for (int j = iCol - 1; j <= iCol + 1; ++j)
			{
				if (i >= rlt.size() || j >= rlt[0].size()) continue;
				iRlt += (rlt[i][j] == 'M' ? 1 : 0);
			}
		}

		return iRlt == 0 ? 'B' : iRlt + '0';
	}

	void updateBoardHelper(int iRow, int iCol, bool bDetect = true)
	{
		if (iRow >= rlt.size() || iCol >= rlt[0].size()) return;
		if (visited[iRow][iCol]) return;

		visited[iRow][iCol] = true;

		char& rCur = rlt[iRow][iCol];
		if (rCur == 'M' && !bDetect)
		{
			rCur = 'X';
			return;
		}
		else if (rCur == 'E')
		{
			rCur = calcNumberOfMineAround(iRow, iCol);
			if (rCur == 'B')
			{
				updateBoardHelper(iRow - 1, iCol - 1);
				updateBoardHelper(iRow - 1, iCol);
				updateBoardHelper(iRow - 1, iCol + 1);
				updateBoardHelper(iRow, iCol - 1);
				updateBoardHelper(iRow, iCol + 1);
				updateBoardHelper(iRow + 1, iCol - 1);
				updateBoardHelper(iRow + 1, iCol);
				updateBoardHelper(iRow + 1, iCol + 1);
			}
		}
	}
};

int main()
{
	vector<vector<char>> board;
	vector<char> line0;
	line0.push_back('E');
	line0.push_back('E');
	line0.push_back('E');
	line0.push_back('E');
	line0.push_back('E');

	vector<char> line1;
	line1.push_back('E');
	line1.push_back('E');
	line1.push_back('M');
	line1.push_back('E');
	line1.push_back('E');

	vector<char> line2;
	line2.push_back('E');
	line2.push_back('E');
	line2.push_back('E');
	line2.push_back('E');
	line2.push_back('E');

	vector<char> line3;
	line3.push_back('E');
	line3.push_back('E');
	line3.push_back('E');
	line3.push_back('E');
	line3.push_back('E');

	board.push_back(line0);
	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);

	vector<int> click;
	click.push_back(3);
	click.push_back(0);

	Solution sln;
	auto rlt = sln.updateBoard(board, click);

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
