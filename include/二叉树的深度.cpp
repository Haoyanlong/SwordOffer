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

// 二叉树的深度

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

// 递归
int TreeDepth(TreeNode * pRoot)
{
	if(!pRoot) return 0;
	return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
}

