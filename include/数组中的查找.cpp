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
#include<heap>


// 寻找在数组中出现的次数超过一半的数，如果不存在则输出为0
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int len = numbers.size();
	int halfLen = len>>1;
	if(len == 0)
		return 0;
	
	map<int, int> cnt;
	for(int i = 0; i < len; i++)
	{
		int num_i = numbers[i];
		if(!cnt.count(numbers[i]))
			cnt[numbers[i]] = 1;
		else
			cnt[numbers[i]]++;
	}
	for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if(cnt[*it] > halfLen)
			return *it;
	}
	return 0;
}

int main()
{
	int nums[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	vector<int> inputs(nums, nums+9);
	int output_num = MoreThanHalfNum_Solution(inputs);
	printf("%d\n", output_num);
	
	return 0;
}
