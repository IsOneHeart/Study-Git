#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	long n;
	printf("请输入一个正整数n：");
	scanf("%ld", &n);
	printf("%d从高位逐渐分离并输出的结果是：",n);
	if (n < 0)
		n = -n;//负数转正数
	if (n == 0)
		printf("0\n");
	else {
		long ten=1;
		while (ten<=n) {
			ten *= 10;//更新ten，使ten成为最小的比n大的十的某整数幂的数以结束循环
		}
		ten /= 10;//使ten成为最大的比n小的十的某整数幂的数来除以n得到n的最高位数
		while (n > 0) {
			int result = n / ten;//分离最高位
			printf("%d", result);
			n %= ten;//去除最高位
			ten /= 10;//更新ten，使其为下个数的十的幂次数
			if ( ten > 0 )
				printf("、");
		}
	}
	return 0;
}