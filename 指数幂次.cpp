#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

double Power(double base, int exponent)
{
	long long p = abs((long long)exponent);
	double r = 1.0;
	
	while(p)
	{	
		if(p & 1) r *= base;
		base *= base;
		p >>= 1;
	}
	return exponent < 0 ? 1/r:r;
}

int main()
{
	double res = Power(2.0, 4);
	printf("%f\n", res);
	return 0;
}

