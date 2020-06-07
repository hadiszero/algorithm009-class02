// 105. Construct Binary Tree from Preorder and Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size()) return nullptr;

		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;
		stk.push(root);
		int inorderIndex = 0;
		for (int i = 1; i < preorder.size(); ++i)
		{
			int preorderVal = preorder[i];
			TreeNode* node = stk.top();
			if (node->val != inorder[inorderIndex])
			{
				node->left = new TreeNode(preorderVal);
				stk.push(node->left);
			}
			else
			{
				while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
				{
					node = stk.top(); stk.pop();
					++inorderIndex;
				}

				node->right = new TreeNode(preorderVal);
				stk.push(node->right);
			}
		}

		return root;
	}
};

int main()
{
	vector<int> iaPre;
	vector<int> iaIn;

	iaPre.push_back(3);
	iaPre.push_back(9);
	iaPre.push_back(20);
	iaPre.push_back(15);
	iaPre.push_back(7);

	iaIn.push_back(9);
	iaIn.push_back(3);
	iaIn.push_back(15);
	iaIn.push_back(20);
	iaIn.push_back(7);

	Solution sln;
	auto rlt = sln.buildTree(iaPre, iaIn);

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
