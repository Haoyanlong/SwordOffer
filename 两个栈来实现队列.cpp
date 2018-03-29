#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>

// 用两个栈来实现队列的操作

using namespace std;

class Solution
{	
	public:
		void push(int num)
		{
			// 将数据入栈stack1
			stack1.push(num);
		}
		
		int pop()
		{
			// 从栈stack2中出,
			// 注意:如果stack2为空栈，则出栈元素为stack1中的底部元素，
			// 此时需要将stack1中的元素全部入堆栈stack2中再弹出
			int res;
			if(stack2.size() > 0)
			{
				res = stack2.top();
				stack2.pop();
			}
			else if(stack1.size() > 0)
			{
				while(stack1.size() > 0)
				{
					int ele = stack1.top();
					stack1.pop();
					stack2.push(ele);
				}
				res = stack2.top();
				stack2.pop();
			}
			return res;	
		
		}
	private:
		stack<int> stack1;
		stack<int> stack2;
}



