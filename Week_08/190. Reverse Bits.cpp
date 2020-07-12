// 190. Reverse Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		//uint32_t ans = 0;
		//for (int i = 0; i < 8 * sizeof(uint32_t); i++) {
		//	ans = (ans << 1) + (n & 1);
		//	n = n >> 1;
		//}
		//return ans;


		uint32_t rlt = 0;
		for (int i = 0; i < sizeof(n) * 8; ++i)
		{
			rlt = (rlt << 1) + (n & 1);
			n = n >> 1;
		}

		return rlt;
	}
};

int main()
{
	Solution sln;
	auto rlt = sln.reverseBits(3);
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
