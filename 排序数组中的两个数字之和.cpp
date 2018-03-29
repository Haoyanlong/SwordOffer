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

// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的

// 乘积最小意思就是两个值的差值最大,从头到尾计算两个数的和，如果大于给定值，则尾部朝前移动，否则头朝后移动
// 如果相等则跳出循环此时找到的两个值就是乘积最大的
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
	vector<int> res;
	int len = array.size();
	int begin = 0;
	int end = len - 1;
	int temp;
	while(begin < end)
	{
		temp = array[begin] + array[end];
		if(temp < sum)
			begin++;
		else if(temp > sum)
			end--;
		else
		{
			res.push_back(array[begin]);
			res.push_back(array[end]);
			break;
		}
	}
	return res;
}

int main()
{
	int N;
	scanf("%d", &N);
	int test_data[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &test_data[i]);
	int sum;
	scanf("%d", &sum);
	vector<int> test_dataV(test_data, test_data+N);
	
	vector<int> res;
	res =  FindNumbersWithSum(test_dataV, sum);
	
	for(int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	return 0;
}

