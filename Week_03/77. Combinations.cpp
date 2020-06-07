// 77. Combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int>> iaaRlt;
	vector<vector<int>> combine(int n, int k) {
		vector<int> subRlt;
		CombineHelper(n, k, 1, subRlt);
		return iaaRlt;
	}

	void CombineHelper(int n, int k, int iCur, vector<int>& rSubRlt)
	{
		if (iCur > n || rSubRlt.size() > k)
		{
			if (rSubRlt.size() == k)
				iaaRlt.push_back(rSubRlt);
			
			return;
		}

		CombineHelper(n, k, iCur + 1, rSubRlt);

		rSubRlt.push_back(iCur);
		CombineHelper(n, k, iCur + 1, rSubRlt);

		rSubRlt.pop_back();
	}
};

int main()
{
	Solution oSolution;
	oSolution.combine(4, 2);

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
