// 363. Max Sum of Rectangle No Larger Than K.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty()) return 0;
		int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
		for (int l = 0; l < col; ++l) {
			vector<int> sums(row, 0);
			for (int r = l; r < col; ++r) {
				for (int i = 0; i < row; ++i) sums[i] += matrix[i][r];

				set<int> accuSet;
				accuSet.insert(0);
				int curSum = 0, curMax = INT_MIN;
				for (int sum : sums)
				{
					curSum += sum;
					set<int>::iterator it = accuSet.lower_bound(curSum - k);
					if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
					accuSet.insert(curSum);
				}
				res = std::max(res, curMax);
			}
		}

		return res;
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> line1;
	line1.push_back(1);
	line1.push_back(0);
	line1.push_back(1);

	vector<int> line2;
	line2.push_back(0);
	line2.push_back(-2);
	line2.push_back(3);

	matrix.push_back(line1);
	matrix.push_back(line2);

	Solution sln;
	auto rlt = sln.maxSumSubmatrix(matrix, 2);

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
