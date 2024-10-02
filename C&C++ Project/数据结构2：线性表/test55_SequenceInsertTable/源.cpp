#include <stdio.h>
#define MaxSize 10
#define TYPE "%d"
typedef int type;
typedef struct SL {
    type data[MaxSize];
    int size;
} SL;

int ListFind(SL* List, int i, type x) {
    for (int j = 0;j <= List->size;j++) {
        if (j >= i && List->data[j] == x)
            return j;
    }
    return -1;
}

int SLInsert(SL* List, int i, type x) {
    int j;
    if (List->size >= MaxSize) {
        printf("˳����������޷����룡");
        return 0;
    }
    else if (i < 0 || i > List->size) {
        printf("�������Ϸ���");
        return 0;
    }
    else {
        for (j = List->size; j > i; j--)
            List->data[j] = List->data[j - 1]; //����
        List->data[i] = x;
        List->size++;
        return 1;
    }
}

int SLReserve(SL* List) {
    type temp;
    for (int j = 0;j < List->size / 2;j++) {
        temp = List->data[j];
        List->data[j] = List->data[List->size-1 - j];
        List->data[List->size-1 - j] = temp;
    }
    return 1;
}

int main() {
    SL List;
    List.size = 0;
    for (int i = 0; i < 6; i++) {
        List.data[i] = i;
        List.size++;
    }
    printf("��˳����е�һ������3��Ԫ�������%d\n", ListFind(&List, 0, 3));
    if (SLInsert(&List, 3, 6))
        printf("����ɹ���\n");
    else
        printf("����ʧ�ܣ�\n");

    for (int i = 0; i < List.size; i++) {
        printf("List.data[%d]=", i);
        printf(TYPE, List.data[i]);
        printf("\n");
    }

    SLReserve(&List);

    printf("���ú�\n");
    for (int i = 0; i < List.size; i++) {
        printf("List.data[%d]=", i);
        printf(TYPE, List.data[i]);
        printf("\n");
    }
    return 0;
}