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

// 字符串的翻转
// "“student. a am I”"--->"I am a student."
using namespace std;

string ReverseSentence(string str)
{
	string res = "";
	string temp = "";
	
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] == ' ')
		{
			res = " " + temp + res;
			temp = "";
		}
		else
			temp += str[i];
	}
	if(temp.size())
		res = temp + res;
	return res;	
}


int main()
{
	string originalStr;
	// 注意包含空格符号的字符串的输入
	getline(cin, originalStr);
	
	string reverseStr;
	reverseStr = ReverseSentence(originalStr);
	cout << reverseStr << endl;
	
	return 0;
}

