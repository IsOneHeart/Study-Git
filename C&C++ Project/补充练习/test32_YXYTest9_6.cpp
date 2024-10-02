#include <stdio.h>
void main()
{
	int a, k = 4, m = 6, *p1 = &k, *p2 = &m;
	a = p1 == &m;
	printf("%d\n", a);
}