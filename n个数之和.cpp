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


using namespace std;

// 1. sum += Sum_Solution(int n)使用递归来计算
int Sum_Solution1(int n)
{
	int sum = n;
	bool ans = (n > 0) && ((sum += Sum_Solution1(n - 1)));
	return sum;
}
// 2.　利用矩阵的大小来计算
int Sum_Solution2(int n)
{
	bool a[n][n+1];
	return sizeof(a) >> 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sum1 = Sum_Solution1(n);
	int sum2 = Sum_Solution2(n);
	
	printf("%d %d\n", sum1, sum2);
	return 0;
}

