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

// 字符串中第一次出现的字符

using namespace std;

int FirstNotRepeatingChar(string str)
{
	int len = str.length();
	if(len == 0) return -1;
	if(len == 1) return 0;
	
	map<char, int> cnt;
	for(int i = 0; i < len; i++)
	{
		if(!cnt.count(str[i]))
			cnt[str[i]] = 1;
		else
			cnt[str[i]]++;
	}
	int ans;
	for(int i = 0; i < len; i++)
	{
		if(cnt[str[i]] == 1)
		{
			ans = i;
			break;
		}
			
	}
	return ans;
}

int main()
{
	string str;
	cin >> str;
	int ans = FirstNotRepeatingChar(str);
	printf("%d\n", ans);
	return 0;
}

