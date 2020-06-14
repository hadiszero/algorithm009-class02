// 874. Walking Robot Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	struct pair_hash
	{
		inline size_t operator()(const pair<__int64, __int64> &rP) const
		{
			return rP.first * 40000, rP.second;
		}
	};

	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int iDir = 0;	// North
		pair<int, int> pDir[4] = { make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};	//	N->E->S->W

		unordered_set<pair<__int64, __int64>, pair_hash> ObsSet;
		for (auto& rObs : obstacles)
			ObsSet.insert(make_pair(rObs[0], rObs[1]));

		int rlt = 0;
		pair<int, int> pCurLocation(0, 0);
		for (int cmd : commands)
		{
			if (cmd < 0)
			{
				iDir = (iDir + (cmd == -1 ? 1 : 3)) % 4;
				continue;
			}
			
			for (int i = 0; i < cmd; ++i)
			{
				int iNextX = pCurLocation.first + pDir[iDir].first;
				int iNextY = pCurLocation.second + pDir[iDir].second;
				if (ObsSet.find(make_pair(iNextX, iNextY)) == ObsSet.end())
					pCurLocation = make_pair(iNextX, iNextY);
				else
					break;
			}

			rlt = max(rlt, pCurLocation.first * pCurLocation.first + pCurLocation.second * pCurLocation.second);
		}

		return rlt;
	}
};


int main()
{
	vector<int> commands;
	//commands.push_back(-2);
	//commands.push_back(-2);
	//commands.push_back(-2);
	//commands.push_back(-2);
	//commands.push_back(-2);
	//commands.push_back(-1);
	//commands.push_back(-1);
	//commands.push_back(-1);
	//commands.push_back(-1);
	//commands.push_back(-1);

	commands.push_back(4);
	commands.push_back(-1);
	commands.push_back(4);
	commands.push_back(-2);
	commands.push_back(4);

	vector<vector<int>> obstacles;
	vector<int> singleObstacle;
	singleObstacle.push_back(2);
	singleObstacle.push_back(4);
	obstacles.push_back(singleObstacle);

	Solution sln;
	auto rlt = sln.robotSim(commands, obstacles);

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
