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

// 字符串的循环左移
// "abcXYZdef"--->"XYZdefabc"
using namespace std;

string LeftRotateString(string str, int n)
{
	// 取出字符串str中前n个字符组成的字符串
	string subStr = str.substr(0, n);
	
	// 然后从str中删除前n个字符串
	str = str.erase(0, n);
	str += subStr;
	return str;
}

int main()
{
	string originalStr;
	cin >> originalStr;
	
	int n;
	scanf("%d", &n);
	
	string cycleLeftStr;
	cycleLeftStr = LeftRotateString(originalStr, n);
	cout << cycleLeftStr << endl;
	
	return 0;
}


