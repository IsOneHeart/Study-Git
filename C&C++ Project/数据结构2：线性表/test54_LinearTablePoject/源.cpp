#include <stdio.h>
#define type int
#include "link.h"
int main() {
	Node* head;
	ListMenu(&head);
	printf("菜单安全关闭!\n");
	ListDescend(&head);

	Node* head2;
	ListIntitiate(&head2);
	ListInsert(head2, 0, 0);
	ListInsert(head2, 0, 1);
	if (ListSubset(head2, head))
		printf("以head2为头指针的链表是以head为头指针的链表的子集");
	else
		printf("以head2为头指针的链表不是以head为头指针的链表的子集");

	if (head != NULL) {//确保内存不泄漏
		ListDestory(&head);
	}
	return 0;
}