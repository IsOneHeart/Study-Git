#define _CRT_SECURE_NO_WARNINGS
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
	int num = 0;
	printf("������һ��������:");
	scanf("%d", &num);
	if (isPrime(num)) //ʹ�ú���Prime
		printf("%d��������",num);
	else printf("%d����������",num);
	return 0;
}