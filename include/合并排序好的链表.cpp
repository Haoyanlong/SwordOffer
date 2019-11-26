#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 将两个排序好的链表进行合并
using namespace std;

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x): val(x), next(NULL)
	{
	}
};

ListNode * Merge(ListNode * pHead1, ListNode * pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	if(pHead2 == NULL)
		return pHead1;
	
	ListNode * pHead = NULL;
	
	if(pHead1->val <= pHead2->val)
	{
		pHead = pHead1;
		pHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pHead = pHead2;
		pHead->next = Merge(pHead1, pHead2->next);
	}
	return pHead;
}

