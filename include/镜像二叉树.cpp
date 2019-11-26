#include<iostream>
#include<cstdio>
#include<cstring>

// 将二叉树进行镜像调换
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	}
};

void Mirror(TreeNode * pRoot)
{
	if(!pRoot)
		return;
	TreeNode * p = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = p;
	Mirror(pRoot->left);
	Mirrot(pRoot->right);
}

