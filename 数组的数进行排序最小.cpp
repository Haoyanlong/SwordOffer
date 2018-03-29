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

// 输入一个正整数数组，把数组所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
// 例如输入数组{3, 32, 321}, 则打印出这三个数字能排成的最小数字为321323
using namespace std;

// 通过定义一种cmp来返回ab < ba
bool cmp(string a, string b)
{
	string A = a + b;
	string B = b + a;
	return A < B;
}

string num2str(int numbers)
{
	stringstream ss;
	ss<<numbers;
	return ss.str();
}

string PrintMinNumber(vector<int> numbers) 
{
	string result;
	sort(numbers.begin(), numbers.end(), cmp);
	for(int i = 0; i < numbers.size(); i++)
	{
		result += num2str(numbers[i]);
	}
	return result;
}

int main()
{
	// int nums[] = {3, 32, 321};
	// vector<int> numbers(nums, nums+3);
	// string str = PrintMinNumber(numbers);
	
	// cout << str << endl;
	return 0;
}


