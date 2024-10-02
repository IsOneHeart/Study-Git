#include <stdio.h>
int main()
{
	float tao=1;
	for (int i = 1;i < 10;i++) {
		tao=2*(tao+1);
	}
	printf("猴子第一天共摘了%.0f颗桃",tao);
	return 0;
}