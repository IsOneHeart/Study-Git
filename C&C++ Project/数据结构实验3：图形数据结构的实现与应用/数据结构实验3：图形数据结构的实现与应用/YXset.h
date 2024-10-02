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

//创建链表
int SetInitiate(SLNode** head) {
	if ((*head = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
		printf("[创建链表]内存块分配失败！\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//打印链表数据
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

//删除节点
int SetDelete(SLNode* head, int i, DataType* deletenode) {
	SLNode* p, * delp;
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
int SetDestory(SLNode** head) {
	SLNode* p1, * p2;
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
int SetExchange(SLNode* a, SLNode* b) {
	if (a == NULL || b == NULL) {
		printf("[交换节点]指针不能为空！\n");
		return 0;
	}
	DataType temp = a->data;
	a->data = b->data;
	b->data = temp;
	return 1;
}

//查找节点
int SetFind(SLNode* head, DataType x) {
	SLNode* p = head->next;
	while (p != NULL) {
		if (HOWFIND)
			return 1;//找到
		p = p->next;
	}
	return NULL;//未找到
}

//插入节点
int SetInsert(SLNode* head, int i, DataType newdata) {
	//if (SetFind(head, newdata) == 1)//该元素已在集合中
	//	return 0;
	//else {
		SLNode* p, * newnode;
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
		if ((newnode = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
			printf("[插入节点]内存块分配失败！\n");
			return 0;
		}
		newnode->data = newdata;//赋值
		p->next = newnode;
	//}
	return 1;
}

//复制链表
int SetCopy(SLNode* head1, SLNode** head2) {
	SLNode* p1 = head1->next;
	SLNode* p2 = NULL;
	SLNode* newnode;
	SLNode* tail = *head2;
	while (p1 != NULL) {
		if ((newnode = (SLNode*)malloc(sizeof(SLNode))) == NULL) {
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

//求交集
//int SetIntersection(SLNode* head1,SLNode* head2,SLNode* head3) {
//	if (head1->next == NULL || head2->next == NULL)
//		//交集为空
//		return 0;
//	else {
//		SLNode* p1 = head1->next;
//		int flag = 0;//标记是否有交集
//		while (p1 != NULL ) {
//			if (SetFind(head2, p1->data) == 1) {
//				SetInsert(head3, 0, p1->data);
//				flag = 1;
//			}
//			p1 = p1->next;
//		}
//		if (flag == 1)
//			return 1;
//		return 0;//交集为空
//	}
//}

////求差集
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

//求并集
int SetUnion(SLNode* head1, SLNode* head2, SLNode* head3) {
	SetCopy(head1, &head3);
	SLNode* p = head2->next;
	while (p != NULL) {
		SetInsert(head3, 0, p->data);
		p = p->next;
	}
	return 1;
}

//升序排列
void SetSort(SLNode* head) {
	SLNode* p, * index, * pre, * temp;
	if (head->next == NULL) {
		printf("链表为空！\n");
	}
	else {
		// 创建临时头节点
		SLNode* tempHead = (SLNode*)malloc(sizeof(SLNode));
		tempHead->next = head->next;

		// 冒泡排序
		for (p = tempHead; p->next != NULL; p = p->next) {
			for (index = p->next; index->next != NULL; index = index->next) {
				if (p->next->DATA > index->next->DATA) {
					// 交换节点指针
					temp = index->next;
					index->next = temp->next;
					temp->next = p->next;
					p->next = temp;

					// 调整指针位置
					pre = index;
					index = temp;
					temp = pre;
				}
			}
		}

		// 更新原链表头节点
		head->next = tempHead->next;
		free(tempHead); // 释放临时头节点
	}
}

//获取长度
int SetLen(SLNode* head) {
	SLNode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//判断子集
//int SetSubset(SLNode* head1, SLNode* head2) {
//	SLNode* p1, * p2;
//	p1 = head1;
//	p2 = head2;
//	int flag = 0;
//	while (p1 != NULL) {
//		p2 = head2;//迭代时重置
//		flag = 0;
//		while (p2 != NULL) {
//			if (p2->data == p1->data) {
//				flag = 1;
//				break;//找到时退出内部循环
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
		printf("取元素位置参数出错！");
		return 0;
	}
	*x = p->data;
	return 1;
}
