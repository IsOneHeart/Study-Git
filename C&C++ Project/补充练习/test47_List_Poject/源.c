#include "datalink.h"

void main() {
	printf("������Ҫ������ڴ�����n��");
	int n;
	scanf("%d", &n);
	link_type* head = setlnk(n);//��������
	printf("����\n");
	prilnk(head);
	int N1, N2;

	printf("������Ҫɾ���Ľڵ㣺");
	scanf("%d", &N1);
	head = dellnk(head, N1);
	printf("����\n");
	prilnk(head);
	printf("������Ҫ����Ľڵ�λ�ã�");
	scanf("%d", &N2);
	head = inslnk(head, N2);
	printf("����\n");
	prilnk(head);
	/*
	printf("����\n");
	asclnk(head);
	prilnk(head);
	printf("����\n");
	deslnk(head);
	prilnk(head);
	printf("������Ҫ������ڴ�����n��");
	int n2;
	scanf("%d", &n2);
	link_type* head2 = setlnk(n2);//��������
	printf("����\n");
	prilnk(head2);
	printf("����\n");
	conlnk(head, head2);
	prilnk(head);
	prilnk(head2);
	*/
	frelnk(head);
}