#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int MaxR(int num1, int num2) {//շת����������Լ��
	if (num2 == 0) return num1;
	return MaxR(num2, num1 % num2);
}
int MinR(int num1, int num2) {//�����������Լ������С������
	int MaxR(int num1, int num2);
	return (num1 * num2) / MaxR(num1, num2);
}
int main() {
	int num1 = 0, num2 = 0;
	printf("�����������Ǹ�������");
	scanf("%d %d", &num1, &num2);
	if (num1 < 0 || num2 < 0) printf("������Ǹ�����!");
	else {
		printf("%d��%d�����Լ��Ϊ%d\n", num1, num2, MaxR(num1, num2));
		printf("%d��%d����С������Ϊ%d\n", num1, num2, MinR(num1, num2));
	}
	return 0;
}