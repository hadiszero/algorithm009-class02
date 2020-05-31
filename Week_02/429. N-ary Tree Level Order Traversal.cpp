// 429. N-ary Tree Level Order Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

//	TODO: DFS

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:
	static vector<vector<int>> rlt;

	static vector<vector<int>> levelOrder(Node* root) {
		if (!root) return rlt;

		deque<Node*> idDeque;
		idDeque.push_back(root);

		BFS(idDeque, 0);

		return rlt;
	}

	static void BFS(deque<Node*>& rDeque, int iLevel)
	{
		if (rDeque.empty())
			return;

		if (rlt.size() <= iLevel)
		{
			rlt.push_back(vector<int>());
		}

		int iNodeCnt = rDeque.size();
		for (int i = 0; i < iNodeCnt; ++i)
		{
			Node* pFront = rDeque.front();
			rDeque.pop_front();

			if (pFront)
			{
				rlt[iLevel].push_back(pFront->val);
				for (Node* pChild : pFront->children)
				{
					rDeque.push_back(pChild);
				}
			}
		}

		BFS(rDeque, iLevel + 1);
	}
};

vector<vector<int>> Solution::rlt;

int main()
{
	Node* pNode2 = new Node(2);


	Node* pNode14 = new Node(14);

	Node* pNode11 = new Node(11);
	pNode11->children.push_back(pNode14);

	Node* pNode7 = new Node(7);
	pNode7->children.push_back(pNode11);

	Node* pNode6 = new Node(6);

	Node* pNode3 = new Node(3);
	pNode3->children.push_back(pNode6);
	pNode3->children.push_back(pNode7);


	Node* pNode12 = new Node(12);

	Node* pNode8 = new Node(8);
	pNode8->children.push_back(pNode12);

	Node* pNode4 = new Node(4);
	pNode4->children.push_back(pNode8);


	Node* pNode13 = new Node(13);

	Node* pNode9 = new Node(9);
	pNode9->children.push_back(pNode13);

	Node* pNode10 = new Node(10);

	Node* pNode5 = new Node(5);
	pNode5->children.push_back(pNode9);
	pNode5->children.push_back(pNode10);


	Node* pNode1 = new Node(1);
	pNode1->children.push_back(pNode2);
	pNode1->children.push_back(pNode3);
	pNode1->children.push_back(pNode4);
	pNode1->children.push_back(pNode5);

	auto rlt = Solution::levelOrder(pNode1);

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
