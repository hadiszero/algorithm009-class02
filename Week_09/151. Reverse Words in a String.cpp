// 151. Reverse Words in a String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		auto itr = s.rbegin();
		deque<char> dStr;
		while (itr != s.rend())
		{
			if (dStr.size() == 0 && *itr == ' ')
			{
				++itr;
				continue;
			}

			dStr.push_back((*itr++));
		}

		string sRlt;
		while (!dStr.empty())
		{
			char c = dStr.front(); dStr.pop_front();
			if (c == ' ') continue;

			string tmp;
			tmp += c;
			while (!dStr.empty())
			{
				c = dStr.front(); dStr.pop_front();
				if (c != ' ')
					tmp += c;
				else
					break;
			}

			reverse(tmp.begin(), tmp.end());
			if (sRlt.length() > 0) sRlt += " ";
			sRlt += tmp;
		}

		return sRlt;
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
