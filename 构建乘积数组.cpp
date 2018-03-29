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

// 构建乘积数组

using namespace std;

vector<int> multiply1(const vector<int> & A)
{
	int len = A.size();
	vector<int> B(len, 1);
	if(len <= 0) return B;
	int temp = 0;
	while(temp != len)
	{
		B[temp] = 1;
		for(int i = 0; i < len; i++)
		{
			if(i != temp)
				B[temp] *= A[i];
		}
		temp++;
	}
	return B;
}

vector<int> multiply2(const vector<int> & A)
{
	int len = A.size();
	vector<int> B;
	if(len != 0)
	{
		B[0] = 1;
		// 计算下三角连乘
		for(int i = 1; i < length; i++)
			B[i] = B[i-1] * A[i-1];
		int temp = 1;
		// 计算上三角
		for(int j = len - 2; j >= 0; j--)
		{
			temp *= A[j+1];
			B[j] *= temp;
		}
	}
	return B;
}


