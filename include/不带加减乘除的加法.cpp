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

// 求两个整数之和

using namespace std;

int Add1(int num1, int num2)
{
	while(num2)
	{
		int temp = num1 ^ num2;
		num2 = (num1 & num2)<<1;
		num1 = temp;
	}
	return num1;
}

int Add2(int num1, int num2)
{
	return num2 ? Add2(num2 ^ num1, (num1 & num2) << 1) : num1;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	int add1 = Add1(a, b);
	int add2 = Add2(a, b);
	printf("add1=%d add2=%d", add1, add2);
	return 0;
}

