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

// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
// 也不知道每个数字重复几次。请找出数组中任意一个重复的数字
using namespace std;

bool duplicate(int numbers[], int length, int * duplication)
{
	bool mask[length];
	memset(mask, false, sizeof(mask));
	int i;
	for(i = 0; i < length; i++)
	{
		if(mask[numbers[i]])
		{
			*duplication = numbers[i];
			return true;
		}
		else
		{
			// printf("%d\n", i);
			mask[numbers[i]] = true;
		}
	}
	return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	int numbers[N];
	for(int i = 0; i < N; i++)	
		scanf("%d", &numbers[i]);
	int dupliNums = -1;
	
	bool flag = duplicate(numbers, N, &dupliNums);
	printf("%d\n", dupliNums);
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
		
	return 0;
}


