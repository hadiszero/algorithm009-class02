// 66. Plus One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	static vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return vector<int>(1, 1);
		
		//bool bCarry = false;
		for (int i = int(digits.size()) - 1; i >= 0; --i)
		{
			digits[i] += 1;
			if (digits[i] >= 10)
			{
				if (i == 0)
				{
					digits = vector<int>(digits.size() + 1, 0);
					digits[0] = 1;
					return digits;
				}
				else
				{
					digits[i] -= 10;
				}
			}
			else
			{
				break;
			}
		}

		return digits;
	}
};

int main()
{
	vector<int> iaDigits;
	iaDigits.push_back(1);
	iaDigits.push_back(2);
	iaDigits.push_back(3);

	vector<int> iaRlt = Solution::plusOne(iaDigits);

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
