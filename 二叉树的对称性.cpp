#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<sstream>

// 实现一个函数用来判断一颗二叉树是不是对称的

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

bool isSymmetrical1(TreeNode * pRoot1, TreeNode * pRoot2)
{
	if(pRoot1 == NULL && pRoot2 == NULL)
		return true;
	if(pRoot1 == NULL || pRoot2 == NULL)
		return false;
	
	if(pRoot1->val != pRoot2->val)
		return false;
	
	return isSymmetrical1(pRoot1->left, pRoot2->right) && isSymmetrical1(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode * pRoot)
{
	return isSymmetrical1(pRoot, pRoot);
}

