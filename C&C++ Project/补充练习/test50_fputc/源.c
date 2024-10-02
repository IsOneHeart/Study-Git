//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义链表结构
typedef struct c {
    char c;
    struct c* next;
} c;

// 创建链表函数
c* clink() {
    c* head = NULL, * p = NULL, * word = NULL;
    char input;

    // 循环读取用户输入字符，构建链表
    while (1) {
        if ((word = (c*)malloc(sizeof(c))) == NULL) {
            printf("分配内存块失败！\n");
            exit(0);
        }
        scanf("%c", &input);
        if (input == '#') {
            free(word); // 释放最后一个节点的内存
            break;//结束循环
        }
        word->c = input;
        word->next = NULL;
        if (head == NULL) {
            head = word;
            p = head;
        }
        else {
            p->next = word;
            p = word;
        }
    }
    return head;
}

int main() {
    FILE* fp;
    c* head = NULL, * p = NULL;

    // 提示用户输入文本
    printf("请输入要储存在mydata.dat中的文本（以#结束）：\n");

    // 创建链表
    head = clink();
    p = head;

    // 打开文件
    if ((fp = fopen_s(&fp,"mydata.dat", "a+")) == NULL) {
        printf("文件打开失败！\n");
        exit(0);
    }

    // 将链表中的字符写入文件
    while (p != NULL) {
        fputc(p->c, fp);
        p = p->next;
    }

    // 释放链表内存
    p = head;
    while (p != NULL) {
        c* temp = p;
        p = p->next;
        free(temp);
    }

    // 关闭文件
    if (fclose(fp) != 0) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }

    return 0;
}