// 493. Reverse Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void update(vector<int>& BIT, int index, int val)
{
	while (index > 0) {
		BIT[index] += val;
		index -= index & (-index);
	}
}

int query(vector<int>& BIT, int index)
{
	int sum = 0;
	while (index < BIT.size()) {
		sum += BIT[index];
		index += index & (-index);
	}
	return sum;
}

int reversePairs(vector<int>& nums)
{
	int n = nums.size();
	vector<int> nums_copy(nums);

	sort(nums_copy.begin(), nums_copy.end());

	vector<int> BITS(n + 1, 0);
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
		update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
	}
	return count;
}


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
