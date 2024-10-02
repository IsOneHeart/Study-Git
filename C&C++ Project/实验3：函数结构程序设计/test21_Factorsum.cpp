#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int factorsum(int i) {
	int sum = 0;
	for (int t=1;t < i; t++)
		if (i % t == 0) sum += t;
	return sum;
}
int main() {
	int i, m = 0, n = 0;
	printf("请输入正整数m和n：");
	scanf("%d %d", &m, &n);
	printf("%d-%d之间所有的完数为：", m, n);
	for (i = m;i <= n && i >= m;i++) {
		if(i==factorsum(i))
			printf("%d ", factorsum(i));
	}
	return 0;
}