#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	printf("������ѧ��������������������");
	scanf("%d", &n);
	int mark=0,sum = 0, countA = 0, countB = 0, countC = 0, countD = 0, countE = 0;
	printf("������%d��ѧ���ĳɼ����ÿո�ָ�����", n);
	for (int i = 1;i <= n; i++ ){
		scanf("%d",&mark);
		sum += mark;
		//���ݳɼ��ȼ�ͳ������
		if (mark >= 90 && mark <= 100)
			countA++;
		else if (mark >= 80 && mark <= 89)
			countB++;
		else if (mark >= 70 && mark <= 79)
			countC++;
		else if (mark >= 60 && mark <= 69)
			countD++;
		else if (mark >= 0 && mark <= 59)
			countE++;
		else
			printf("�������������Χ��");
	}
	printf("ƽ����=%.2f\n", (float)sum / n);
	printf("A������=%d,B������=%d,C������=%d,D������=%d,E������=%d",countA,countB,countC,countD,countE);
	return 0;
}