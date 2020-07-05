// 547. Friend Circles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int N = 0;
	vector<bool> visited;
	int findCircleNum(vector<vector<int>>& M) {
		N = M.size();
		visited = vector<bool>(N, false);
		int iCirCnt = 0;
		for (int i = 0; i < N; ++i)
		{
			if (!visited[i])
			{
				dfs(i, M);
				++iCirCnt;
			}
		}

		return iCirCnt;
	}

	void dfs(int i, vector<vector<int>>& M)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[j] && M[i][j] == 1)
			{
				visited[j] = true;
				dfs(j, M);
			}
		}
	}
};

int main()
{
	vector<vector<int>> M;
	vector<int> line1;
	line1.push_back(1);
	line1.push_back(1);
	line1.push_back(0);

	vector<int> line2;
	line2.push_back(1);
	line2.push_back(1);
	line2.push_back(1);

	vector<int> line3;
	line3.push_back(0);
	line3.push_back(1);
	line3.push_back(1);

	M.push_back(line1);
	M.push_back(line2);
	M.push_back(line3);



	//班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
	//如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
	//所谓的朋友圈，是指所有朋友的集合。
	//给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
	//如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
	//你必须输出所有学生中的已知的朋友圈总数。


	//[1, 0, 0, 1], 
	//[0, 1, 1, 0], 
	//[0, 1, 1, 1], 
	//[1, 0, 1, 1]
	//vector<int> line1;
	//line1.push_back(1);
	//line1.push_back(0);
	//line1.push_back(0);
	//line1.push_back(1);

	//vector<int> line2;
	//line2.push_back(0);
	//line2.push_back(1);
	//line2.push_back(1);
	//line2.push_back(0);

	//vector<int> line3;
	//line3.push_back(0);
	//line3.push_back(1);
	//line3.push_back(1);
	//line3.push_back(1);

	//vector<int> line4;
	//line4.push_back(1);
	//line4.push_back(0);
	//line4.push_back(1);
	//line4.push_back(1);

	//M.push_back(line1);
	//M.push_back(line2);
	//M.push_back(line3);
	//M.push_back(line4);

	Solution sln;
	auto rlt = sln.findCircleNum(M);

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
