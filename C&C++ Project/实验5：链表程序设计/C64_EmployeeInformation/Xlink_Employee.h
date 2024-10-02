#pragma once
#include <stdlib.h>
#define TYPE "%d"

typedef struct EINode {
	char name[15];
	int salary;
	struct EINode* next;
}EINode;

//��������
int EIListInitiate(EINode** head) {
	if ((*head = (EINode*)malloc(sizeof(EINode))) == NULL) {
		printf("[��������]�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//����ڵ�
int EIListInsert(EINode* head, int i, char* newname, int newsalary) {
	EINode* p, * newEINode;
	p = head;
	int j = -1;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {//pָ��a[i-1]
		printf("[����ڵ�]����Ԫ��λ�ò�������\n");
		return 0;
	}
	if ((newEINode = (EINode*)malloc(sizeof(EINode))) == NULL) {
		printf("[����ڵ�]�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	strcpy(newEINode->name, newname);
	//*(newEINode->name) = *newname;
	newEINode->salary = newsalary;//��ֵ
	newEINode->next = p->next;//����ڵ�,p->nextΪa[i]
	p->next = newEINode;
	return 1;
}

//��ӡ��������
int EIListPrint(EINode* head) {
	EINode* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%s %d ", p->name, p->salary);
	}
	return 1;
}

//ɾ���ڵ�
int EIListDelete(EINode* head, int i, char* deletename, int* deletesalary) {
	EINode* p, * delp;
	p = head;
	int j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("[ɾ���ڵ�]ɾ��Ԫ��λ�ò�������\n");
		return 0;
	}
	strcpy(deletename, p->name);
	//deletename = p->name;
	*deletesalary = p->salary;//��ָ�뷵�ر�ɾ��Ԫ��
	delp = p->next;
	p->next = p->next->next;//��p�ĺ�̵ĺ����Ϊ���
	free(delp);//�ͷ�
	return 1;
}

//�ͷ�����
int EIListDestory(EINode** head) {
	EINode* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//��p2������һ���ڵ�ָ��
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head�ÿ�
	return 1;
}

//�����ڵ�
int EIListExchange(EINode* a, EINode* b) {
	if (a == NULL || b == NULL) {
		printf("[�����ڵ�]ָ�벻��Ϊ�գ�\n");
		return 0;
	}
	char* temp_name = a->name;
	strcpy(a->name, b->name);
	//*a->name = *b->name;
	strcpy(b->name, temp_name);
	//*b->name = *temp_name;

	int temp = a->salary;
	a->salary = b->salary;
	b->salary = temp;
	return 1;
}

//��������
int EIListAscend(EINode** head) {
	EINode* p, * index;
	if ((*head)->next == NULL) {
		printf("[��������]����Ϊ�գ�\n");
		return 0;
	}
	else {
		int flag = 1;
		for (p = (*head)->next;p->next != NULL;p = p->next) {
			flag = 0;
			for (index = p->next;index != NULL;index = index->next) {
				if (p->salary > index->salary)
					EIListExchange(p, index);
			}
		}
		return 1;
	}
}

//��������
int EIListDescend(EINode** head) {
	EINode* p, * index;
	if ((*head)->next == NULL) {
		printf("[��������]����Ϊ�գ�\n");
		return 0;
	}
	else {
		int flag = 1;
		for (p = (*head)->next;p->next != NULL;p = p->next) {
			flag = 0;
			for (index = p->next;index != NULL;index = index->next) {
				if (p->salary < index->salary)
					EIListExchange(p, index);
			}
		}
		return 1;
	}
}

//��������
int EIListCopy(EINode* head1, EINode** head2) {
	EINode* p1 = head1->next;
	EINode* p2 = NULL;
	EINode* newEINode;
	EINode* tail = *head2;
	while (p1 != NULL) {
		if ((newEINode = (EINode*)malloc(sizeof(EINode))) == NULL) {
			printf("[��������]�ڴ�����ʧ�ܣ�\n");
			return 0;
		}
		strcpy(newEINode->name, p1->name);
		//*newEINode->name = *p1->name;
		newEINode->salary = p1->salary;
		newEINode->next = NULL;
		if (*head2 == NULL) {
			*head2 = newEINode;
			tail = newEINode;
		}
		else {
			tail->next = newEINode;
			tail = newEINode;
		}
		p1 = p1->next;
	}
	return 1;
}

//���ҽڵ�
int EIListFind(EINode* head, int x, int i) {//��i��ʼ����salaryΪx�Ľڵ�
	EINode* p = head->next;
	int j = -1;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("[���ҽڵ�]ɾ��Ԫ��λ�ò�������\n");
		return 0;
	}
	while (p->next != NULL) {
		if (p->salary == x)
			return 1;//�ҵ�
		p = p->next;
	}
	return -1;//δ�ҵ�
}

//��ȡ����
int EIListLen(EINode* head) {
	EINode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//��������
int EIListReverse(EINode** head) {
	int len = EIListLen(*head);
	EINode* p1 = (*head)->next;
	EINode* p2 = p1;
	int i = len;
	int k = 0;
	for (int j = 0; j < i; j++) {
		p2 = (*head)->next;
		for (int m = 0; m < len - j - 1; m++) {
			p2 = p2->next;
		}
		EIListExchange(p1, p2);
		p1 = p1->next;
		i--;
	}
	return 1;
}

//����ɾ��
int EIListDeleteMore(EINode* head, int x) {
	EINode* p = head->next;
	EINode* prev = head;
	int deleted = 0;
	while (p != NULL) {
		if (p->salary == x) {
			EINode* delp = p;
			prev->next = p->next;
			p = p->next;
			free(delp);//�ͷ�
			deleted = 1;
		}
		else {
			prev = p;
			p = p->next;//����ɾ���ڵ�ʱ
		}
	}
	return deleted;
}

int EIListGet(EINode* head, int n, char* name, int* x) {
	EINode* p = head;
	int j = -1;
	while (p->next != NULL && j < n) {
		p = p->next;
		j++;
	}
	if (j != n) {
		printf("ȡԪ��λ�ò�������");
		return 0;
	}
	strcpy(name, p->name);
	//name = p->name;
	*x = p->salary;
	return 1;
}

// Copyright(C) 2023 ZYX, All Rights Reserved
//
// @Author  : ZYX in Cyberspace Security Class 2 of DGUT
// @File    : Xlink_Employee.h