#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<stack>

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表，
// 不能创建任何新的节点，只能调整树中节点指针的指向
// 对二叉搜索树进行中序遍历

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	
	}
}]

TreeNode * Convert(TreeNode * pRootOfTree)
{
	if(!pRootOfTree) return NULL;
	TreeNode * pre = NULL;
	convertHelper(pRootOfTree, pre);
	
	TreeNode * res = pRootOfTree;
	while(res->left)
		res = res->left;
	return res;
}

void convertHelper(TreeNode * cur, TreeNode *& pre)
{
	if(!cur)
		return;
	convertHelper(cur->left, pre);
	cur->left = pre;
	if(pre) pre->right = cur;
	pre = cur;
	
	convertHelper(cur->right, pre);
}



