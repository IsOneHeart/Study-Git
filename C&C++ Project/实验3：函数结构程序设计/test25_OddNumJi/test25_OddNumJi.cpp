#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fun(int n) {
	if (n == 1) return 1;
	return (2 * n - 1) * fun(n - 1);
}
int main() {
	int n;
	printf("��t=1*3*5*7*��*(2n-1)��ֵ\n������n��ֵ��");
	scanf("%d", &n);
	printf("1*3*...*%d��ֵ��%d\n", 2*n-1,fun(n));
	return 0;
}