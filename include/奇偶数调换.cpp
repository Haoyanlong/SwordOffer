#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 调整数组顺序,使得奇数位于前半部分,偶数位于后半部分
// 类似与冒泡法
void reOrderArray(vector<int> & array)
{
	for(int i = 0; i < array.size(); i++)
	{
		for(int j = array.size() - 1; j > i; j--)
		{
			if(array[j] % 2 == 1 && array[j - 1] % 2 == 0)    // 前偶后奇交换
			{
				swap(array[j], array[j-1]);
			}
		}
	}
}




































