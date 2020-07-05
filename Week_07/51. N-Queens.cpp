// 51. N-Queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> tmpRlt;
	map<int, int> cols, pie, na;

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> rlt;
		if (n < 1) return rlt;
		
		vector<int> single;
		dfs(n, 0, single);
		
		string line;
		for (int i = 0; i < n; ++i) line += ".";
		for (auto& val : tmpRlt)
		{
			vector<string> singleBoard;
			
			for (auto index : val)
			{
				((char*)(line.c_str()))[index] = 'Q';
				singleBoard.push_back(line);
				((char*)(line.c_str()))[index] = '.';
			}
			rlt.push_back(move(singleBoard));
		}

		return move(rlt);
	}

	void dfs(int n, int row, vector<int>& cur)
	{
		if (row >= n)
		{
			tmpRlt.push_back(cur);
			return;
		}

		for (int col = 0; col < n; ++col)
		{
			if (cols[col] != 0 || pie[row + col] != 0 || na[row - col] != 0) continue;

			cols[col] = 1; pie[row + col] = 1; na[row - col] = 1;
			cur.push_back(col);
			dfs(n, row + 1, cur);
			cur.pop_back();
			cols[col] = 0; pie[row + col] = 0; na[row - col] = 0;
		}
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.solveNQueens(4);
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
