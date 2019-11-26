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

// 判断一个树是否是平衡二叉树
// 只需要判断左右孩子的高度只差是否是小于1
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

// 获取树的高度
int TreeDepth(TreeNode * p)
{
	if(p == NULL) return 0;
	return max(1 + TreeDepth(p->left), 1 + TreeDepth(p->right));
}

bool IsBalanced_Solution(TreeNode * pRoot)
{
	if(!pRoot) return true;
	
	int left_depth = TreeDepth(pRoot->left);
	int right_depth = TreeDepth(pRoot->right);
	if(abs(left_depth - right_depth) > 1)
		return false;
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}


