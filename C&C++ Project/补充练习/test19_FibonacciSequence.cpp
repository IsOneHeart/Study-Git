#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double fbnc(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fbnc(n - 1) + fbnc(n - 2);
}
int main() {
	int n = 0;
	printf("������쳲�����������n��ֵ��");
	scanf("%d", &n);
	if (n < 0) printf("������n��ֵ����Ϊ�Ǹ�������\n");
	else printf("쳲���������F(%d)=%lf\n",n,fbnc(n));
	return 0;
}