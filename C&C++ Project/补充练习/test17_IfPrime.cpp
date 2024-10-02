#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int num) {//定义函数isPrime
	if (num <= 1) return 0;//不是素数
	for (int i = 2;i < num;i++) {
		if (num % i == 0) {
			return 0;//不是素数
		}
	}
	return 1;//是素数
}
int main()
{
	int num = 0;
	printf("请输入一个正整数:");
	scanf("%d", &num);
	if (isPrime(num)) //使用函数Prime
		printf("%d是素数。",num);
	else printf("%d不是素数。",num);
	return 0;
}