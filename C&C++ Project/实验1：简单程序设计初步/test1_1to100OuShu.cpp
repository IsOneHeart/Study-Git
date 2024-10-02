#include <stdio.h>			/* 编译预处理命令 */
int main()
{
	int i, sum=0;				/* i：循环变量，sum：和变量 */

	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum = sum + i;	/* 如果i是偶数则累加i */
	}
		printf("sum=%d\n", sum);/* 输出累加和sum */
		return 0;
}