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

using namespace std;

// 一个链表中包含环，请找出该链表的环的入口结点。

/*
第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，直到p1==p2找到在环中的相汇点。
第二步，找环的入口。接上步，当p1==p2时，p2所经过节点数为2x,p1所经过节点数为x,设环中有n个节点,p2比p1多走一圈有2x=n+x; 
n=x;可以看出p1实际走了一个环的步数，再让p2指向链表头部，p1位置不变，p1,p2每次走一步直到p1==p2; 此时p1指向环的入口
*/

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNode(int x): val(x), next(NULL)
	{
	
	}
};

ListNode * EntryNodeOfLoop(ListNode * pHead)
{
	if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) return NULL;
	
	ListNode * fast = pHead->next->next;
	ListNode * slow = pHead->next;
	
	// 首先判断是否有环
	while(fast != slow)
	{
		if(fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		else
			// 没有环，返回
			return NULL;
	}
	
	// 当fast = slow的时候说明是存在环的
	fast = pHead;
	while(fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

