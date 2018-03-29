#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>

// 连续子数组的和最大

using namespace std;

// 方法1: 采用分治策略
int FindGreatestSumOfCrossing(vector<int> array, int low, int mid, int high)
{
	// vector<int> temp;
	int left_sum = -100;
	int max_left = mid;
	int sum = 0;
	for(int i = mid; i >= low; i--)
	{
		sum += array[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			max_left = i;	
		}
	}
	// temp.push_back(max_left);
	int right_sum = -100;
	int max_right = mid;
	sum = 0;
	for(int i = mid + 1; i < high; i++)
	{
		sum += array[i];
		if(sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	} 
	// temp.push_back(max_right);
	// temp.push_back(left_sum + right_sum);
	return left_sum+right_sum;
}

int FindGreatestSumOfSubArray(vector<int> array, int low, int high)
{
	if(high == low)
		return array[0];
	else
	{
		int mid = high >> 1;
		int left_max = FindGreatestSumOfSubArray(array, low, mid);
		int right_max = FindGreatestSumOfSubArray(array, mid+1, high);
		int cross_max = FindGreatestSumOfCrossing(array, low, mid, high);
		
		int maxValue = left_max > right_max ? left_max : right_max;
		maxValue = maxValue > cross_max ? maxValue: cross_max;
		return maxValue;
	}
}

// 方法2: 采用动态规划的思想
int FindGreatestSumOfSubArray1(vector<int> array)
{
	int cursum = array[0];   // 包含array[i]的最大值
	int maxsum = array[0];   // 记录当前所有子数组的和的最大值
	for(int i = 1; i < array.size(); i++)
	{
		cursum += array[i];
		if(cursum < array[i])
			cursum = array[i];
		if(maxsum < cursum)
			maxsum = cursum;
	}
	return maxsum;
}


int main()
{
	int nums[8] = {6, -3, -2, 7, -15, 1, 2, 2};
	vector<int> array(nums, nums+8);
	
	int maxvalue = FindGreatestSumOfSubArray1(array);
	printf("%d\n", maxvalue);
	return 0;
}

