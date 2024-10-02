#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include <stdlib.h>

/*
datalink.h头文件函数介绍：
setlnk(正整数,数据类型)      创建某正整数个内存块的链表并返回头指针
prilnk(头指针)               打印输入的头指针对应的链表
dellnk(头指针,非负整数)      删除输入的头指针对应的链表的第某非负整数个节点
inslnk(头指针,非负整数)      在输入的头指针对应的链表的第某非负整数个节点插入一个新节点
frelnk(头指针)               释放输入的头指针对应的链表并将头指针指向NULL
asclnk(头指针)               将输入的头指针对应的链表按data大小进行升序排列
deslnk(头指针)               将输入的头指针对应的链表按data大小进行降序排列
spnode(节点,节点)            交换两个节点
*/

typedef struct link_type {//定义链表节点结构
	int data;
	struct link_type* next;
}link_type;

link_type* setlnk(int n) {//创建链表并返回头指针
	link_type* link = NULL, * p = NULL;
	link_type* head = NULL;
	if (n <= 0) {//检查是否需要分配内存块
		printf("内存块分配失败！");
		exit(0);
	}
	for (int i = 0;i < n;i++) {//循环创建链表节点
		if ((link = (link_type*)malloc(sizeof(link_type))) == NULL) {//分配内存块
			printf("内存块分配失败！");
			exit(0);
		}
		printf("data[%d]:", i);//用户输入节点数据
		scanf("%d", &(link->data));
		link->next = NULL;//初始化节点的下一个指针
		if (i == 0) {
			head = link;//将节点加入链表
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
			//printf("已成功删除节点%d！\n",N);
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
	if ((new_node = (link_type*)malloc(sizeof(link_type))) == NULL) {//分配内存块
		printf("内存块分配失败！");
		exit(0);
	}
	scanf("%d", &(new_node->data));
	if ( N >= 0 ) {
		for (;i < N;i++) {
			if (p1 == NULL) {
				printf("插入位置超出链表长度！\n");
				free(new_node);
				return head;
			}
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == NULL) {//插入位置为首节点之前
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
		next = current->next; // 保存下一个节点的指针
		free(current); // 释放当前节点的内存
		current = next; // 将当前节点指针指向下一个节点
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
		printf("链表为空！\n");
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
		printf("链表为空！\n");
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