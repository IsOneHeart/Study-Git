#pragma once
#include <stdlib.h>
#ifndef TYPE
#define TYPE "%d"
#endif
#ifndef DataType
#define DataType int
#endif

#ifndef DATA
#define DATA data
#endif
#ifndef HOWFIND
#define HOWFIND p->data==x
#endif

typedef struct SLNode {
	DataType data;
	struct SLNode* next;
}SLNode;

//��������
int SetInitiate(SLNode** head) {
	if ((*head = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
		printf("[��������]�ڴ�����ʧ�ܣ�\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//��ӡ��������
//int SetPrint(SLNode* head) {
//	SLNode* p = head;
//	if (head->next == NULL) {
//		printf(" ");
//		return 1;
//	}
//	while (p->next != NULL) {
//		p = p->next;
//		printf("%d ", p->data);
//	}
//	return 1;
//}

//ɾ���ڵ�
int SetDelete(SLNode* head, int i, DataType* deletenode) {
	SLNode* p, * delp;
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
int SetDestory(SLNode** head) {
	SLNode* p1, * p2;
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
int SetExchange(SLNode* a, SLNode* b) {
	if (a == NULL || b == NULL) {
		printf("[�����ڵ�]ָ�벻��Ϊ�գ�\n");
		return 0;
	}
	DataType temp = a->data;
	a->data = b->data;
	b->data = temp;
	return 1;
}

//���ҽڵ�
int SetFind(SLNode* head, DataType x) {
	SLNode* p = head->next;
	while (p != NULL) {
		if (HOWFIND)
			return 1;//�ҵ�
		p = p->next;
	}
	return NULL;//δ�ҵ�
}

//����ڵ�
int SetInsert(SLNode* head, int i, DataType newdata) {
	//if (SetFind(head, newdata) == 1)//��Ԫ�����ڼ�����
	//	return 0;
	//else {
		SLNode* p, * newnode;
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
		if ((newnode = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
			printf("[����ڵ�]�ڴ�����ʧ�ܣ�\n");
			return 0;
		}
		newnode->data = newdata;//��ֵ
		p->next = newnode;
	//}
	return 1;
}

//��������
int SetCopy(SLNode* head1, SLNode** head2) {
	SLNode* p1 = head1->next;
	SLNode* p2 = NULL;
	SLNode* newnode;
	SLNode* tail = *head2;
	while (p1 != NULL) {
		if ((newnode = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
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

//�󽻼�
//int SetIntersection(SLNode* head1,SLNode* head2,SLNode* head3) {
//	if (head1->next == NULL || head2->next == NULL)
//		//����Ϊ��
//		return 0;
//	else {
//		SLNode* p1 = head1->next;
//		int flag = 0;//����Ƿ��н���
//		while (p1 != NULL ) {
//			if (SetFind(head2, p1->data) == 1) {
//				SetInsert(head3, 0, p1->data);
//				flag = 1;
//			}
//			p1 = p1->next;
//		}
//		if (flag == 1)
//			return 1;
//		return 0;//����Ϊ��
//	}
//}

////��
//int SetDifference(SLNode* head1, SLNode* head2, SLNode* head3) {
//	if (head1->next == NULL)
//		return 0;
//	else {
//		SLNode* p1 = head1->next;
//		int flag = 0;
//		while (p1 != NULL) {
//			if (SetFind(head2, p1->data) == NULL) {
//				SetInsert(head3, 0, p1->data);
//				flag = 1;
//			}
//			p1 = p1->next;
//		}
//		if (flag == 1)
//			return 1;
//		return 0;
//	}
//}

//�󲢼�
int SetUnion(SLNode* head1, SLNode* head2, SLNode* head3) {
	SetCopy(head1, &head3);
	SLNode* p = head2->next;
	while (p != NULL) {
		SetInsert(head3, 0, p->data);
		p = p->next;
	}
	return 1;
}

//��������
void SetSort(SLNode* head) {
	SLNode* p, * index, * pre, * temp;
	if (head->next == NULL) {
		printf("����Ϊ�գ�\n");
	}
	else {
		// ������ʱͷ�ڵ�
		SLNode* tempHead = (SLNode*)malloc(sizeof(SLNode));
		tempHead->next = head->next;

		// ð������
		for (p = tempHead; p->next != NULL; p = p->next) {
			for (index = p->next; index->next != NULL; index = index->next) {
				if (p->next->DATA > index->next->DATA) {
					// �����ڵ�ָ��
					temp = index->next;
					index->next = temp->next;
					temp->next = p->next;
					p->next = temp;

					// ����ָ��λ��
					pre = index;
					index = temp;
					temp = pre;
				}
			}
		}

		// ����ԭ����ͷ�ڵ�
		head->next = tempHead->next;
		free(tempHead); // �ͷ���ʱͷ�ڵ�
	}
}

//��ȡ����
int SetLen(SLNode* head) {
	SLNode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//�ж��Ӽ�
//int SetSubset(SLNode* head1, SLNode* head2) {
//	SLNode* p1, * p2;
//	p1 = head1;
//	p2 = head2;
//	int flag = 0;
//	while (p1 != NULL) {
//		p2 = head2;//����ʱ����
//		flag = 0;
//		while (p2 != NULL) {
//			if (p2->data == p1->data) {
//				flag = 1;
//				break;//�ҵ�ʱ�˳��ڲ�ѭ��
//			}
//			p2 = p2->next;
//		}
//		if (flag == 0) {
//			return 0;
//		}
//		p1 = p1->next;
//	}
//	return 1;
//}

int SetGet(SLNode* head, int n,DataType *x) {
	SLNode* p = head;
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
