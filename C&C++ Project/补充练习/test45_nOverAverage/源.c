#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*定义结点*/
typedef struct NumList {
    int num;
    struct NumList* next;
} NumList;

/*开辟空间与建立链表*/
NumList* mallocNum(int n) {
    NumList* head = NULL;
    NumList* p = NULL;
    NumList* num = NULL;

    head = (NumList*)malloc(sizeof(NumList));
    if (head == NULL) {
        printf("分配储存块失败！");
        exit(0);
    }

    printf("num[0]=");
    scanf("%d", &(head->num));
    head->next = NULL;
    p = head;

    for (int i = 1; i < n; i++) {
        num = (NumList*)malloc(sizeof(NumList));
        if (num == NULL) {
            printf("分配储存块失败！");
            exit(0);
        }

        printf("num[%d]=", i);
        scanf("%d", &(num->num));
        num->next = NULL;
        p->next = num;
        p = num;
    }

    return head;  //传递首地址
}

/*求平均值与查找结点*/
int searchList(NumList* head) {
    NumList* p = head;
    int sum = 0, count = 0, i = 0;

    while (p != NULL) {
        sum += p->num;
        p = p->next;
        i++;
    }

    double aver = sum / (double)i;
    p = head; // 重新定位到链表头部

    while (p != NULL) {
        if (p->num > aver) {
            count++;
        }
        p = p->next;
    }

    return count;
}

int main() {
    printf("请输入正整数n：");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("n值不为正整数!");
        exit(0);
    }
    else {
        NumList* head = mallocNum(n);
        printf("这%d个整数中超出平均数的个数为%d\n", n, searchList(head));
    }

    return 0;
}