#include <stdio.h>
int isPrime(int num) {//���庯��isPrime
	if (num <= 1) return 0;//��������
	for (int i = 2;i < num;i++) {
		if (num % i == 0) {
			return 0;//��������
		}
	}
	return 1;//������
}
int main()
{
	int count = 0;
	printf("100�ڵ������У�");
	for (int num = 2;num < 100;num++) {
		if (isPrime(num)) {//ʹ�ú���Prime
			printf("%d,", num);
			count++;
		}
	}
	printf("\n��%d��", count);
	return 0;
}