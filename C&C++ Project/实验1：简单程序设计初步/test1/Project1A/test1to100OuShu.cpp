#include <stdio.h>			/* ����Ԥ�������� */
int main()
{
	int i, sum=0;				/* i��ѭ��������sum���ͱ��� */

	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum = sum + i;	/* ���i��ż�����ۼ�i */
	}
		printf("sum=%d\n", sum);/* ����ۼӺ�sum */
		return 0;
}