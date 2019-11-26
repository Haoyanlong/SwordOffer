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

// 统计数组中的逆序对(归并排序)

using namespace std;

long InversePairsCore(vector<int> & data, vector<int> & copy, long start, long end)
{
	// copy是辅助数组
	if(start == end)
	{
		return 0;              // 递归终止条件
	}
	long length = (end - start) / 2;
	
	long left = InversePairsCore(copy, data, start, start+length);   // 递归，归并排序并计算本次逆序对数
	long right = InversePairsCore(copy, data, start+length+1, end);
	
	long crossCount = 0;      // 记录交叉的逆序对数
	
	long i = start + length, j = end, temp = end;       // i:前半部分的下标, j: 后半部分的下标, temp:辅助数组的下标
	while(i >= start && j >= start + length + 1)        // 存在交叉的逆序对，先统计一下，然后依次将较大值放进辅助数组里
	{
		if(data[i] > data[j])
		{
			copy[temp--] = data[i--];
			crossCount += j - start - length;
		}
		else
		{
			copy[temp--] = data[j--];                   // 不存在交叉的逆序对，依次将较大值放进辅助数组
		}
	}
	while(i >= start)
	{
		copy[temp--] = data[i--];
	}
	while(j >= start + length + 1)
	{
		copy[temp--] = data[j--];
	}
	
	return (left + right + crossCount) % 1000000007;    // 数值过大防止溢出
}

int InversePairs(vector<int> & data)
{
	if(data.size() == 0) return 0;
	else if(data.size() == 1) return 1;
	else
	{
		vector<int> copy(data);
		return InversePairsCore(copy, data, 0, data.size() - 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int numbers[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);
	vector<int> data(numbers, numbers+8);
	// for(int i = 0; i < data.size(); i++)
	// 	printf("%d ", data[i]);
	// printf("\n");
	int inverseNum = InversePairs(data);
	printf("%d\n", inverseNum);
	return 0;
}


