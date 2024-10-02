#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int MaxR(int num1, int num2) {//辗转相除法求最大公约数
	if (num2 == 0) return num1;
	return MaxR(num2, num1 % num2);
}
int MinR(int num1, int num2) {//两数积除最大公约数求最小公倍数
	int MaxR(int num1, int num2);
	return (num1 * num2) / MaxR(num1, num2);
}
int main() {
	int num1 = 0, num2 = 0;
	printf("请输入两个非负整数：");
	scanf("%d %d", &num1, &num2);
	if (num1 < 0 || num2 < 0) printf("请输入非负整数!");
	else {
		printf("%d和%d的最大公约数为%d\n", num1, num2, MaxR(num1, num2));
		printf("%d和%d的最小公倍数为%d\n", num1, num2, MinR(num1, num2));
	}
	return 0;
}