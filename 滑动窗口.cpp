#include<iostream>
#include<cstdio>
#include<cstring>
// 给定一个数组和滑动窗口的大小，找出所有滑动窗口数值的最大值

using namespace std;

class Solution
{
	public:
		vector<int> maxInWindows(const vector<int> & num, unsigned int size)
		{
			vector<int> res;
			if(num.size() == 0 || size == 0)
				return res;
			
			unsigned int i = 0;
			while(i + size <= num.size())
			{
				int max = -100000;
				for(unsigned int j = i; j <= i + size - 1; j++)
				{
					if(num[j] > max)
						max = num[j];
				}
				res.push_back(max);
				i++;
			}
			return res;
		}
}


