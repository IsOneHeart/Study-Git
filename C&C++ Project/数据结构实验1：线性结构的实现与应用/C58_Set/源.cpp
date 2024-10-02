#include <stdio.h>
typedef int DataType;
#include "Xlink_Set.h"

int main() {
	SLNode* head1, * head2, * head3, * head4, * head5;
	SetInitiate(&head1);
	SetInitiate(&head2);
	SetInitiate(&head3);
	SetInitiate(&head4);
	SetInitiate(&head5);

	DataType data1, data2;
	printf("请输入set1元素：(输入非数字字符标记结束）\n");
	while (scanf_s("%d", &data1) == 1) {
		SetInsert(head1, 0, data1);
	}
	// 清空输入缓冲区
	getchar();
	printf("请输入set2元素：(输入非数字字符标记结束）\n");
	while (scanf_s("%d", &data2) == 1) {
		SetInsert(head2, 0, data2);
	}

	printf("set1={");
	SetPrint(head1);
	printf("\b}\n");
	printf("set2={");
	SetPrint(head2);
	printf("\b}\n");

	printf("set1∩set2={");
	SetIntersection(head1, head2, head3);
	SetSort(head3);
	SetPrint(head3);
	printf("\b}\n");

	printf("set1∪set2={");
	SetUnion(head1, head2, head4);
	SetSort(head4);
	SetPrint(head4);
	printf("\b}\n");

	printf("set1-set2={");
	SetDifference(head1, head2, head5);
	SetSort(head5);
	SetPrint(head5);
	printf("\b}\n");

	SetDestory(&head1);
	SetDestory(&head2);
	SetDestory(&head3);
	SetDestory(&head4);
	SetDestory(&head5);
	return 0;
}

