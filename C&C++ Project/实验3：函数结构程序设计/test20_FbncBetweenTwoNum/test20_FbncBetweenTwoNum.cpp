#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fib(int n) {
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}
int main() {
	printf("������������������");
	int num1 = 0, num2 = 0;
	scanf("%d %d", &num1, &num2);
	printf("��%d���%d���Fibonacci���ǣ�", num1, num2);
	for (int i = num1;i >= num1 && i <= num2;i++)
		printf("%d ", fib(i));
}