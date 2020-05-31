// 589. N-ary Tree Preorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
	//vector<int> iaRlt;

	//vector<int> preorder(Node* root) {
	//	if (!root)
	//		return iaRlt;

	//	TraverseHelper(root);

	//	return iaRlt;		
	//}

	//void TraverseHelper(Node* root)
	//{
	//	if (!root)
	//		return;

	//	iaRlt.push_back(root->val);
	//	for (Node* pNode : root->children)
	//		TraverseHelper(pNode);
	//}


	vector<int> preorder(Node* root) {
		vector<int> iaRlt;

		if (!root) return iaRlt;

		stack<Node*> spStack;
		spStack.push(root);
		while (!spStack.empty())
		{
			Node* pCur = spStack.top();
			spStack.pop();
			iaRlt.push_back(pCur->val);

			if (pCur->children.size() > 0)
			{
				for (int i = pCur->children.size() - 1; i >= 0; --i)
					spStack.push(pCur->children[i]);
			}

		}

		return iaRlt;
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
