#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double fbnc(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fbnc(n - 1) + fbnc(n - 2);
}
int main() {
	int n = 0;
	printf("请输入斐波那契数列中n的值：");
	scanf("%d", &n);
	if (n < 0) printf("数列中n的值必须为非负整数！\n");
	else printf("斐波那契数列F(%d)=%lf\n",n,fbnc(n));
	return 0;
}