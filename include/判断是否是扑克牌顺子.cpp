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

// 给出5个数来判断是否是顺子(0是万能的)
/*
顺子满足的条件: max - min < 5
除过0外的其他数字不能重复
传入的数组放5个元素
*/
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	if(numbers.empty()) return 0;
	int count[14] = {0};   // 记录每个元素出现的次数，以numbers中的元素作为下标(最大K, 对应13)
	int len = numbers.size();
	int max = -1;
	int min = 14;
	
	for(int i = 0; i < len; ++i)
	{
		count[numbers[i]]++;
		if(numbers[i] == 0) continue;
		
		if(count[numbers[i]] > 1) return 0;
		if(numbers[i] > max) max = numbers[i];
		if(numbers[i] < min) min = numbers[i];
	}
	if(max - min < 5)   // 注意最大数减去最小数一定小于5
		return 1;
	return 0;
}


int main()
{
	int N = 5;
	int numbers[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);
	
	vector<int> test_nums(numbers, numbers+N);
	
	
	bool iscon;
	iscon = IsContinuous(test_nums);
	
	if(iscon)
		printf("YES!!!\n");
	else
		printf("NO!!!\n");
	return 0;
}


