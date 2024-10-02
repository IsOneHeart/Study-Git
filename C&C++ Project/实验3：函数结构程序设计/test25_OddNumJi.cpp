#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fun(int n) {
	if (n == 1) return 1;
	return (2 * n - 1) * fun(n - 1);
}
int main() {
	int n;
	printf("求t=1*3*5*7*…*(2n-1)的值\n请输入n的值：");
	scanf("%d", &n);
	printf("1*3*...*%d的值：%d\n", 2*n-1,fun(n));
	return 0;
}