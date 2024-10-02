#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	printf("请输入学生总人数（正整数）：");
	scanf("%d", &n);
	int mark=0,sum = 0, countA = 0, countB = 0, countC = 0, countD = 0, countE = 0;
	printf("请输入%d个学生的成绩（用空格分隔）：", n);
	for (int i = 1;i <= n; i++ ){
		scanf("%d",&mark);
		sum += mark;
		//根据成绩等级统计人数
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
			printf("输入的数超出范围！");
	}
	printf("平均分=%.2f\n", (float)sum / n);
	printf("A级人数=%d,B级人数=%d,C级人数=%d,D级人数=%d,E级人数=%d",countA,countB,countC,countD,countE);
	return 0;
}