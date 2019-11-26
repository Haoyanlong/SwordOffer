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

// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序(左根右)的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

using namespace std;

/*
1.有右子树的，那么下个节点就是右子树最左边的点;
2.没有右子树的，也可以分为两类:
	a.是父节点的左孩子，那么父节点就是下一个节点;
	b.是父节点的右孩子，找它父节点的父节点，直到当前节点是其父节点的左孩子;
*/
struct TreeLinkNode
{
	int val;
	struct TreeLinkNode * left;
	struct TreeLinkNode * right;
	struct TreeLinkNode * next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};

TreeLinkNode * GetNext(TreeLinkNode * pNode)
{
	if(pNode == NULL) return NULL;
	
	// 如果存在右子树,找右子树最左边的点
	if(pNode->right != NULL)
	{
		pNode = pNode->right;
		while(pNode->left != NULL)
			pNode = pNode->left;
		return pNode;
	}
	// 没有右子树且是父节点的左孩子
	// 没有右子树且是父节点的右孩子，一直向上找，直至父节点是父节点的父节点的左孩子
	while(pNode->next != NULL)
	{
		if(pNode->next->left == pNode)
			return pNode->next;
		pNode = pNode->next;
	}	
}

