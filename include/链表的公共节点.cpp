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

// 链表的第一个公共节点

using namespace std;

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x):val(x), next(NULL)
	{
	}
};

// 用两个指针扫描两个链表，知道最后或者公共节点
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	ListNode * p1 = pHead1;
	ListNode * p2 = pHead2;
	while(p1 != p2)
	{
		p1 = (p1 == NULL ? pHead2 : p1->next);
		p2 = (p2 == NULL ? pHead1 : p2->next);
	}
	return p1;
}

// 长度差
ListNode * FindFirstCommonNode(ListNode * pHead1, ListNode * pHead2)
{
	ListNode * p1 = pHead1;
	ListNode * p2 = pHead2;
	int len1 = 0, len2 = 0, diff = 0;
	
	// 计算两个链表的长度
	while(p1!=NULL)
	{
		p1 = p1->next;
		len1++;
	}
	while(p2 != NULL)
	{
		p2 = p2->next;
		len2++;
	}
        
	if(len1 > len2)
	{
		diff = len1 - len2;
		p1 = pHead1;
		p2 = pHead2;
	}
        
	else
	{
    	diff=len2-len1;
    	p1=pHead2;
    	p2=pHead1;
    }
    for(int i = 0; i<diff; i++)
    {
    	p1 = p1->next;
    }
    while(p1 != NULL && p2 != NULL)
    {
    	if(p1 == p2)
        	break;
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

