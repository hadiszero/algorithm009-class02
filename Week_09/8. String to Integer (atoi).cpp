// 8. String to Integer (atoi).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int negative = 1;
		int index = 0;
		while (str[index] == ' ') ++index;
		if (str[index] == '-') negative = -1;
		if (str[index] == '-' || str[index] == '+') ++index;

		long rlt = 0;
		for (; index < str.length() && isdigit(str[index]); ++index)
		{
			rlt = rlt * 10 + (str[index] - '0');
			if (rlt >= INT_MAX && negative == 1) return INT_MAX;
			if (rlt > INT_MAX && negative == -1) return INT_MIN;
		}

		return rlt * negative;
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
