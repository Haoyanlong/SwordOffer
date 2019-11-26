#include<iostream>
#include<cstdio>
#include<cstring>

// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树
using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	
	}
}

TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	int inlen = in.size();
	if(inlen == 0)
		return NULL;
	
	vector<int> left_pre, right_pre, left_in, right_in;
	
	// 创建根节点，根节点肯定是前序遍历的第一个数
	TreeNode * head = new TreeNode(pre[0]);
	
	// 找到中序遍历根节点所在位置，存放在变量gen中
	int gen = 0;
	for(int i = 0; i < inlen; i++)
	{
		if(in[i] == pre[0])
		{
			gen = i;
			break;
		}
	}
	//　对于中序遍历，根节点左边的节点位于二叉树的左边,　根节点右边的节点位于二叉树的右边
	// 对二叉树的节点进行归并
	for(int i = 0; i < gen; i++)
	{
		left_in.push_back(in[i]);
		left_pre.push_back(pre[i+1]);  // 前序的第一个为根节点
	}
	for(int i = gen+1; i < len; i++)
	{
		right_in.push_back(in[i];
		right_pre.push_back(pre[i])
	}
	
	head->left = reConstructBinaryTree(left_pre, left_in);
	head->right = reConstructBinaryTree(right_pre, right_in);
	return head;
}

