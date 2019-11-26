#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>

// 找出数组中最小的k个数
/*
 使用最大堆排序
 涉及应用到堆的四种操作:
 make_heap(_First, _Last, _Comp): 建立堆(默认是最大堆),可以在第三个参数传入greater<int>()得到最小堆
 push_heap(_First, _Last): 在堆中添加数据,要现在容器中加入数据，在调用push_heap()
 pop_heap(_First, _Last): 在堆中删除数据，要先调用pop_heap()再在容器中删除数据
 sort_heap(_First, _Last): 堆排序，之后就不是一个合法的heap了
*/
using namespace std;

vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
{
	int len = input.size();
	if(len <= 0 || k > len) return vector<int> ();
	
	vector<int> res(input.begin(), input.begin() + k);
	
	// 建堆
	make_heap(res.begin(), res.end());
	
	for(int i = k; i < len; i++)
	{
		if(input[i] < res[0])
		{
			// 先pop, 然后在容器中删除
			pop_heap(res.begin(), res.end());
			res.pop_back();
			
			// 先在容器中加入在push
			res.push_back(input[i]);
			push_heap(res.begin(), res.end());
		}
	}
	// 使其从小到大输出
	sort_heap(res.begin(), res.end());
	return res;
}

int main()
{
	int nums[8] = {4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> nums_vec(nums, nums+8);
	
	vector<int> res = GetLeastNumbers_Solution(nums_vec, 4);
	for(vector<int>::iterator it = res.begin(); it != res.end(); it++)
		printf("%d ", *it);
	return 0;
}

