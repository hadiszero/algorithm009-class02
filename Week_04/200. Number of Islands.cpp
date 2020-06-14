// 200. Number of Islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int iRlt(0);
		for (size_t i = 0; i < grid.size(); ++i)
		{
			for (size_t j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					DestroyIsland(grid, i, j);
					++iRlt;
				}
			}
		}

		return iRlt;
	}

	void DestroyIsland(vector<vector<char>>& grid, int iRow, int iCol)
	{
		if (iRow < 0 || iCol < 0 || iRow >= grid.size() || iCol >= grid[0].size()) return;
		if (grid[iRow][iCol] == '1')
		{
			grid[iRow][iCol] = '0';
			DestroyIsland(grid, iRow, iCol + 1);
			DestroyIsland(grid, iRow, iCol - 1);
			DestroyIsland(grid, iRow - 1, iCol);
			DestroyIsland(grid, iRow + 1, iCol);
		}
	}
};

int main()
{
	//11110
	//11010
	//11000
	//00000

	vector<vector<char>> grid;

	vector<char> line1;
	line1.push_back('1');
	line1.push_back('1');
	line1.push_back('1');
	line1.push_back('1');
	line1.push_back('0');

	vector<char> line2;
	line2.push_back('1');
	line2.push_back('1');
	line2.push_back('0');
	line2.push_back('1');
	line2.push_back('0');

	vector<char> line3;
	line3.push_back('1');
	line3.push_back('1');
	line3.push_back('0');
	line3.push_back('0');
	line3.push_back('0');

	vector<char> line4;
	line4.push_back('0');
	line4.push_back('0');
	line4.push_back('0');
	line4.push_back('0');
	line4.push_back('0');

	grid.push_back(line1);
	grid.push_back(line2);
	grid.push_back(line3);
	grid.push_back(line4);

	Solution sln;
	auto rlt = sln.numIslands(grid);

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
