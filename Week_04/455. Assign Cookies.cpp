// 455. Assign Cookies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int iGPtr = static_cast<int>(g.size()) - 1;
		int iSPtr = static_cast<int>(s.size()) - 1;

		int iRlt = 0;
		while (iGPtr >= 0 && iSPtr >= 0)
		{
			if (g[iGPtr] <= s[iSPtr]) { ++iRlt; --iGPtr; --iSPtr; }
			else --iGPtr;
		}

		return iRlt;
	}
};

int main()
{
	vector<int> iaGreed;
	iaGreed.push_back(1);
	iaGreed.push_back(2);
	//iaGreed.push_back(3);

	vector<int> iaSize;
	iaSize.push_back(1);
	//iaSize.push_back(1);

	iaSize.push_back(2);
	iaSize.push_back(3);

	Solution sln;
	auto rlt = sln.findContentChildren(iaGreed, iaSize);

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
