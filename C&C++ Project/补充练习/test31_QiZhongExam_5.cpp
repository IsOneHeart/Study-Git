#include <stdio.h>
int main() {
	int m = 1, n = 1, a = 1, b = 1, c = 1, d = 1;
	(m = a > b) && (n = c > d);
	printf("m=%d,n=%d\n", m, n);
	printf("%d\n", (c > d));
	printf("%d", 0 && 0);
	return 0;
}