#include <stdio.h>
int main()
{
	float tao=1;
	for (int i = 1;i < 10;i++) {
		tao=2*(tao+1);
	}
	printf("���ӵ�һ�칲ժ��%.0f����",tao);
	return 0;
}