#include <stdio.h>
#define type int
#include "Xlink.h"

int main() {
	Node* head1, * head2;
	ListInitiate(&head1);
	ListInitiate(&head2);
	printf("请输入链表一学生成绩：(-1标志结束）\n");
	int mark = 0;
	while (1) {
		scanf_s("%d", &mark);
		if (mark == -1)
			break;
		ListInsert(head1, 0, mark);
	}
	ListAscend(&head1);
	printf("请输入链表二学生成绩：(-1标志结束）\n");
	mark = 0;
	while (1) {
		scanf_s("%d", &mark);
		if (mark == -1)
			break;
		ListInsert(head2, 0, mark);
	}
	ListAscend(&head2);

	Node* head3;
	ListInitiate(&head3);
	ListMerge(head1, head2, head3);
	ListAscend(&head3);
	printf("合并链表：\n");
	ListPrint(head3);

	return 0;
}