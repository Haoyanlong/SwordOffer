#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

void replaceSpace(char * str, int length)
{
	if(str == NULL || length < 0)
		return;
	
	int cntblank = 0;
	int original = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		original++;
		if(str[i] == ' ')
			cntblank++;
	}
	int newlen = original + 2 * cntblank;
	
	while(original > 0 && newlen > original)
	{
		if(str[original] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[original];
		}
		original--;
	}
}

int main()
{
	char str[] = "We Are Happy";
	replaceSpace(str, 100);
	for(int i = 0; str[i] != '\0'; i++)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}



