// 917. Reverse Only Letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	inline bool isAlphabet(char c)
	{
		if ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			)
		{
			return true;
		}

		return false;
	}

	string reverseOnlyLetters(string S) {
		if (S.length() == 0) return "";
		int begin = 0, end = S.length() - 1;

		while (begin < end)
		{
			if (!isAlphabet(S[begin]))
			{
				++begin;
				continue;
			}

			if (!isAlphabet(S[end]))
			{
				--end;
				continue;
			}

			swap(S[begin++], S[end--]);
		}

		return move(S);
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
