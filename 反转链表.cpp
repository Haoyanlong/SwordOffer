#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>

// 反转链表 需要用到堆栈
using namespace std;

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x): val(x), next(NULL)
	{
	}
}

ListNode * ReverseList(ListNode * pHead)
{
	if(pHead == NULL || pHead->next == NULL)
		return pHead;

	stack<ListNode *> result;
	
	ListNode * p = pHead;
	while(p->next)
	{
		result.push(p);
		p = p->next;
	}
	
	ListNode * head = p;
	while(!result.empty())
	{
		p->next = result.top();
		result.pop();
		p=p->next;
	}
	p->next = NULL;
	return head;
	
}

