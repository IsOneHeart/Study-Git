#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double x=0.0,y=0.0;
	printf("请输入x的值：");
	scanf("%lf", &x);
	if (x < 0)
	{
		y = pow(x, 5) + 2.0 * x + 1.0 / x;
	}
	else
	{
		y = sqrt(x);
	}
	printf("当x=%.2lf时，y=%.2lf",x, y);
	return 0;
}