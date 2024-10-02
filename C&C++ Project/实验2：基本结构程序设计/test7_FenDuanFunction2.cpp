#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double x,y;
	printf("�����빤��x��ֵ��");
	scanf("%lf", &x);
	if (x <= 0) {
		printf("��������ֵ��\n");
		y = 0;
	}
	else if (x>0&&x <= 30000)
		y = 0;
	else if (x > 30000 && x <= 50000)
		y = (x - 30000) * 0.3;
	else if (x > 50000 && x <= 100000)
		y = 20000 * 0.03 + (x - 50000) * 0.06;
	else
		y = 20000 * 0.03 + 50000 * 0.06 + (x - 100000) * 0.1;
	printf("����˰y=%.2lf",y);
	return 0;
}