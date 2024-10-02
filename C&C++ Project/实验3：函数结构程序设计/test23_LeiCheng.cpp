#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fact(int n) {
	if (n == 0 || n == 1) return 1;
	return n * fact(n - 1);
}
int main() {
	int n = 0;
	printf("请输入n的值：");
	scanf("%d", &n);
	printf("t=%d!的值：%d", n, fact(n));
	return 0;
}