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
		printf("�ڴ�����ʧ�ܣ�");
		exit(0);
	}
	head = NULL;
	p = head;
	for (int i = 0;i < n;i++) {
		printf("��%d��ѧ����\n", i + 1);
		printf("ѧ�ţ�");
		scanf("%ld", &(stu->num));
		printf("������");
		getchar();
		gets(stu->name);
		/*fgets(stu[i].name, sizeof(stu[i].name), stdin);*/
		printf("�ɼ���");
		scanf("%f", &(stu->mark));
		/*��ͷ�巨������̬����*/
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
		printf("��������Ϊ��");
		getchar();
		gets(p1->name);
		printf("���ĳɼ�Ϊ��");
		scanf("%f", &(p1->mark));
		printf("������ɣ�");
	}
}

int main() {
	printf("������������n��");
	int n;
	scanf("%d", &n);
	if (n <= 0) {
		printf("n��Ϊ��������");
		exit(0);
	}
	student* head = insert_link_table(n);
	printf("�Ƿ���Ҫ�޸������ش���/�񣩣�");
	char ifChange[3];
	scanf("%s", &ifChange);
	if (strcmp(ifChange,"��") == 0) {
		int numC;
		printf("������Ҫ�޸ĵ�ѧ����Ϣ��Ӧ��ѧ�ţ�");
		scanf("%d", &numC);
		edit_link_table(head, numC);
	}
	else
		printf("���������");
	return 0;
}