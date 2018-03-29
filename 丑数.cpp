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


int min(int x, int y, int z)
{
	int minValue = x < y ? x : y;
	minValue = minValue < z ? minValue : z;
	return minValue; 
}

int GetUglyNumber_Solution(int index)
{
	if(index < 7)
		return index;
	vector<int> res(index);
	res[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0, i;
	for(i = 1; i < index; i++)
	{
		printf("%d %d %d\n", res[t2] * 2, res[t3] * 3, res[t5] * 5);
		res[i] = min(res[t2] * 2, res[t3] * 3, res[t5] * 5);
		if(res[i] == res[t2] * 2)
			t2++;
		if(res[i] == res[t3] * 3)
			t3++;
		if(res[i] == res[t5] * 5)
			t5++;	
	}
	return res[index - 1];
}

int main()
{
	int n;
	scanf("%d", &n);
	int ugly_number = GetUglyNumber_Solution(n);
	printf("%d\n", ugly_number);
	return 0;
}

