#include <stdio.h>
int main()
{
	printf("100���ڵ������У�");
	int count = 0 ,d;
	for (int i = 2; i <= 100 ; i++) {
		int isPrime = 1;//���ʼֵΪ����
		for (d = 2; d < i;d++) {//�Գ���
			if (i % d == 0) {//��������
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {//������
			printf("%d,", i);
			++count;
		}
	}
	printf("\n��%d��", count);
	return 0;
}