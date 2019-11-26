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

// 和为定值的连续正整数序列
using namespace std;

void InsertRes(int begin, int end, vector<vector<int> > & res)
{
	vector<int> temp;
	for(int i = begin; i <= end; i++)
		temp.push_back(i);
	res.push_back(temp);
}

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > res;
	if(sum < 3) return res;
	
	int mid = (sum + 1) >> 1;
	int begin = 1;
	int end = 2;
	int cur = begin + end;
	while(begin < mid && end < sum)
	{
		while(cur > sum)
		{
			cur -= begin;
			begin++;
		}
		if(cur == sum)
			InsertRes(begin, end, res);
		end++;
		cur += end;
	}
	return res;
}

int main()
{
	int sum;
	scanf("%d", &sum);
	
	vector<vector<int> > answer;
	answer = FindContinuousSequence(sum);
	for(int i = 0; i < answer.size(); i++)
	{
		for(int j = 0; j < answer[i].size(); j++)
			printf("%d ", answer[i][j]);
		printf("\n"); 
	}

	return 0;
}

