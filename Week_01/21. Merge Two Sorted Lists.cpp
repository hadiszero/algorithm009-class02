// 21. Merge Two Sorted Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* pNext) : val(x), next(pNext)
	{
	}
};

class Solution {
public:
	static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;

		if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}
};

int main()
{
	ListNode* pListNode14 = new ListNode(8, nullptr);
	ListNode* pListNode13 = new ListNode(6, pListNode14);
	ListNode* pListNode12 = new ListNode(4, pListNode13);
	ListNode* pListNode11 = new ListNode(2, pListNode12);

	ListNode* pListNode24 = new ListNode(7, nullptr);
	ListNode* pListNode23 = new ListNode(5, pListNode24);
	ListNode* pListNode22 = new ListNode(3, pListNode23);
	ListNode* pListNode21 = new ListNode(1, pListNode22);

	Solution::mergeTwoLists(pListNode11, pListNode21);

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
