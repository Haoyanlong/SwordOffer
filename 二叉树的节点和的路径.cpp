#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<stack>

// 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 每次取出根节点的值，递归整数减去根节点的值

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	
	}
}

class Solution
{
	public:
		vector<vector<int> > buffer;
		vector<int> tmp;
		vector<vector<int> > FindPath(TreeNode * root, int expectNumber)
		{
			if(root == NULL)
				return buffer;
			tmp.push_back(root->val);
			
			if((expectNumber - root->val == 0) && root->left == NULL && root->right == NULL)
				buffer.push_back(tmp);
			
			FindPath(root->left, expectNumber - root->val);
			FindPath(root->right, expectNumber - root->val);
			
			if(tmp.size() != 0)
				tmp.pop_back();	 		
		
			return buffer;
		}
}


