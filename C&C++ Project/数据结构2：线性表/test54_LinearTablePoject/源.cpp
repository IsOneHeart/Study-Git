#include <stdio.h>
#define type int
#include "link.h"
int main() {
	Node* head;
	ListMenu(&head);
	printf("�˵���ȫ�ر�!\n");
	ListDescend(&head);

	Node* head2;
	ListIntitiate(&head2);
	ListInsert(head2, 0, 0);
	ListInsert(head2, 0, 1);
	if (ListSubset(head2, head))
		printf("��head2Ϊͷָ�����������headΪͷָ���������Ӽ�");
	else
		printf("��head2Ϊͷָ�����������headΪͷָ���������Ӽ�");

	if (head != NULL) {//ȷ���ڴ治й©
		ListDestory(&head);
	}
	return 0;
}