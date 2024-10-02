#include <stdio.h>
int main()
{
	printf("100以内的素数有：");
	int count = 0 ,d;
	for (int i = 2; i <= 100 ; i++) {
		int isPrime = 1;//设初始值为素数
		for (d = 2; d < i;d++) {//试除法
			if (i % d == 0) {//不是素数
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {//是素数
			printf("%d,", i);
			++count;
		}
	}
	printf("\n共%d个", count);
	return 0;
}