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

// 统计从1到n中1出现的次数

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if(n < 1) return 0;
	if(n == 1) return 1;
	
	int count = 0;
	for(int i = 1; i < n; i++)
	{
		int temp = i;
		while(temp)
		{
			if(temp % 10 == 1)
				count++;
			temp /= 10;
		}
	}
	return count;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	// cin >> n;
	int temp = NumberOf1Between1AndN_Solution(n);
	printf("%d\n", temp);
	return 0;
}

