// 74. Search a 2D Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;

		int iMatrixCols = matrix[0].size();

		int iTop(0), iBottom(matrix.size() - 1);
		while (iTop <= iBottom)
		{
			int iMidV = iTop + (iBottom - iTop) / 2;
			if (target >= matrix[iMidV][0] && target <= matrix[iMidV][iMatrixCols - 1])
			{
				int iLeft(0), iRight = iMatrixCols - 1;
				while (iLeft <= iRight)
				{
					int iMidH = iLeft + (iRight - iLeft) / 2;
					if (target > matrix[iMidV][iMidH])
					{
						iLeft = iMidH + 1;
					}
					else if (target < matrix[iMidV][iMidH])
					{
						iRight = iMidH - 1;
					}
					else
					{
						return true;
					}
				}

				return false;
			}
			else if (target > matrix[iMidV][iMatrixCols - 1])
			{
				iTop = iMidV + 1;
			}
			else
			{
				iBottom = iMidV - 1;
			}
		}

		return false;
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> line1;
	line1.push_back(1);
	line1.push_back(3);
	line1.push_back(5);
	line1.push_back(7);

	vector<int> line2;
	line2.push_back(10);
	line2.push_back(11);
	line2.push_back(16);
	line2.push_back(20);

	vector<int> line3;
	line3.push_back(23);
	line3.push_back(30);
	line3.push_back(34);
	line3.push_back(50);

	matrix.push_back(line1);
	matrix.push_back(line2);
	matrix.push_back(line3);

	Solution sln;
	auto rlt = sln.searchMatrix(matrix, 13);

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
