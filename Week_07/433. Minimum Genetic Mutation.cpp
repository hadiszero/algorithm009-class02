// 433. Minimum Genetic Mutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> candidate(bank.begin(), bank.end());
		queue<pair<string, int>> q;
		q.push(make_pair(start, 0));

		while (!q.empty())
		{
			if (q.front().first == end) return q.front().second;

			string& gene = q.front().first;
			int step = q.front().second;
			for (int i = 0; i < gene.length(); ++i)
			{
				char backup = gene[i];
				for (char c : "ATCG")
				{
					if (c == backup) continue;
					gene[i] = c;
					if (candidate.find(gene) == candidate.end()) continue;

					q.push(make_pair(gene, step + 1));
					candidate.erase(gene);
				}

				gene[i] = backup;
			}

			q.pop();
		}

		return -1;
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
