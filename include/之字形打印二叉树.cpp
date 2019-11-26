#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x):val(x), left(NULL), right(NULL)
	{
	
	}
};

class Solution
{
public:
	vector<vector<int> > Print(TreeNode * pRoot)
	{
		vector<vector<int> > res;
		if(pRoot == NULL)
			return res;
		
		// 使用队列来前序遍历二叉树
		queue<TreeNode *> que;
		que.push(pRoot);
		// 用来标记是偶数行还是奇数行
		bool even = false;
		
		while(!que.empty())
		{
			vector<int> vec;
			const int size = que.size();
			for(int i = 0; i < size; i++)
			{
				TreeNode * tmp = que.front();
				que.pop();
				vec.push_back(tmp->val);
				if(tmp->left != NULL)
					que.push(tmp->left);
				if(tmp->right != NULL)
					que.push(tmp->right);
			}
			if(even)
				std::reverse(vec.begin(), vec.end());
			res.push_back(vec);
			even = !even;
		}
		return res;	
	}
};

