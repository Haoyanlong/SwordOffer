#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

class Solution {
public:
    // 选择从左下角开始搜寻，如果大于就向右，小于就向左。
    bool Find(int target, vector<vector<int> > array) 
    {
        int len = array.size() - 1;
        int i = 0;
        while((len >= 0) && (i < array[0].size()))
        {
            if(array[len][i] > target)
            {
                len--;
            }
            else if(array[len][i] < target)
            {
                i++;
            }
            else 
                return true;
        }
        return false;
    }
    // 二分查找法
	bool Find(int target, vector<vector<int> > array)
	{
		for(int i = 0; i < array.size(); i++)
		{
			int low = 0;
			int hight = array[i].size() - 1;
			while(low <= high)
			{
				int mid = (low + high) / 2;
				if(target > array[i][mid]
					low = mid + 1;
				else(target < array[i][mid]
					high = mid - 1;
				else
					return true;
			}
		}
		return false;
	}
};

