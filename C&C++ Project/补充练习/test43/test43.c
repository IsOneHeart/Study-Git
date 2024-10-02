#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct StuInf {/*定义学生结构体*/
	long num;
	char name[10];
	float mark;
	struct StuInf* next;//指向下一个节点
}student;

int main(){
	printf("请输入学生数量n(n<=10)：");/*输入与判断n值*/
	int n;
	scanf("%d", &n);
	if (n <= 0 || n > MaxSize) {
		printf("n值溢出，程序结束\n");
		return 0;
	}
	else
		printf("请输入%d个学生的信息：\n",n);

	/*建立单项链表*/
	student stu[MaxSize], * head, * p;//head：头指针变量，p：循环变量
	head = &stu[0];
	for (int i = 0;i < n - 1;i++) {
		stu[i].next = &stu[i + 1];
		stu[i + 1].next = NULL;
	}

	for (int i = 0;i < n;i++) {/*输入学生信息*/
		printf("第%d个学生：\n", i + 1);
		printf("学号：");
		scanf("%ld", &stu[i].num);
		printf("姓名：");
		while (getchar() != '\n');
		fgets(stu[i].name,sizeof(stu[i].name),stdin);
		if (stu[i].name[strlen(stu[i].name) - 1] == '\n')
			stu[i].name[strlen(stu[i].name) - 1] = '\0';
		printf("成绩：");
		scanf("%f", &stu[i].mark);
	}

	printf("%-5s%-10s%-5s\n", "学号", "    姓名      ", "成绩");/*输出单向链表*/
	for (p = head;p != NULL;p = p->next)
		printf("%-5ld   %-10s%-5.1f\n", p->num, p->name, p->mark);
	return 0;
}