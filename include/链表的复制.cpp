#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<stack>

// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
// 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。

using namespace std;

struct RandomListNode
{
	int val;
	struct RandomListNode * next, * random;
	RandomListNode(int x): val(x), next(NULL), random(NULL)
	{
	
	}
}

// 方法1:
/*
递归思想: 把大问题转换为若干子问题
此题转换为一个头结点和除去头结点剩余部分，剩余部分操作和原问题一样
*/

RandomListNode * Clone1(RandomListNode * pHead)
{
	if(pHead == NULL)
		return NULL;
	 
	 // 开辟一个新节点
	 RandomListNode * pCloneHead = new RandomListNode(pHead->val);
	 pCloneHead->next = pHead->next;
	 pCloneHead->random = pHead->random;
	 
	 // 递归其他节点
	 pCloneHead->next = Clone(pHead->next);
	 return pCloneHead;
}

//方法2
/*分为三步:
a.复制链表，并连成AA1BBCC1...的形式
b.更新新节点的random
c.拆分新旧链表
*/
RandomListNode * Clone(RandomListNode * pHead)
{
	if(!pHead) return NULL;
	
	// 复制链表，并连成AA1BB1CC1...的形式
	RandomListNode * cur = pHead;
	while(cur)
	{
		RandomListNode * node = new RandomListNode(cur->val);
		node->next = cur->next;
		cur->next = node;
		cur = cur->next;
	}
	
	// 更新新节点的random
	cur = pHead;
	RandomListNode * p;
	while(cur)
	{
		p = cur->next;
		if(cur->random)
			p->random = cur->random->next;           // 指向复制的新节点
		cur = p->next;
	}
	
	// 拆分链表(取出链表的偶数)
	RandomListNode * pCloneHead = pHead->next;
	RandomListNode * tmp;
	cur = pHead;
	while(cur->next)
	{
		tmp = cur->next;
		cur->next = tmp->next;
		cur = tmp;
	}
	return pCloneHead;
}


