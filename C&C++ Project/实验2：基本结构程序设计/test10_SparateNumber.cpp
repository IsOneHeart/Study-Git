#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	long n;
	printf("������һ��������n��");
	scanf("%ld", &n);
	printf("%d�Ӹ�λ�𽥷��벢����Ľ���ǣ�",n);
	if (n < 0)
		n = -n;//����ת����
	if (n == 0)
		printf("0\n");
	else {
		long ten=1;
		while (ten<=n) {
			ten *= 10;//����ten��ʹten��Ϊ��С�ı�n���ʮ��ĳ�����ݵ����Խ���ѭ��
		}
		ten /= 10;//ʹten��Ϊ���ı�nС��ʮ��ĳ�����ݵ���������n�õ�n�����λ��
		while (n > 0) {
			int result = n / ten;//�������λ
			printf("%d", result);
			n %= ten;//ȥ�����λ
			ten /= 10;//����ten��ʹ��Ϊ�¸�����ʮ���ݴ���
			if ( ten > 0 )
				printf("��");
		}
	}
	return 0;
}