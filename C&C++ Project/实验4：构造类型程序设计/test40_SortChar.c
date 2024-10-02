/*��дsort������ʵ�ֶ�n���ַ������Ӵ�С��������
��������������5�ַ���������sort������5���ַ���s��������Ȼ�������������
���磺�����ַ���Li Xiao Wang Zhang Yu�����Zhang Yu Xiao Wang Li��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MaxSize 32

// ���������ַ����ĺ���
void swapStrings(char* a, char* b) {
    char temp[MaxSize];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// ������
void sort(char strings[MaxSize][MaxSize], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) < 0) {
                // ���������ַ���
                swapStrings(strings[j], strings[j + 1]);
            }
        }
    }
}

int main() {
    char strings[MaxSize][MaxSize];
    int i, n;
    printf("�������ַ�������n��");
    scanf("%d", &n);
    printf("������%d���ַ���\n", n);

    // �����ַ�������
    for (i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // �������������ַ��������������
    sort(strings, n);

    printf("\n�Ӵ�С�������ַ�����\n");

    // ����������ַ�������
    for (i = 0; i < n; i++) {
        printf("%s ", strings[i]);
    }

    return 0;
}