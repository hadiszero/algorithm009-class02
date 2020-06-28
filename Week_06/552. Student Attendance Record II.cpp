// 552. Student Attendance Record II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int checkRecord(int n) {
		long M = 1000000007;

		auto f = vector<long>(n <= 5 ? 6 : n + 1, 0);
		f[0] = 1;
		f[1] = 2;
		f[2] = 4;
		f[3] = 7;
		for (int i = 4; i <= n; i++) f[i] = ((2 * f[i - 1]) % M + (M - f[i - 4])) % M;
		long sum = f[n];
		for (int i = 1; i <= n; i++) sum += (f[i - 1] * f[n - i]) % M;

		return (int)(sum % M);
	}
};

int main()
{
	Solution sln;
	auto r = sln.checkRecord(2);

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
