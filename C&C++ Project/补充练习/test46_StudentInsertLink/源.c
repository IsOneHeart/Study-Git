#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 10

typedef struct student {
	long num;
	char name[MaxSize];
	float mark;
	struct student* next;
}student;

student* insert_link_table(int n) {
	student* stu, * head, * p;
	if ((stu = (student*)malloc(n * sizeof(student))) == NULL) {
		printf("内存块分配失败！");
		exit(0);
	}
	head = NULL;
	p = head;
	for (int i = 0;i < n;i++) {
		printf("第%d个学生：\n", i + 1);
		printf("学号：");
		scanf("%ld", &(stu->num));
		printf("姓名：");
		getchar();
		gets(stu->name);
		/*fgets(stu[i].name, sizeof(stu[i].name), stdin);*/
		printf("成绩：");
		scanf("%f", &(stu->mark));
		/*用头插法建立动态链表*/
		stu->next = head;
		head = stu;
	}
	return head;
}

void edit_link_table(student* head, int num) {
	student* p1 = head, * p2 = head;
	while ((p1->num != num) && (p1->next != NULL)) {
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num == num) {
		printf("更改姓名为：");
		getchar();
		gets(p1->name);
		printf("更改成绩为：");
		scanf("%f", &(p1->mark));
		printf("更改完成！");
	}
}

int main() {
	printf("请输入正整数n：");
	int n;
	scanf("%d", &n);
	if (n <= 0) {
		printf("n需为正整数！");
		exit(0);
	}
	student* head = insert_link_table(n);
	printf("是否需要修改链表（回答是/否）：");
	char ifChange[3];
	scanf("%s", &ifChange);
	if (strcmp(ifChange,"是") == 0) {
		int numC;
		printf("请输入要修改的学生信息对应的学号：");
		scanf("%d", &numC);
		edit_link_table(head, numC);
	}
	else
		printf("程序结束！");
	return 0;
}