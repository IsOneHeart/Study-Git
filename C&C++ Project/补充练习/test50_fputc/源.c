//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��������ṹ
typedef struct c {
    char c;
    struct c* next;
} c;

// ����������
c* clink() {
    c* head = NULL, * p = NULL, * word = NULL;
    char input;

    // ѭ����ȡ�û������ַ�����������
    while (1) {
        if ((word = (c*)malloc(sizeof(c))) == NULL) {
            printf("�����ڴ��ʧ�ܣ�\n");
            exit(0);
        }
        scanf("%c", &input);
        if (input == '#') {
            free(word); // �ͷ����һ���ڵ���ڴ�
            break;//����ѭ��
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

    // ��ʾ�û������ı�
    printf("������Ҫ������mydata.dat�е��ı�����#��������\n");

    // ��������
    head = clink();
    p = head;

    // ���ļ�
    if ((fp = fopen_s(&fp,"mydata.dat", "a+")) == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }

    // �������е��ַ�д���ļ�
    while (p != NULL) {
        fputc(p->c, fp);
        p = p->next;
    }

    // �ͷ������ڴ�
    p = head;
    while (p != NULL) {
        c* temp = p;
        p = p->next;
        free(temp);
    }

    // �ر��ļ�
    if (fclose(fp) != 0) {
        printf("���������ر��ļ���\n");
        exit(0);
    }

    return 0;
}