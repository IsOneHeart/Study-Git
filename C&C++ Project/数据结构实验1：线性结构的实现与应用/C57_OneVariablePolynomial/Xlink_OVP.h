#pragma once
#include <stdlib.h>

typedef struct OVPNode {
	float P;
	int power;
	struct OVPNode* next;
}OVPNode;

//创建链表
int OVPInitiate(OVPNode** head) {
	if ((*head = (OVPNode*)malloc(sizeof(OVPNode))) == NULL) {
		printf("内存块分配失败！\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//插入节点
int OVPInsert(OVPNode* head , float newP , int newpower) {
	if (newP == 0)
		return 1;
	OVPNode* p, * newnode;
	p = head;
	while (p->next != NULL) {
		/* 已存在相等幂 */
		if (p->power == newpower) {
			p->P = p->P + newP;
			return 1;
		}

		/* 中间新幂 */
		if (p->next->power > newpower) {
			if ((newnode = (OVPNode*)malloc(sizeof(OVPNode))) == NULL) {
				printf("内存块分配失败！\n");
				return 0;
			}
			newnode->power = newpower;//赋值
			newnode->P = newP;
			newnode->next = p->next;//插入节点
			p->next = newnode;
			return 1;
		}
		p = p->next;
	}

	// 如果到达链表末尾仍未插入，则在链表末尾插入新节点
	if (p->power == newpower) {
		p->P += newP; // 直接将系数相加
		return 1;
	}
	newnode = (OVPNode*)malloc(sizeof(OVPNode));
	if (newnode == NULL) {
		printf("内存块分配失败！\n");
		return 0;
	}
	newnode->power = newpower;
	newnode->P = newP;
	newnode->next = NULL;
	p->next = newnode;
	return 1;
}

//打印多项式
int OVPPrint(OVPNode* head) {
	OVPNode* p = head->next;
	int isFirst = 1;
	while (p != NULL) {
		if (isFirst != 1)
			printf("+");
		else
			isFirst = 0;
		printf("%.2fx^%d", p->P , p->power);
		p = p->next;
	}
	return 1;
}

//释放链表
int OVPDestory(OVPNode** head) {
	OVPNode* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//用p2保存下一个节点指针
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head置空
	return 1;
}

//获取长度
int OVPLen(OVPNode* head) {
	OVPNode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//多项式相加
OVPNode* OVPAdd(OVPNode* head1, OVPNode* head2) {
	OVPNode* result_head;
	OVPInitiate(&result_head);
	OVPNode* p = head1->next;
	while (p->next != NULL) {
		OVPInsert(result_head, p->P, p->power);
		p = p->next;
	}
	p = head2->next;
	while (p->next != NULL) {
		OVPInsert(result_head, p->P, p->power);
		p = p->next;
	}
	return result_head;
}

//多项式相减
OVPNode* OVPMinus(OVPNode* head1, OVPNode* head2) {
	OVPNode* result_head;
	OVPInitiate(&result_head);
	OVPNode* p = head1->next;
	while (p->next != NULL) {
		OVPInsert(result_head, p->P, p->power);
		p = p->next;
	}
	p = head2->next;
	while (p->next != NULL) {
		OVPInsert(result_head, -(p->P), p->power);
		p = p->next;
	}
	return result_head;
}

// Copyright(C) 2023 ZYX, All Rights Reserved
//
// @Author  : ZYX in Cyberspace Security Class 2 of DGUT
// @File    : Xlink.h_OVP
