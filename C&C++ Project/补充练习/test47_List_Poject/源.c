#include "datalink.h"

void main() {
	printf("请输入要分配的内存块个数n：");
	int n;
	scanf("%d", &n);
	link_type* head = setlnk(n);//创建链表
	printf("链表：\n");
	prilnk(head);
	int N1, N2;

	printf("请输入要删除的节点：");
	scanf("%d", &N1);
	head = dellnk(head, N1);
	printf("链表：\n");
	prilnk(head);
	printf("请输入要插入的节点位置：");
	scanf("%d", &N2);
	head = inslnk(head, N2);
	printf("链表：\n");
	prilnk(head);
	/*
	printf("升序：\n");
	asclnk(head);
	prilnk(head);
	printf("降序：\n");
	deslnk(head);
	prilnk(head);
	printf("请输入要分配的内存块个数n：");
	int n2;
	scanf("%d", &n2);
	link_type* head2 = setlnk(n2);//创建链表
	printf("链表：\n");
	prilnk(head2);
	printf("链表：\n");
	conlnk(head, head2);
	prilnk(head);
	prilnk(head2);
	*/
	frelnk(head);
}