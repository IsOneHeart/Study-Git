#include <stdio.h>
#include <stdlib.h>

struct info {
	union num {
		long numS;
		long NoT;
	}num;
	char name[10];
	char sex;
	char ident;
	union CoP {
		char class[10];
		char position[10];
	}CoP;
	struct info* next;
};

struct info* infoFun(int n) {
	struct info* information = NULL, * head = NULL, * p = NULL;
	getchar();
	for (int i = 0;i < n;i++) {
		if ((information = ((struct info*)malloc(sizeof(struct info)))) == NULL) {
			printf("内存块分配失败！");
			exit(0);
		}
		printf("第%d个学生/教师:\n", i + 1);//用户输入节点数据
		printf("身份：(s/t)");
		scanf_s("%c", &(information->ident));
		printf("姓名：");
		getchar();
		gets(information->name);
		printf("性别：(f/m)");
		scanf_s("%c", &(information->sex));
		if (information->ident == 's') {
			printf("学号：");
			scanf_s("%ld", &(information->num.numS));
			printf("班级：");
			getchar();
			gets(information->CoP.class);
		}
		else if (information->ident == 't') {
			printf("编号：");
			scanf_s("%ld", &(information->num.NoT));
			printf("职称：");
			getchar();
			gets(information->CoP.position);
		}
		else {
			printf("身份错误！\n");
			exit(0);
		}
		information->next = NULL;//初始化节点的下一个指针
		if (i == 0) {
			head = information;//将节点加入链表
			p = head;
		}
		else {
			p->next = information;
			p = information;
		}
	}
	return head;
}

void main() {
	printf("请输入总人数：");
	int n;
	scanf_s("%d", &n);
	struct info* head = infoFun(n);
	printf("======信息列表======\n");
	printf("%-5s%-5s%-5s%-5s%-5s\n", "num", "name", "sex", "job", "class/position");
	struct info* p = head;
	while (p != NULL) {
		if (p->ident == 's')
			printf("%-5ld%-5s%-5c%-5c%-5s\n", p->num.numS, p->name, p->sex, p->ident, p->CoP.class);
		else
			printf("%-5ld%-5s%-5c%-5c%-5s\n", p->num.NoT, p->name, p->sex, p->ident, p->CoP.position);
		p = p->next;
	}
}