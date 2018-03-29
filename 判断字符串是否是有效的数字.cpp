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

// 判断字符串是否是合法的数字
using namespace std;

int StrToInt(string str)
{
	int len = str.length();
	if(len == 0) return 0;
	
	int s = (str[0] == '-' ? -1 : 1);
	int result = 0;
	for(int i = ((str[0] == '-' || str[0] == '+') ? 1 : 0); i < len; i++)
	{
		if(!(str[i] <= '9' || str[i] >= '0'))
			return 0;
		else
		{
			result = result * 10 + (str[i] - '0');
		}
	}
	result = s * result;
	return result;
}

int main()
{
	string originalStr;
	cin >> originalStr;
	
	int strtoInt;
	strtoInt = StrToInt(originalStr);
	printf("%d\n", strtoInt);
	return 0;
}


