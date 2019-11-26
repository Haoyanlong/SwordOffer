#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x):val(x), next(NULL)
	{
	
	}
};

vector<int> printListFromTailToHead(ListNode * head)
{
	vector<int> res;
	ListNode * p = head;
	while(p != NULL)
	{
		res.push(p->val);
		p = p ->next;
	}
	reverse(res.begin(), res.end());
	return res;
}

