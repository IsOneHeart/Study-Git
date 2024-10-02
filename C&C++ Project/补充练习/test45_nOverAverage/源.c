#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*������*/
typedef struct NumList {
    int num;
    struct NumList* next;
} NumList;

/*���ٿռ��뽨������*/
NumList* mallocNum(int n) {
    NumList* head = NULL;
    NumList* p = NULL;
    NumList* num = NULL;

    head = (NumList*)malloc(sizeof(NumList));
    if (head == NULL) {
        printf("���䴢���ʧ�ܣ�");
        exit(0);
    }

    printf("num[0]=");
    scanf("%d", &(head->num));
    head->next = NULL;
    p = head;

    for (int i = 1; i < n; i++) {
        num = (NumList*)malloc(sizeof(NumList));
        if (num == NULL) {
            printf("���䴢���ʧ�ܣ�");
            exit(0);
        }

        printf("num[%d]=", i);
        scanf("%d", &(num->num));
        num->next = NULL;
        p->next = num;
        p = num;
    }

    return head;  //�����׵�ַ
}

/*��ƽ��ֵ����ҽ��*/
int searchList(NumList* head) {
    NumList* p = head;
    int sum = 0, count = 0, i = 0;

    while (p != NULL) {
        sum += p->num;
        p = p->next;
        i++;
    }

    double aver = sum / (double)i;
    p = head; // ���¶�λ������ͷ��

    while (p != NULL) {
        if (p->num > aver) {
            count++;
        }
        p = p->next;
    }

    return count;
}

int main() {
    printf("������������n��");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("nֵ��Ϊ������!");
        exit(0);
    }
    else {
        NumList* head = mallocNum(n);
        printf("��%d�������г���ƽ�����ĸ���Ϊ%d\n", n, searchList(head));
    }

    return 0;
}