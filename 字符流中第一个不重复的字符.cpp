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

const int maxn = 100;
map<char, int> cnt;
deque<char> str;


// 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
// 第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"

void Insert(char ch)
{
	if(!cnt.count(ch))
	{
		cnt[ch] = 1;
		str.push_back(ch);
	}
	else
		cnt[ch]++;
}

// return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
	while(!str.empty() && cnt[str.front()] >= 2)
		str.pop_front();
	if(str.empty())
		return '#';
	return str.front();
}

int main()
{
	char temp[maxn];
	cin >> temp;
	
	for(int i = 0; temp[i] != '\0'; i++)
		Insert(temp[i]);
	
	char result = FirstAppearingOnce();
	
	cout << result << endl;
	return 0;
}

