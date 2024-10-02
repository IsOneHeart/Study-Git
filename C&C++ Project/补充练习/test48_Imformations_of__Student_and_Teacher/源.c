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
			printf("�ڴ�����ʧ�ܣ�");
			exit(0);
		}
		printf("��%d��ѧ��/��ʦ:\n", i + 1);//�û�����ڵ�����
		printf("��ݣ�(s/t)");
		scanf_s("%c", &(information->ident));
		printf("������");
		getchar();
		gets(information->name);
		printf("�Ա�(f/m)");
		scanf_s("%c", &(information->sex));
		if (information->ident == 's') {
			printf("ѧ�ţ�");
			scanf_s("%ld", &(information->num.numS));
			printf("�༶��");
			getchar();
			gets(information->CoP.class);
		}
		else if (information->ident == 't') {
			printf("��ţ�");
			scanf_s("%ld", &(information->num.NoT));
			printf("ְ�ƣ�");
			getchar();
			gets(information->CoP.position);
		}
		else {
			printf("��ݴ���\n");
			exit(0);
		}
		information->next = NULL;//��ʼ���ڵ����һ��ָ��
		if (i == 0) {
			head = information;//���ڵ��������
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
	printf("��������������");
	int n;
	scanf_s("%d", &n);
	struct info* head = infoFun(n);
	printf("======��Ϣ�б�======\n");
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