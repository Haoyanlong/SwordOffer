#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

// 在旋转数组中寻找最小的值
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) 
{
	int len = rotateArray.size();
	if(len == 0)
		return 0;
	
	for(int i = 0; i < len - 1; i++)
	{
		if(rotateArray[i] > rotateArray[i+1])
			return rotateArray[i+1];
	}
}

int main()
{
	int temp[10] = {3, 4, 5, 6, 7, 8, 2};
	vector<int> x(temp, temp+10);
	
	int output = minNumberInRotateArray(x);
	printf("%d\n", output); 
	return 0;
}

