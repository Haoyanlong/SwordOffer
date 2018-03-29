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

const int maxn = 100;
using namespace std;
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值
/*
注意表示数值的字符串遵循的规则
在数值之前可能有一个"+"或"-",接下来是0-9的数位表示数值的整数部分，
如果是一个小数，那么小数后面可能会有若干0-9的数位
来表示数值的小数部分。如果用科学计数法，接下来是一个'e'或者'E',
以及紧跟着一个整数(可能有正负号)表示指数

*/
bool isNumeric(char * string)
{
	if(string == NULL)
		return false;
	
	if(*string == '+' || *string == '-')
		string++;
	if(*string == '\0')
		return false;
	
	int dot = 0, num = 0, nume = 0;
	// 分别用来标记小数点、整数部分和e指数是否存在
	while(*string != '\0')
	{
		if(*string >= '0' && *string <= '9')
		{
			string++;
			num = 1;
		}
		else if(*string == '.')
		{
			if(dot > 0 || nume > 0)
				return false;
			string++;
			dot = 1;
		}
		else if(*string == 'e' || *string == 'E')
		{
			if(num == 0 || nume > 0)
				return false;
			string++;
			nume++;
			if(*string == '-' || *string == '+')
				string++;
			if(*string == '\0')
				return false;
		}
		else
			return false;
	}
	return true;
}


int main()
{
	char temp[maxn];
	cin >> temp;
	cout << temp << endl;
	
	bool flag = isNumeric(temp);
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");	
	return 0;
}

