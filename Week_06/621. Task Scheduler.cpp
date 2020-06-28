// 621. Task Scheduler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		//auto taskCnt = vector<int>(26, 0);
		//for (char c : tasks) ++taskCnt[c - 'A'];
		//sort(taskCnt.begin(), taskCnt.end(), [](int& v1, int& v2) {return v1 > v2; });
		//int finalTaskCnt = 1;
		//while (finalTaskCnt < taskCnt.size() && taskCnt[finalTaskCnt] == taskCnt[0]) ++finalTaskCnt;

		//return max(int(tasks.size()), finalTaskCnt + (n + 1) * (taskCnt[0] - 1));




		auto taskCnt = vector<int>(26, 0);
		for (char c : tasks) ++taskCnt[c - 'A'];
		sort(taskCnt.begin(), taskCnt.end(), [](int& v1, int& v2) {return v1 > v2; });
		int finalTaskCnt = 1;
		while (finalTaskCnt < taskCnt.size() && taskCnt[finalTaskCnt] == taskCnt[0]) ++finalTaskCnt;

		return max(int(tasks.size()), finalTaskCnt + (n + 1) * (taskCnt[0] - 1));

	}
};

int main()
{
	vector<char> tasks;
	tasks.push_back('A');
	tasks.push_back('A');
	tasks.push_back('A');
	tasks.push_back('B');
	tasks.push_back('B');
	tasks.push_back('B');

	Solution sln;
	auto rlt = sln.leastInterval(tasks, 2);
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
