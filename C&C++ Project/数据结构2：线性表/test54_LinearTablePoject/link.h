#pragma once
#include <stdlib.h>
#define TYPE "%d"

typedef struct Node {
	type data;
	struct Node* next;
}Node;

//��������
int ListIntitiate(Node** head) {
	if ((*head = (Node*)malloc(sizeof(Node))) == NULL){
		printf("[��������]�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//����ڵ�
int ListInsert(Node* head, int i, type newdata) {
	Node* p, *newnode;
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
	if ((newnode = (Node*)malloc(sizeof(Node))) == NULL) {
		printf("[����ڵ�]�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	newnode->data = newdata;//��ֵ
	newnode->next = p->next;//����ڵ�,p->nextΪa[i]
	p->next = newnode;
	return 1;
}

//��ӡ��������
int ListPrint(Node* head) {
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ",p->data);
	}
	return 1;
}

//ɾ���ڵ�
int ListDelete(Node* head, int i, type* deletenode) {
	Node* p, *delp;
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
	*deletenode = p->data;//��ָ�뷵�ر�ɾ��Ԫ��
	delp = p->next;
	p->next = p->next->next;//��p�ĺ�̵ĺ����Ϊ���
	free(delp);//�ͷ�
	return 1;
}

//�ͷ�����
int ListDestory(Node** head) {
	Node* p1, * p2;
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
int ListExchange(Node* a, Node* b) {
	if (a == NULL || b == NULL) {
		printf("[�����ڵ�]ָ�벻��Ϊ�գ�\n");
		return 0;
	}
	type temp = a->data;
	a->data = b->data;
	b->data = temp;
	return 1;
}

//��������
int ListAscend(Node** head) {
	Node* p, * index;
	if ((*head)->next == NULL) {
		printf("[��������]����Ϊ�գ�\n");
		return 0;
	}
	else {
		int flag = 1;
		for (p = (*head)->next;p->next != NULL;p = p->next) {
			flag = 0;
			for (index = p->next;index != NULL;index = index->next) {
				if (p->data > index->data)
					ListExchange(p, index);
			}
		}
		return 1;
	}
}

//��������
int ListDescend(Node** head) {
	Node* p, * index;
	if ((*head)->next == NULL) {
		printf("[��������]����Ϊ�գ�\n");
		return 0;
	}
	else {
		int flag = 1;
		for (p = (*head)->next;p->next != NULL;p = p->next) {
			flag = 0;
			for (index = p->next;index != NULL;index = index->next) {
				if (p->data < index->data)
					ListExchange(p, index);
			}
		}
		return 1;
	}
}

//��������
int ListCopy(Node* head1,Node** head2) {
	Node* p1 = head1->next;
	Node* p2 = NULL;
	Node* newnode;
	Node* tail = *head2;
	while (p1 != NULL) {
		if ((newnode = (Node*)malloc(sizeof(Node))) == NULL) {
			printf("[��������]�ڴ�����ʧ�ܣ�\n");
			return 0;
		}
		newnode->data = p1->data;
		newnode->next = NULL;
		if (*head2 == NULL) {
			*head2 = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		p1 = p1->next;
	}
	return 1;
}

//���ҽڵ�
int ListFind(Node* head, type x, int i) {//��i��ʼ����dataΪx�Ľڵ�
	Node* p = head->next;
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
		if (p->data == x)
			return 1;//�ҵ�
		p = p->next;
	}
	return -1;//δ�ҵ�
}

//��ȡ����
int ListLen(Node* head) {
	Node* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//��������
int ListReverse(Node** head) {
	int len = ListLen(*head);
	Node* p1 = (*head)->next;
	Node* p2 = p1;
	int i = len;
	int k = 0;
	for (int j = 0; j < i; j++) {
		p2 = (*head)->next;
		for (int m = 0; m < len - j - 1; m++) {
			p2 = p2->next;
		}
		ListExchange(p1, p2);
		p1 = p1->next;
		i--;
	}
	return 1;
}

//����ɾ��
int ListDeleteMore(Node* head, type x) {
	Node* p = head->next;
	Node* prev = head;
	int deleted = 0;
	while (p != NULL) { 
		if (p->data == x) {
			Node* delp = p;
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

//�ж��Ӽ�
int ListSubset(Node* head1, Node* head2) {
	Node* p1, * p2;
	p1 = head1;
	p2 = head2;
	int flag = 0;
	while (p1 != NULL) {
		p2 = head2;//����ʱ����
		flag = 0;
		while (p2 != NULL) {
			if (p2->data == p1->data) {
				flag = 1;
				break;//�ҵ�ʱ�˳��ڲ�ѭ��
			}
			p2 = p2->next;
		}
		if (flag == 0) {
			return 0;
		}
		p1 = p1->next;
	}
	return 1;
}

int ListGet(Node* head, int n, type* x) {
	Node* p = head;
	int j = -1;
	while (p->next != NULL && j < n) {
		p = p->next;
		j++;
	}
	if (j != n) {
		printf("ȡԪ��λ�ò�������");
		return 0;
	}
	*x = p->data;
	return 1;
}

//��������˵�
int ListMenu(Node** head) {
	int flag = -2;
	int counts;
	printf("[������Ϣ]......\n");
	while (flag != -1) {
		printf("================��������˵�=================\n");
		printf("��������0��   ����ڵ㡾1��   ��ӡ����2��\n");
		printf("��������3��   ���ҽڵ㡾4��   ��ȡ���ȡ�5��\n");
		printf("�������С�6��   �������С�7��   �������á�8��\n");
		printf("�����ڵ㡾9��   ɾ���ڵ㡾10��  �ͷ�����11��\n");
		printf("����ɾ����12��  �ж��Ӽ���13��  ��ȡԪ�ء�14��\n");
		printf("�˳��˵���-1��\n");
		printf("=============================================\n");
		printf("ѡ�������");
		scanf_s("%d", &flag);
		switch (flag) {
		    case -1:
			    return 1;

		    case 0:
			    ListIntitiate(head);
				system("cls");
				printf("[��������]��������ɹ���\n");
			    break;

		    case 1:
			    printf("������Ҫ����Ľڵ�λ�ã�");
			    int place;
			    scanf_s("%d", &place);
			    printf("������Ҫ����Ľڵ����ݣ�");
			    type newnode;
				scanf_s(TYPE, &newnode);
				/*if (sizeof(type) == sizeof(int))
					scanf_s("%d", &newnode);
				else if (sizeof(type) == sizeof(float))
					scanf_s("%f", &newnode);
				else if (sizeof(type) == sizeof(double))
					scanf_s("%lf", &newnode);
				else if (sizeof(type) == sizeof(long))
					scanf_s("%ld", &newnode);
				else if (sizeof(type) == sizeof(long long))
					scanf_s("%lld", &newnode);
				else if (sizeof(type) == sizeof(char))
					scanf_s("%c", &newnode);
				else if (sizeof(type) == sizeof(char*)){
					char buffer[100]; 
					scanf_s("%s", buffer, sizeof(buffer));
					newnode = buffer;
				}*/
				system("cls");
				if(ListInsert(*head, place, newnode)==1)
					printf("[����ڵ�]����ڵ�ɹ���\n");
				else
					printf("[����ڵ�]����ڵ�ʧ�ܣ�\n");
			    break;

			case 2:
				system("cls");
				printf("[��ӡ����]");
				ListPrint(*head);
				printf("\n");
				break;

			case 3:
				system("cls");
				printf("[��������]ʧ�ܣ��뵥�����ú���ListCpoy��int ListCopy(Node* head1,Node** head2)\n");
				break;

			case 4:
				type findnode;
				int i;
				printf("������Ҫ���ҵĽڵ����ݣ�");
				scanf_s(TYPE, &findnode);//!
				printf("��������ʼ�����ڵ㣺");
				scanf_s("%d", &i);
				system("cls");
				if (ListFind(*head, findnode, i) == 1)
					printf("[���ҽڵ�]���ҵ���\n");
				else
					printf("[���ҽڵ�]δ�ҵ���\n");
				break;

			case 5:
				system("cls");
				printf("[��ȡ����]");
				printf(TYPE, ListLen(*head));
				printf("\n");
				break;

			case 6:
				system("cls");
				if(ListAscend(head)==1)
					printf("[��������]������ɣ�\n");
				else
					printf("[��������]����ʧ�ܣ�\n");
				break;

			case 7:
				system("cls");
				if (ListDescend(head) == 1)
					printf("[��������]������ɣ�\n");
				else
					printf("[��������]����ʧ�ܣ�\n");
				break;

			case 8:
				system("cls");
				if (ListReverse(head) == 1)
					printf("[��������]������ɣ�\n");
				else
					printf("[��������]����ʧ�ܣ�\n");
				break;

			case 9:
				system("cls");
				printf("[�����ڵ�]ʧ�ܣ��뵥�����ú���ListExchange��int ListExchange(Node * a, Node * b)\n");
				break;

			case 10:
				system("cls");
				printf("[ɾ���ڵ�]ʧ�ܣ��뵥�����ú���ListDelete��int ListDelete(Node* head, int i, type* deletenode)\n");
				break;

			case 11:
				system("cls");
				ListDestory(head);
				printf("[�ͷ�����]�ɹ��ͷ�����\n");
				break;
			
			case 12:
				printf("������Ҫɾ����Ԫ�ص�data��");
				type del_data;
				scanf_s(TYPE, &del_data);//!
				system("cls");
				counts = ListDeleteMore(*head, del_data);
				printf("[����ɾ��]ɾ���ɹ���\n", counts);
				break;

			case 13:
				system("cls");
				printf("[�ж��Ӽ�]ʧ�ܣ��뵥�����ú���ListSubset��int ListSubset(Node* head1, Node* head2)\n");
				break;

			case 14:
				int n;
				printf("������Ҫ��ȡ��Ԫ�ؽڵ���ţ�");
				scanf_s("%d", &n);
				system("cls");
				printf("[��ȡԪ��]");
				type* x;
				ListGet(*head, n, x);
				printf(TYPE, *x);
				printf("\n");
				break;

			default:
				system("cls");
				printf("��Ч�Ĳ�����\n");
				break;
		}
	}
	return 1;
}

// Copyright(C) 2023 ZYX, All Rights Reserved
//
// @Author  : ZYX in Cyberspace Security Class 2 of DGUT
// @File    : link.h