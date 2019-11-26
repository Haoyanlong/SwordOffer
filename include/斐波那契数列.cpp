#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 斐波那契数列，输入n,　输出数列的第n项
int Fibonacci(int n)
{
	int res = 0;
	if(n == 0)
		return 0;
	if(n == 1 || n == 2)
		return 1;
	if(n > 2)
		res = Fibonacci(n-1) + Fibonacci(n-2);
	return res;
}

// 类似与青蛙跳台阶,一次只能跳一节或者两节，问有多少种跳法
int jumpFloor1(int number)
{
	if(number == 1)
		return 1;
	if(number == 2)
		return 2;
	return jumpFloor1(number-1) + jumpFloor1(number-2);
}
// 一次可以调到任何台阶,有多少中跳法,n = n-1 + 1
int jumpFloor2(int number)
{
	if(number == 1)
		return 1;
	int ans = 1;
	for(int i = 1; i < number; i++)
		ans *= 2;
	return ans;
}
// 矩形砖覆盖(依旧是斐波那契数列)
int RectCover(int target)
{
	it(target < 1)
		return 0;
	else if(target == 1 || target == 2)
		return target;
	else
		return RectCover(target-1) + RectCover(target-2);
}


int main()
{
	int num;
	scanf("%d", &num);
	int res;
	res = jumpFloor2(num);
	printf("output=%d\n", res);
	return 0;
}

