#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float mark;
	printf("请输入百分制成绩（请确保输入的数为0-100内的数）：");
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
	printf("对应的五级制成绩为%c。",grade);
	return 0;
}