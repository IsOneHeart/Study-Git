#pragma once
/* 含头节点的栈 */
typedef struct SNode {
	stype data;
	struct SNode* next;
}SNode;

//栈初始化
int StackInitiate(SNode** head) {
	if ((*head = (SNode*)malloc(sizeof(SNode))) == NULL) {
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//检测栈是否为空
int StackNotEmpty(SNode* head) {
	if (head->next == NULL)
		return 0;
	return 1;
}

//入栈
int StackPush(SNode* head, stype x) {
	SNode* newnode;
	if ((newnode = (SNode*)malloc(sizeof(SNode))) == NULL) {
		return 0;
	}
	newnode->data = x;
	newnode->next = head->next;//新节点链入栈顶
	head->next = newnode;
	return 0;
}

//出栈
int StackPop(SNode* head, stype* pop) {
	SNode* p = head->next;
	if (p == NULL)
		return 0;
	head->next = p->next;//*删除原栈顶元素
	*pop = p->data;
	free(p);
	return 1;
}

//取栈顶元素
stype StackTop(SNode* head) {
	return head->next->data;
}

//释放栈
int StackDestory(SNode** head) {
	SNode* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//用p2保存下一个节点指针
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head置空
	return 1;
}

//打印栈
int StackPrint(SNode* head) {
	SNode* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf(TYPE, p->data);
		printf(" ");
	}
	return 1;
}

//获取长度
int StackLen(SNode* head) {
	SNode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

// Copyright(C) 2023 ZYX, All Rights Reserved
//
// @Author  : ZYX in Cyberspace Security Class 2 of DGUT
// @File    : XStack.h