#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int fun(int n) {
	int depNum = 0, result = 0, j = 0, temp = 0;
	while (n != 0) {
	    depNum = n % 10;
	    n /= 10;
		temp = depNum * pow(2, j);
		result += temp;
		j++;
	}
	return result;
}
int main() {
	printf("������һ����������n��");
	int n;
	scanf("%ld", &n);
	printf("%ld��ʮ������Ϊ%d", n, fun(n));
	return 0;
}