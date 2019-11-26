#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数
using namespace std;

class Solution
{
	public:
		void push(int value)
		{
			stk.push(value);
			if(stk_min.empty())
				stk_min.push(value);
			else if(value <= stk_min.top())
				stk_min.push(value);
		}
		
		void pop()
		{
			if(stk.pop() == stk_min.top())
				stk_min.pop();
			stk.pop();
		}
		
		int top()
		{
			return stk.top();
		}
		int min()
		{
			return stk_min.top();		
		}
	private:
		stack<int> stk;
		stack<int> stk_min;
}


