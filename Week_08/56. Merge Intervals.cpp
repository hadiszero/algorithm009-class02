// 56. Merge Intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size();) {
			int t = intervals[i][1];
			int j = i + 1;
			while (j < intervals.size() && intervals[j][0] <= t) {
				t = max(t, intervals[j][1]);
				j++;
			}
			ans.push_back({ intervals[i][0], t });
			i = j;
		}

		return ans;
	}
};

int main()
{
	vector<vector<int>> intervals;

	vector<int> range1;
	range1.push_back(1);
	range1.push_back(3);

	vector<int> range2;
	range2.push_back(1);
	range2.push_back(4);

	vector<int> range3;
	range3.push_back(1);
	range3.push_back(2);

	vector<int> range4;
	range4.push_back(5);
	range4.push_back(4);

	vector<int> range5;
	range5.push_back(4);
	range5.push_back(5);

	intervals.push_back(range1);
	intervals.push_back(range2);
	intervals.push_back(range3);
	intervals.push_back(range4);
	intervals.push_back(range5);

	Solution sln;
	sln.merge(intervals);


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
