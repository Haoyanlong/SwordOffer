#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

/*
int movingCount(int threshold, int rows, int cols)
{
	if(threshold <= 0)
		return 0;
	if(threshold == 1)
		return 3;
	if(rows == 0 || cols == 0)
		return 0;
	int count = 0;
	for(int i = 0; i < rows; i++)
	{
		printf("i:%d\n", i);
		int rows_right = i % 10;
		int rows_left = i / 10;
          
		for(int j = 0; j < cols; j++)
		{
			int cols_right = j % 10;
			int cols_left = j / 10;
               
			int add = rows_right + rows_left + cols_right + cols_left;
			if(add <= threshold)
			{
				count++;
				printf("%d\n", j);
			}
				
		}
	}
	return count;
}
*/
int getsum(int num)
{
	// 该函数求数值num上的各个数位上的数字之和
	int count = 0;
	while(num)
	{
		count += num % 10;
		num /= 10;
	}
	return count;
}

int moving(int threshold, int rows, int cols, int i, int j, bool * flag)
{	
	int count = 0;
	if(i >= 0 && i < rows && j >= 0 && j <= cols && getsum(i) + getsum(j) <= threshold && flag[i * cols + j] == false)
	{
		flag[i * cols + j] = true;
		count = 1 + moving(threshold, rows, cols, i-1, j, flag)
		          + moving(threshold, rows, cols, i, j-1, flag)
		          + moving(threshold, rows, cols, i+1, j, flag)
		          + moving(threshold, rows, cols, i, j+1, flag);
	
	}
	return count;
}



int movingCount(int threshold, int rows, int cols)
{
	// vector<bool> flag(rows * cols, false);
	bool * flag = new bool[rows * cols];
	for(int i = 0; i < rows * cols; i++)
		flag[i] = false;
	int count = moving(threshold, rows, cols, 0, 0, flag);
	return count;
}


int main()
{
	
	int threshold = 10;
	int rows = 1;
	int cols = 100;
	int count = movingCount(threshold, rows, cols);
	printf("%d\n", count);

	// int temp = 123456;
	// int count = getsum(temp);
	// printf("%d\n", count);

	return 0;
}

