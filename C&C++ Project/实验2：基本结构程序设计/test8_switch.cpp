#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float mark;
	printf("������ٷ��Ƴɼ�����ȷ���������Ϊ0-100�ڵ�������");
	scanf("%f", &mark);
	int int_mark = (int)mark;
	char grade;
	switch (int_mark/10) {
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'E';
	}
	printf("��Ӧ���弶�Ƴɼ�Ϊ%c��",grade);
	return 0;
}