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

// 删除链表中重复的节点
// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
using namespace std;

struct ListNode
{
	int val;
	struct ListNode * next;
	ListNde(int x): val(x), next(NULL)
	{
	
	}
}

ListNode * deleteDuplication(ListNode * pHead)
{
	if(pHead == NULL) return pHead;
	
	ListNode * pre = NULL;           // 指向前面最晚访问过的不重复节点 
	ListNode * p = pHead;            // 指向当前处理的节点
	ListNode * q = NULL;             // 指向当前处理节点后面的节点
	
	while(p != NULL)
	{
		// 当前节点p, 如果与它下一个节点p->next的所有val相同，说明要删除这个val的所有节点
		if(p->next != NULL && p->next->val == p->val)
		{
			q = p->next;
			// 找到q, 它指向最后一个与p.val相同的节点，那么p到q(包含)都是要删除的
			while(q != NULL && q->next->val == q.val)
				q = q->next;
		
		
			// 如果p指向链表中的第一个元素, p->...->q->....,则要删除p和q中间的元素
			// 将指向链表的第一个元素的指针指向q->next
			if(p == pHead)
			{
				pHead = q->next;
			}
			// 如果p不指向链表中的第一个元素,pre->p->...->q->...
			// 要删除p到q, 即pre->next = q->next
			else
			{
				pre->next = q->next;
			}
			p = q->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return pHead;
}

