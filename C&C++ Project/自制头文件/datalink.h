#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include <stdlib.h>

/*
datalink.hͷ�ļ��������ܣ�
setlnk(������,��������)      ����ĳ���������ڴ�����������ͷָ��
prilnk(ͷָ��)               ��ӡ�����ͷָ���Ӧ������
dellnk(ͷָ��,�Ǹ�����)      ɾ�������ͷָ���Ӧ������ĵ�ĳ�Ǹ��������ڵ�
inslnk(ͷָ��,�Ǹ�����)      �������ͷָ���Ӧ������ĵ�ĳ�Ǹ��������ڵ����һ���½ڵ�
frelnk(ͷָ��)               �ͷ������ͷָ���Ӧ��������ͷָ��ָ��NULL
asclnk(ͷָ��)               �������ͷָ���Ӧ������data��С������������
deslnk(ͷָ��)               �������ͷָ���Ӧ������data��С���н�������
spnode(�ڵ�,�ڵ�)            ���������ڵ�
*/

typedef struct link_type {//��������ڵ�ṹ
	int data;
	struct link_type* next;
}link_type;

link_type* setlnk(int n) {//������������ͷָ��
	link_type* link = NULL, * p = NULL;
	link_type* head = NULL;
	if (n <= 0) {//����Ƿ���Ҫ�����ڴ��
		printf("�ڴ�����ʧ�ܣ�");
		exit(0);
	}
	for (int i = 0;i < n;i++) {//ѭ����������ڵ�
		if ((link = (link_type*)malloc(sizeof(link_type))) == NULL) {//�����ڴ��
			printf("�ڴ�����ʧ�ܣ�");
			exit(0);
		}
		printf("data[%d]:", i);//�û�����ڵ�����
		scanf("%d", &(link->data));
		link->next = NULL;//��ʼ���ڵ����һ��ָ��
		if (i == 0) {
			head = link;//���ڵ��������
			p = head;
		}
		else {
			p->next = link;
			p = link;
		}
	}
	return head;
}

void prilnk(link_type* head) {
	link_type* p = head;
	int i = 0;
	while (p != NULL) {
		printf("data[%d]=%d\n", i, p->data);
		i++;
		p = p->next;
	}
}

link_type* dellnk(link_type* head, int N) {
	link_type* p1 = head, * p2 = NULL;
	int i = 0;
	while (p1 != NULL) {
		if (i == N) {
			if (i == 0)
				head = p1->next;
			else
				p2->next = p1->next;
			free(p1);
			//printf("�ѳɹ�ɾ���ڵ�%d��\n",N);
			return head;
		}
		else {
			i++;
			p2 = p1;
			p1 = p1->next;
		}
	}
	return head;
}

link_type* inslnk(link_type* head, int N) {
	link_type* p1 = head, * p2 = NULL, * new_node = NULL;
	int i = 0;
	printf("data[new]:");
	if ((new_node = (link_type*)malloc(sizeof(link_type))) == NULL) {//�����ڴ��
		printf("�ڴ�����ʧ�ܣ�");
		exit(0);
	}
	scanf("%d", &(new_node->data));
	if ( N >= 0 ) {
		for (;i < N;i++) {
			if (p1 == NULL) {
				printf("����λ�ó��������ȣ�\n");
				free(new_node);
				return head;
			}
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == NULL) {//����λ��Ϊ�׽ڵ�֮ǰ
			new_node->next = head;
			head = new_node;
		}
		else {
			new_node->next = p1;
			p2->next = new_node;
		}
	}
	return head;
}

void frelnk(link_type* head) {
	link_type* current = head;
	link_type* next;
	while (current != NULL) {
		next = current->next; // ������һ���ڵ��ָ��
		free(current); // �ͷŵ�ǰ�ڵ���ڴ�
		current = next; // ����ǰ�ڵ�ָ��ָ����һ���ڵ�
	}
	head = NULL;
}

void spnode(link_type* a, link_type* b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void asclnk(link_type* head) {
	link_type* current, * index;
	if (head == NULL) {
		printf("����Ϊ�գ�\n");
		return NULL;
	}
	else {
		for (current = head; current != NULL; current = current->next) {
			for (index = current->next; index != NULL; index = index->next) {
				if (current->data < index->data) {
					spnode(current, index);
				}
			}
		}
	}
	//return head;
}

void deslnk(link_type* head) {
	link_type* current, * index;
	if (head == NULL) {
		printf("����Ϊ�գ�\n");
		return NULL;
	}
	else {
		for (current = head; current != NULL; current = current->next) {
			for (index = current->next; index != NULL; index = index->next) {
				if (current->data > index->data) {
					spnode(current, index);
				}
			}
		}
	}
}

void conlnk(link_type* head1, link_type* head2) {
	link_type* p = head1;
	while (p->next != NULL) 
		p = p->next;
	p->next = head2;
	head2 = head1;
}