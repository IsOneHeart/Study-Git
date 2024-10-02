#pragma once
#include <stdlib.h>
#define TYPE "%d"

typedef struct Node {
	type data;
	struct Node* next;
}Node;

//创建链表
int ListIntitiate(Node** head) {
	if ((*head = (Node*)malloc(sizeof(Node))) == NULL){
		printf("[创建链表]内存块分配失败！\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//插入节点
int ListInsert(Node* head, int i, type newdata) {
	Node* p, *newnode;
	p = head;
	int j = -1;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {//p指向a[i-1]
		printf("[插入节点]插入元素位置参数出错！\n");
		return 0;
	}
	if ((newnode = (Node*)malloc(sizeof(Node))) == NULL) {
		printf("[插入节点]内存块分配失败！\n");
		return 0;
	}
	newnode->data = newdata;//赋值
	newnode->next = p->next;//插入节点,p->next为a[i]
	p->next = newnode;
	return 1;
}

//打印链表数据
int ListPrint(Node* head) {
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ",p->data);
	}
	return 1;
}

//删除节点
int ListDelete(Node* head, int i, type* deletenode) {
	Node* p, *delp;
	p = head;
	int j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("[删除节点]删除元素位置参数出错！\n");
		return 0;
	}
	*deletenode = p->data;//用指针返回被删除元素
	delp = p->next;
	p->next = p->next->next;//把p的后继的后继作为后继
	free(delp);//释放
	return 1;
}

//释放链表
int ListDestory(Node** head) {
	Node* p1, * p2;
	p1 = *head;
	while (p1->next != NULL) {
		p2 = p1->next;//用p2保存下一个节点指针
		free(p1);
		p1 = p2;
	}
	*head = NULL;//head置空
	return 1;
}

//交换节点
int ListExchange(Node* a, Node* b) {
	if (a == NULL || b == NULL) {
		printf("[交换节点]指针不能为空！\n");
		return 0;
	}
	type temp = a->data;
	a->data = b->data;
	b->data = temp;
	return 1;
}

//升序排列
int ListAscend(Node** head) {
	Node* p, * index;
	if ((*head)->next == NULL) {
		printf("[升序排列]链表为空！\n");
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

//降序排列
int ListDescend(Node** head) {
	Node* p, * index;
	if ((*head)->next == NULL) {
		printf("[降序排列]链表为空！\n");
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

//复制链表
int ListCopy(Node* head1,Node** head2) {
	Node* p1 = head1->next;
	Node* p2 = NULL;
	Node* newnode;
	Node* tail = *head2;
	while (p1 != NULL) {
		if ((newnode = (Node*)malloc(sizeof(Node))) == NULL) {
			printf("[复制链表]内存块分配失败！\n");
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

//查找节点
int ListFind(Node* head, type x, int i) {//从i开始查找data为x的节点
	Node* p = head->next;
	int j = -1;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("[查找节点]删除元素位置参数出错！\n");
		return 0;
	}
	while (p->next != NULL) {
		if (p->data == x)
			return 1;//找到
		p = p->next;
	}
	return -1;//未找到
}

//获取长度
int ListLen(Node* head) {
	Node* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//链表逆置
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

//批量删除
int ListDeleteMore(Node* head, type x) {
	Node* p = head->next;
	Node* prev = head;
	int deleted = 0;
	while (p != NULL) { 
		if (p->data == x) {
			Node* delp = p;
			prev->next = p->next;
			p = p->next;
			free(delp);//释放
			deleted = 1;
		}
		else {
			prev = p;
			p = p->next;//仅不删除节点时
		}
	}
	return deleted;
}

//判断子集
int ListSubset(Node* head1, Node* head2) {
	Node* p1, * p2;
	p1 = head1;
	p2 = head2;
	int flag = 0;
	while (p1 != NULL) {
		p2 = head2;//迭代时重置
		flag = 0;
		while (p2 != NULL) {
			if (p2->data == p1->data) {
				flag = 1;
				break;//找到时退出内部循环
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
		printf("取元素位置参数出错！");
		return 0;
	}
	*x = p->data;
	return 1;
}

//链表操作菜单
int ListMenu(Node** head) {
	int flag = -2;
	int counts;
	printf("[操作信息]......\n");
	while (flag != -1) {
		printf("================链表操作菜单=================\n");
		printf("创建链表【0】   插入节点【1】   打印链表【2】\n");
		printf("复制链表【3】   查找节点【4】   获取长度【5】\n");
		printf("升序排列【6】   降序排列【7】   链表逆置【8】\n");
		printf("交换节点【9】   删除节点【10】  释放链表【11】\n");
		printf("批量删除【12】  判断子集【13】  获取元素【14】\n");
		printf("退出菜单【-1】\n");
		printf("=============================================\n");
		printf("选择操作：");
		scanf_s("%d", &flag);
		switch (flag) {
		    case -1:
			    return 1;

		    case 0:
			    ListIntitiate(head);
				system("cls");
				printf("[创建链表]创建链表成功！\n");
			    break;

		    case 1:
			    printf("请输入要插入的节点位置：");
			    int place;
			    scanf_s("%d", &place);
			    printf("请输入要插入的节点数据：");
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
					printf("[插入节点]插入节点成功！\n");
				else
					printf("[插入节点]插入节点失败！\n");
			    break;

			case 2:
				system("cls");
				printf("[打印链表]");
				ListPrint(*head);
				printf("\n");
				break;

			case 3:
				system("cls");
				printf("[复制链表]失败，请单独调用函数ListCpoy：int ListCopy(Node* head1,Node** head2)\n");
				break;

			case 4:
				type findnode;
				int i;
				printf("请输入要查找的节点数据：");
				scanf_s(TYPE, &findnode);//!
				printf("请输入起始搜索节点：");
				scanf_s("%d", &i);
				system("cls");
				if (ListFind(*head, findnode, i) == 1)
					printf("[查找节点]已找到。\n");
				else
					printf("[查找节点]未找到。\n");
				break;

			case 5:
				system("cls");
				printf("[获取长度]");
				printf(TYPE, ListLen(*head));
				printf("\n");
				break;

			case 6:
				system("cls");
				if(ListAscend(head)==1)
					printf("[升序排列]排列完成！\n");
				else
					printf("[升序排列]排列失败！\n");
				break;

			case 7:
				system("cls");
				if (ListDescend(head) == 1)
					printf("[降序排列]排列完成！\n");
				else
					printf("[降序排列]排列失败！\n");
				break;

			case 8:
				system("cls");
				if (ListReverse(head) == 1)
					printf("[链表逆置]排列完成！\n");
				else
					printf("[链表逆置]排列失败！\n");
				break;

			case 9:
				system("cls");
				printf("[交换节点]失败，请单独调用函数ListExchange：int ListExchange(Node * a, Node * b)\n");
				break;

			case 10:
				system("cls");
				printf("[删除节点]失败，请单独调用函数ListDelete：int ListDelete(Node* head, int i, type* deletenode)\n");
				break;

			case 11:
				system("cls");
				ListDestory(head);
				printf("[释放链表]成功释放链表！\n");
				break;
			
			case 12:
				printf("请输入要删除的元素的data域：");
				type del_data;
				scanf_s(TYPE, &del_data);//!
				system("cls");
				counts = ListDeleteMore(*head, del_data);
				printf("[批量删除]删除成功！\n", counts);
				break;

			case 13:
				system("cls");
				printf("[判断子集]失败，请单独调用函数ListSubset：int ListSubset(Node* head1, Node* head2)\n");
				break;

			case 14:
				int n;
				printf("请输入要获取的元素节点序号：");
				scanf_s("%d", &n);
				system("cls");
				printf("[获取元素]");
				type* x;
				ListGet(*head, n, x);
				printf(TYPE, *x);
				printf("\n");
				break;

			default:
				system("cls");
				printf("无效的操作！\n");
				break;
		}
	}
	return 1;
}

// Copyright(C) 2023 ZYX, All Rights Reserved
//
// @Author  : ZYX in Cyberspace Security Class 2 of DGUT
// @File    : link.h