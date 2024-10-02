/*定义学生结构体Student(含学号、姓名、成绩、等级、名次)和统计函数Static，
该函数具有设置等级、计算名次、统计各等级人数和返回平均成绩的功能。
在主函数中输入3个学生的学号、姓名和成绩，调用Static函数完成统计功能，最后输出学生全部信息。
成绩等级规则：大于等于90—A，大于等于80—B，大于等于70—C，大于等于60—D，60以下—E。*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 64
#define NumStudent 10
#include <stdio.h>
struct Student {
	long long No;
	char Name[MaxSize];
	float Mark;
	char Grade;
	int List;
}student[NumStudent];

void Static(struct Student students[]) {
	int count[5] = { 0,0,0,0,0 };
	float sum = 0, aver = 0;
	for (int i = 0;i < NumStudent;i++) {
		switch ((int)students[i].Mark / 10) {
		case 10:
		case 9:
			count[0]++;
			students[i].Grade = 'A';
			break;
		case 8:
			count[1]++;
			students[i].Grade = 'B';
			break;
		case 7:
			count[2]++;
			students[i].Grade = 'C';
			break;
		case 6:
			count[3]++;
			students[i].Grade = 'D';
			break;
		default:
			count[4]++;
			students[i].Grade = 'E';
			break;
		}
	}
	printf("A等级%d人，B等级%d人，C等级%d人，D等级%d人，E等级%d人\n", count[0], count[1], count[2], count[3], count[4]);

	struct Student temp;
	for (int i = 0;i < NumStudent;i++) {
		for (int j = 0;j < NumStudent - i;j++) {
			if (students[j].Mark < students[j + 1].Mark) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	//处理并列排名
	for (int i = 0;i < NumStudent;i++) {
		students[i].List = i + 1;
		if (i > 0 && students[i].Mark == students[i - 1].Mark) 
			students[i].List = students[i - 1].List;
	}

	printf("排名\t姓名\t学号\t分数\t等级\n");
	for (int i = 0;i < NumStudent;i++) {
		printf("第%d名\t%s\t%lld\t%.2f\t%c\n", students[i].List, students[i].Name, students[i].No, students[i].Mark, students[i].Grade);
		sum += students[i].Mark;
	}

	aver = sum / NumStudent;
	printf("\n平均分：%.2f\n", aver);
}

void main() {
	printf("请输入%d个学生的信息：\n", NumStudent);
	for (int i = 0;i < NumStudent;i++) {
		printf("第%d个学生：\n", i+1);
		printf("学号：");
		scanf("%lld", &student[i].No);
		printf("姓名：");
		getchar();//小号上一次输入的回车符
		gets(student[i].Name);
		printf("成绩：");
		scanf("%f", &student[i].Mark);
	}
	Static(student);
}