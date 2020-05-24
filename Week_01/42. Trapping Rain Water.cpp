// 42. Trapping Rain Water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int trap(vector<int>& height) {
		int iRlt = 0;
		stack<int> siMono;
		for (int i = 0; i < height.size(); ++i)
		{
			while (!siMono.empty() && height[siMono.top()] < height[i])
			{
				int iCur = siMono.top();
				siMono.pop();
				if (siMono.empty()) break;
				int iLeft = siMono.top();
				int iRight = i;
				int iHeight = min(height[iRight], height[iLeft]) - height[iCur];
				iRlt += (iRight - iLeft - 1) * iHeight;
			}
			siMono.push(i);
		}

		return iRlt;
	}
};

int main()
{
	vector<int> iaHeight;
	iaHeight.push_back(0);
	iaHeight.push_back(1);
	iaHeight.push_back(0);
	iaHeight.push_back(2);
	iaHeight.push_back(1);
	iaHeight.push_back(0);
	iaHeight.push_back(1);
	iaHeight.push_back(3);
	iaHeight.push_back(2);
	iaHeight.push_back(1);
	iaHeight.push_back(2);
	iaHeight.push_back(1);

	int iRlt = Solution::trap(iaHeight);

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
