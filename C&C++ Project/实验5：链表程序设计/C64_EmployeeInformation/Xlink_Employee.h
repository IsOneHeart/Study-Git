#pragma once
#include <stdlib.h>
#define TYPE "%d"

typedef struct EINode {
	char name[15];
	int salary;
	struct EINode* next;
}EINode;

//创建链表
int EIListInitiate(EINode** head) {
	if ((*head = (EINode*)malloc(sizeof(EINode))) == NULL) {
		printf("[创建链表]内存块分配失败！\n");
		return 0;
	}
	(*head)->next = NULL;
	return 1;
}

//插入节点
int EIListInsert(EINode* head, int i, char* newname, int newsalary) {
	EINode* p, * newEINode;
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
	if ((newEINode = (EINode*)malloc(sizeof(EINode))) == NULL) {
		printf("[插入节点]内存块分配失败！\n");
		return 0;
	}
	strcpy(newEINode->name, newname);
	//*(newEINode->name) = *newname;
	newEINode->salary = newsalary;//赋值
	newEINode->next = p->next;//插入节点,p->next为a[i]
	p->next = newEINode;
	return 1;
}

//打印链表数据
int EIListPrint(EINode* head) {
	EINode* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%s %d ", p->name, p->salary);
	}
	return 1;
}

//删除节点
int EIListDelete(EINode* head, int i, char* deletename, int* deletesalary) {
	EINode* p, * delp;
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
	strcpy(deletename, p->name);
	//deletename = p->name;
	*deletesalary = p->salary;//用指针返回被删除元素
	delp = p->next;
	p->next = p->next->next;//把p的后继的后继作为后继
	free(delp);//释放
	return 1;
}

//释放链表
int EIListDestory(EINode** head) {
	EINode* p1, * p2;
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
int EIListExchange(EINode* a, EINode* b) {
	if (a == NULL || b == NULL) {
		printf("[交换节点]指针不能为空！\n");
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

//升序排列
int EIListAscend(EINode** head) {
	EINode* p, * index;
	if ((*head)->next == NULL) {
		printf("[升序排列]链表为空！\n");
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

//降序排列
int EIListDescend(EINode** head) {
	EINode* p, * index;
	if ((*head)->next == NULL) {
		printf("[降序排列]链表为空！\n");
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

//复制链表
int EIListCopy(EINode* head1, EINode** head2) {
	EINode* p1 = head1->next;
	EINode* p2 = NULL;
	EINode* newEINode;
	EINode* tail = *head2;
	while (p1 != NULL) {
		if ((newEINode = (EINode*)malloc(sizeof(EINode))) == NULL) {
			printf("[复制链表]内存块分配失败！\n");
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

//查找节点
int EIListFind(EINode* head, int x, int i) {//从i开始查找salary为x的节点
	EINode* p = head->next;
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
		if (p->salary == x)
			return 1;//找到
		p = p->next;
	}
	return -1;//未找到
}

//获取长度
int EIListLen(EINode* head) {
	EINode* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

//链表逆置
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

//批量删除
int EIListDeleteMore(EINode* head, int x) {
	EINode* p = head->next;
	EINode* prev = head;
	int deleted = 0;
	while (p != NULL) {
		if (p->salary == x) {
			EINode* delp = p;
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

int EIListGet(EINode* head, int n, char* name, int* x) {
	EINode* p = head;
	int j = -1;
	while (p->next != NULL && j < n) {
		p = p->next;
		j++;
	}
	if (j != n) {
		printf("取元素位置参数出错！");
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