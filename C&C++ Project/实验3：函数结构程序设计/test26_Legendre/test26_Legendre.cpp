#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double fun(int n,int x) {
	if (n == 0) return 1;
	if (n == 1) return x;
	return ((2 * n - 1) * x - fun(n - 1, x) - (n - 1) * fun(n - 2, x)) / n;
}
int main() {
	int n;
	double x;
	printf("�����õ¶���ʽ\n����������n��n>=0)��");
	scanf("%d", &n);
	printf("������һ��ʵ��x��");
	scanf("%lf", &x);
	printf("2�����õ¶���ʽ��ֵ��%.1lf", fun(n,x));
	return 0;
}