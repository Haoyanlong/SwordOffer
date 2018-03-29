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

// 序列化和反序列化二叉树
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x):val(x), left(NULL), right(NULL)
	{
	}
};


/*
1.对于序列化: 使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的节点不为空时，
在转化val所得的字符之后添加一个','作为分隔符,对于空节点则以'#'代替;
2.对于反序列化: 按照前序顺序，递归的使用字符串中的字符创建一个二叉树
(特别注意:在递归时，递归函数的参数一定要是char **, 这样才能保证每次递归后指向字符串的指针会随着递归的
进行而移动).
*/
		
char * Serialize(TreeNode * root)
{
	if(root == NULL)
		return NULL;
		
	string str;
	Serialize(root, str);
	char * ret = new char[str.length() + 1];
	int i;
	for(i = 0; i < str.length(); i++)
		ret[i] = str[i];
	ret[i] = '\0';
	return ret;
}
		
void Serialize(TreeNode * root, string & str)
{
	if(root == NULL)
	{
		str += '#';
		return;
	}
	string r = to_string(root->val);
	str += r;
	str += ',';
	Serialize(root->left, str);
	Serialize(root->right, str);
}
		
TreeNode * Deserialize(char * str)
{
	if(str == NULL)
		return NULL;
			
	TreeNode * ret = Deserialize(&str);
	return ret;
}

TreeNode * Deserialize(char ** str)
{
	// 由于递归时，会不断的向后读取字符串，所以一定要用**str,
	//　以保证得到递归后指针str指向未被读取的字符
	if(**str == '#')
	{
		++(*str);
		return NULL;
	}
	int num = 0;
	while(**str != '\0' && **str != ',')
	{
		num = num * 10 + ((**str) - '0');
		++(*str);
	}
	TreeNode * root = new TreeNode(num);
	if(**str == '\0')
		return root;
	else
		(*str)++;
	root->left = Deserialize(str);
	root->right = Deserialize(str);
	return root;
}


