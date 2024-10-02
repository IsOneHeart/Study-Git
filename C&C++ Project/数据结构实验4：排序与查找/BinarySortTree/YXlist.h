#pragma once
#include <stdlib.h>
#ifndef type
#define type int
#endif
#ifndef TYPE
#define TYPE "%d"
#endif

typedef struct Node {
    type data;
    struct Node* next;
}Node;

//创建链表
int ListInitiate(Node** head) {
    if ((*head = (Node*)malloc(sizeof(Node))) == NULL){
        printf("[创建链表]内存块分配失败！\n");
        return 0;
    }
    (*head)->next = NULL;
    return 1;
}

//插入节点
int ListInsert(Node* head, int i, type newdata) {
    int count=0;
    Node* p, *newnode;
    p = head;
    int j = -1;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
        count++;
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
    count+=3;
    return count;
}

//打印链表数据
int ListPrint(Node* head) {
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
        printf(TYPE" ",p->data);
    }
    return 1;
}

//删除节点
int ListDelete(Node* head, int i, type* deletenode) {
    Node* p, *delp;
    p = head;
    int j = -1,count=0;
    while (p->next != NULL && p->next->next != NULL && j < i - 1) {
        p = p->next;
        j++;
        count++;
    }
    if (j != i - 1) {
        printf("[删除节点]删除元素位置参数出错！\n");
        return 0;
    }
    *deletenode = p->data;//用指针返回被删除元素
    delp = p->next;
    p->next = p->next->next;//把p的后继的后继作为后继
    free(delp);//释放
    count+=2;
    return count;
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