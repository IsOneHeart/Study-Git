#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct StuInf {/*����ѧ���ṹ��*/
	long num;
	char name[10];
	float mark;
	struct StuInf* next;//ָ����һ���ڵ�
}student;

int main(){
	printf("������ѧ������n(n<=10)��");/*�������ж�nֵ*/
	int n;
	scanf("%d", &n);
	if (n <= 0 || n > MaxSize) {
		printf("nֵ������������\n");
		return 0;
	}
	else
		printf("������%d��ѧ������Ϣ��\n",n);

	/*������������*/
	student stu[MaxSize], * head, * p;//head��ͷָ�������p��ѭ������
	head = &stu[0];
	for (int i = 0;i < n - 1;i++) {
		stu[i].next = &stu[i + 1];
		stu[i + 1].next = NULL;
	}

	for (int i = 0;i < n;i++) {/*����ѧ����Ϣ*/
		printf("��%d��ѧ����\n", i + 1);
		printf("ѧ�ţ�");
		scanf("%ld", &stu[i].num);
		printf("������");
		while (getchar() != '\n');
		fgets(stu[i].name,sizeof(stu[i].name),stdin);
		if (stu[i].name[strlen(stu[i].name) - 1] == '\n')
			stu[i].name[strlen(stu[i].name) - 1] = '\0';
		printf("�ɼ���");
		scanf("%f", &stu[i].mark);
	}

	printf("%-5s%-10s%-5s\n", "ѧ��", "    ����      ", "�ɼ�");/*�����������*/
	for (p = head;p != NULL;p = p->next)
		printf("%-5ld   %-10s%-5.1f\n", p->num, p->name, p->mark);
	return 0;
}