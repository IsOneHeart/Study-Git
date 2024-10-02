#pragma once
/* ��ͷ�ڵ��ջ */
typedef struct SNode {
	stype data;
	struct SNode* next;
}SNode;

//ջ��ʼ��
int StackInitiate(SNode** head) {
	if ((*head = (SNode*)malloc(sizeof(SNode))) == NULL) {
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//���ջ�Ƿ�Ϊ��
int StackNotEmpty(SNode* head) {
	if (head->next == NULL)
		return 0;
	return 1;
}

//��ջ
int StackPush(SNode* head, stype x) {
	SNode* newnode;
	if ((newnode = (SNode*)malloc(sizeof(SNode))) == NULL) {
		return 0;
	}
	newnode->data = x;
	newnode->next = head->next;//�½ڵ�����ջ��
	head->next = newnode;
	return 0;
}

//��ջ
int StackPop(SNode* head, stype* pop) {
	SNode* p = head->next;
	if (p == NULL)
		return 0;
	head->next = p->next;//*ɾ��ԭջ��Ԫ��
	*pop = p->data;
	free(p);
	return 1;
}

//ȡջ��Ԫ��
stype StackTop(SNode* head) {
	return head->next->data;
}

//�ͷ�ջ
int StackDestory(SNode** head) {
	SNode* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//��p2������һ���ڵ�ָ��
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head�ÿ�
	return 1;
}

//��ӡջ
int StackPrint(SNode* head) {
	SNode* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf(TYPE, p->data);
		printf(" ");
	}
	return 1;
}

//��ȡ����
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