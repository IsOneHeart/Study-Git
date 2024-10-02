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
	int count = 0;
	printf("100内的素数有：");
	for (int num = 2;num < 100;num++) {
		if (isPrime(num)) {//使用函数Prime
			printf("%d,", num);
			count++;
		}
	}
	printf("\n共%d个", count);
	return 0;
}