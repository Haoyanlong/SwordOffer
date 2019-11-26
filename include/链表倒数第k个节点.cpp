#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 寻找链表的倒数第k个节点
struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x): val(x), next(NULL)
	{
	
	}
};
ListNode * FindKthToTail(ListNode * p, int k)
{
	ListNode * p1 = p;
	for(int i = 0; i != k; i++)
	{
		if(!p1)
			return NULL;
		else
			p1 = p1->next;
	}
	while(p1)
	{
		p1 = p1->next;
		p = p->next;
	}
	return p;

}

