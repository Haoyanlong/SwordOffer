#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 判断一个树是不是另一个树的子树
using namespace std;

bool isSubtree(TreeNode * pRootA, TreeNode * pRootB)
{
	if(!pRootB) return true;
	if(!pRootA) return false;
	
	if(pRootA->val == pRootB->val)
	{
		if(isSubtree(pRootA->left, pRootB->left) && isSubtree(pRootA->right, pRootB->right))
			return true;
	}
	return false;
}

bool HasSubtree(TreeNode * pRoot1, TreeNode * pRoot2)
{
	if(!pRoot1 || !pRoot2)
		return false;
	if(pRoot1->val == pRoot2->val)
	{
		if(isSubtree(pRoot1, pRoot2))
			return true;
	}
	if(HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2))
	{
		return true;	
	}
	return false;
}

