// 1122. Relative Sort Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		const int arrSize = 1001;
		int hashMap[arrSize] = {};
		for (int val : arr1) ++hashMap[val];

		vector<int> rlt;
		for (int i = 0; i < arr2.size(); ++i)
		{
			for (int j = 0; j < hashMap[arr2[i]]; ++j) rlt.push_back(arr2[i]);
			hashMap[arr2[i]] = 0;
		}

		for (int i = 0; i < arrSize; ++i)
		{
			if (hashMap[i] == 0) continue;

			for (int j = 0; j < hashMap[i]; ++j) rlt.push_back(i);
		}

		return move(rlt);
	}
};

int main()
{
	Solution sln;
	vector<int> arr1;
	vector<int> arr2;

	arr1.push_back(28);
	arr1.push_back(6);
	arr1.push_back(22);
	arr1.push_back(8);
	arr1.push_back(44);
	arr1.push_back(17);

	arr2.push_back(22);
	arr2.push_back(28);
	arr2.push_back(8);
	arr2.push_back(6);

	auto rlt = sln.relativeSortArray(arr1, arr2);

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
