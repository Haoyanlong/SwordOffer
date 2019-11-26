#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>

// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

using namespace std;
vector<string> result;

void Permutation1(string str, int begin)
{
	if(begin == str.length())
	{
		result.push_back(str);
		return;
	}
	for(int i = begin; str[i] != '\0'; i++)   // 遍历第begin位的所有可能性
	{
		if(i != begin && str[begin] == str[i])
			continue;
		swap(str[begin], str[i]);           
		Permutation1(str, begin+1);           // 遍历后面的所有字符
		swap(str[begin], str[i]);
	}
}


vector<string> Permutation(string str)
{
	if(str.length() == 0)
		return result;
	
	Permutation1(str, 0);
	sort(result.begin(), result.end());
	return result;
}

int main()
{
	string str = "abc";
	result = Permutation(str);
	for(vector<string>::iterator it = result.begin(); it != result.end(); it++ )
		cout << *it << endl; 
	return 0;
}
