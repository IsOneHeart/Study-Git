#include <stdio.h>
int main()
{
	int i,n, sum = 0, count = 0, average = 0;
	if (n <= 0) {
		printf("输入的数应为正整数。\n");
	}
	else {
		for (i = 0;i <= 100;i++)
		{
			if (i % 2 != 0)
			{
				sum = sum + i;
				count = count + 1;
			}
		}
	}
	average = sum / count;
	printf("count=%d\nsum=%d\naverage=%d\n", count, sum,average);
		return 0;
}