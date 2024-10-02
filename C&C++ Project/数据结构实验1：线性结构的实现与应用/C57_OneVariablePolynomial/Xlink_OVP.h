#pragma once
#include <stdlib.h>

typedef struct OVPNode {
	float P;
	int power;
	struct OVPNode* next;
}OVPNode;

//��������
int OVPInitiate(OVPNode** head) {
	if ((*head = (OVPNode*)malloc(sizeof(OVPNode))) == NULL) {
		printf("�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//����ڵ�
int OVPInsert(OVPNode* head , float newP , int newpower) {
	if (newP == 0)
		return 1;
	OVPNode* p, * newnode;
	p = head;
	while (p->next != NULL) {
		/* �Ѵ�������� */
		if (p->power == newpower) {
			p->P = p->P + newP;
			return 1;
		}

		/* �м����� */
		if (p->next->power > newpower) {
			if ((newnode = (OVPNode*)malloc(sizeof(OVPNode))) == NULL) {
				printf("�ڴ�����ʧ�ܣ�\n");
				return 0;
			}
			newnode->power = newpower;//��ֵ
			newnode->P = newP;
			newnode->next = p->next;//����ڵ�
			p->next = newnode;
			return 1;
		}
		p = p->next;
	}

	// �����������ĩβ��δ���룬��������ĩβ�����½ڵ�
	if (p->power == newpower) {
		p->P += newP; // ֱ�ӽ�ϵ�����
		return 1;
	}
	newnode = (OVPNode*)malloc(sizeof(OVPNode));
	if (newnode == NULL) {
		printf("�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	newnode->power = newpower;
	newnode->P = newP;
	newnode->next = NULL;
	p->next = newnode;
	return 1;
}

//��ӡ����ʽ
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

//�ͷ�����
int OVPDestory(OVPNode** head) {
	OVPNode* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//��p2������һ���ڵ�ָ��
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head�ÿ�
	return 1;
}

//��ȡ����
int OVPLen(OVPNode* head) {
	OVPNode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//����ʽ���
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

//����ʽ���
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
