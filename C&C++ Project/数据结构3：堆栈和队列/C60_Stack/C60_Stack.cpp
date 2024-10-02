#include <stdio.h>
#include <stdlib.h>
typedef char stype;
#define TYPE "%c"
#include "Xstack.h"

/* test */
int main() {
	SNode* head;
	StackInitiate(&head);

	if (StackNotEmpty(head))
		printf("栈不为空\n");
	else
		printf("栈为空\n");

	for (char i = 'a';i < 'k';i++)
		StackPush(head, i);

	printf("打印栈：");
	StackPrint(head);
	printf("\n");

	if (StackNotEmpty(head))
		printf("栈不为空\n");
	else
		printf("栈为空\n");

	stype c;
	StackTop(head, &c);
	printf("栈顶元素为%c\n", c);

	printf("栈节点有%d个\n", StackLen(head));

	printf("出栈一次\n");
	stype pop;
	StackPop(head, &pop);
	printf("删除栈顶元素为%c\n", pop);

	printf("打印栈：");
	StackPrint(head);
	printf("\n");

	StackTop(head, &c);
	printf("栈顶元素为%c\n", c);

	printf("栈节点有%d个\n", StackLen(head));

	StackDestory(&head);
	return 0;
}