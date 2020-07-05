// 22. Generate Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> rlt;
	vector<string> generateParenthesis(int n) {
		_gen(0, 0, n, "");
		return rlt;
	}

	void _gen(int left, int right, int n, string str)
	{
		if (left == right && left == n)
		{
			rlt.push_back(str);
			return;
		}

		if (left < n) _gen(left + 1, right, n, str + "(");
		if (left > right && right < n) _gen(left, right + 1, n, str + ")");
	}
};

int main()
{
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
