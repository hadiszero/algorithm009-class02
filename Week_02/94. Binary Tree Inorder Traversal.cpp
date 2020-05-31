// 94. Binary Tree Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* pLeft, TreeNode* pRight) : val(x), left(pLeft), right(pRight)
	{
	}
};
 
class Solution {
public:
	static vector<int> inorderTraversal(TreeNode* root) {
		//stack<TreeNode*> psStack;
		//vector<int> iaRlt;
		//TreeNode* pNode = root;
		//while (pNode || !psStack.empty())
		//{
		//	while (pNode)
		//	{
		//		psStack.push(pNode->right);
		//		iaRlt.push_back(pNode->val);
		//		pNode = pNode->left;
		//	}
		//	pNode = psStack.top();
		//	psStack.pop();
		//}
		//return iaRlt;

		stack<TreeNode*> psStack;
		vector<int> iaRlt;
		TreeNode* pNode = root;
		while (pNode || psStack.size())
		{
			while (pNode)
			{
				psStack.push(pNode);
				pNode = pNode->left;
			}

			pNode = psStack.top();
			psStack.pop();
			iaRlt.push_back(pNode->val);
			pNode = pNode->right;
		}

		return iaRlt;
	}

	static void inorderHelper(TreeNode* pNode, vector<int>& rRlt)
	{
		if (!pNode) return;

		inorderHelper(pNode->left, rRlt);
		rRlt.push_back(pNode->val);
		inorderHelper(pNode->right, rRlt);
	}

};
int main()
{
	TreeNode* pNode3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* pNode4 = new TreeNode(4, nullptr, nullptr);
	TreeNode* pNode2 = new TreeNode(2, pNode3, pNode4);
	TreeNode* pNode1 = new TreeNode(1, nullptr, pNode2);

	auto rlt = Solution::inorderTraversal(pNode1);

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
