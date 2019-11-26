#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<stack>

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	}
}

vector<int> PrintFromTopToBottom(TreeNode * root)
{
	vector<int> que;
	queue<TreeNode *> q;
	TreeNode * fr;
	if(root == NULL) return que;
	q.push(root);
	
	while(!q.empty())
	{
		fr = q.front();
		que.push_back(fr->val);
		if(fr->left != NULL)
			q.push(fr->left);
		if(fr->right != NULL)
			q.push(fr->right);
		q.pop();
	}
	return que;
}

