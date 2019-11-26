#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<stack>

// 根据输入的数组判断是否是二叉搜索树的后序遍历
/*
二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树
*/
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	}
};

/*
方法1: 
左子树一定比右子树小，因此，去掉根后，数字分为left, right两部分, right部分的最后一个数字
是右子树的根，它也比左子树所有值大，因此可以每次只看所有子树是否符合条件
即使到了左子树，也可以看成有左右子树组成的树
*/
bool VerifySquenceOfBST1(vector<int> sequence)
{
	int length = sequence.size();
	if(length == 0)
		return false;
	int i = 0;
	while(--length)
	{
		while(sequence[i++] < sequence[length]);
		while(sequence[i++] > sequence[length]);
		if(i < length)
			return false;
		i = 0;
	}
	return true;
}
/*
方法2:
取出序列的最后一个值也就是根节点的值将树分为left和right;递归再次进行判断.
*/
bool isLastOrder(vector<int> sequence, int begin, int end)
{
	if(begin == end)
		return true;
	int mid = begin;
	while(sequence[mid++] < sequence[end] && mid < end);
	int tmp = mid;
	while(sequence[tmp++] > sequence[end] && tmp < end);
	if(tmp < end)
		return false;
	if(mid == begin || mid == end)
	{
		return isLastOrder(sequence, begin, end-1);
	}
	else
	{
		return (isLastOrder(sequence, begin, mid - 1) && isLastOrder(sequence, mid, end - 1));
	}
}

bool VerifySquenceOfBST2(vector<int> sequence)
{
	int size = sequence.size();
	if(0 == size)
	{
		return false;
	}
	return isLastOrder(sequence, 0, size - 1);
}


int main()
{
	int temp[] = {1, 4, 3, 7, 9, 8};
	vector<int> test(temp, temp+6);
	bool YesNo = VerifySquenceOfBST2(test);
	if(YesNo)
		printf("YES\n");
		
	return 0;
}

