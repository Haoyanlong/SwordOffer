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

// 数据流的中位数
using namespace std;

vector<int> v;
int n;

void Insert(int num)
{
	v.push_back(num);
	int len = v.size();
	// 每次插入进来一个数进行排序
	for(int i = len - 1; i > 0 && v[i] < v[i-1]; --i)
		swap(v[i], v[i-1]);
}

double GetMedia()
{
	return (v[(n -1) >> 1] + v[n >> 1]) / 2.0;
}

int main()
{
	scanf("%d", &n);
	int temp;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		Insert(temp);
	}
	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	double middleNum = GetMedia();
	printf("%f\n", middleNum);	
	return 0;
}


