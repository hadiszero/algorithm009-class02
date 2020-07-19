// 680. Valid Palindrome II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		if (s.length() == 0) return true;
		validPalindrome(s, 0, s.length() - 1, 1);
	}

	bool validPalindrome(string s, int left, int right, int leftDelCnt)
	{
		while (left < right)
		{
			if (s[left] != s[right])
			{
				if (leftDelCnt > 0) return validPalindrome(s, left + 1, right, leftDelCnt - 1) || validPalindrome(s, left, right - 1, leftDelCnt - 1);
				else return false;
			}
			else
			{
				++left;
				--right;
			}
		}

		return true;
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
