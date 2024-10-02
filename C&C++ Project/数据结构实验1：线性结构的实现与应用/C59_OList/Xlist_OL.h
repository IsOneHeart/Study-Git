#pragma once
typedef struct OList {
    type* array;
    int size;
}OList;

int ListSort(OList* list) {
    type temp;
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (list->array[j] > list->array[j + 1]) {
                temp = list->array[j];
                list->array[j] = list->array[j + 1];
                list->array[j + 1] = temp;
            }
        }
    }
    return 1;
}

int ListInitiate(OList* list, int size) {
    //list = (OList*)malloc(sizeof(OList));
    list->size = size;
    if (list->size == 0)
        return 1;
    list->array = (type*)calloc(size, sizeof(type));
    if (list->array == NULL) {
        printf("内存块分配失败！");
        return 0;
    }
    for (int i = 0;i < size;i++) {
        printf("[%d]", i);
        scanf(TYPE, &list->array[i]);
        getchar();
    }
    ListSort(list);
    return 1;
}

int ListSize(OList* list) {
    return list->size;
}

int ListInsert(OList* list,type newc) {
    list->size++;
    list->array = (type*)realloc(list->array, list->size * sizeof(type));
    if (list->array == NULL) {
        printf("内存块分配失败！");
        return 0;
    }
    list->array[list->size - 1] = newc;
    ListSort(list);
    return 1;
}

int ListGet(OList* list, int i, type* c) {
    if (i >= list->size)
        return 0;
    *c = list->array[i];
    return 1;
}

int ListDelete(OList* list, int i) {
    for (int j = i;j < list->size;j++) {
        list->array[j] = list->array[j + 1];
    }
    list->size--;
    list->array = (type*)realloc(list->array, list->size * sizeof(type));
    if (list->array == NULL) {
        printf("内存块分配失败！");
        return 0;
    }
    return 1;
}

void ListMerge(OList* L1, OList* L2, OList* L3) {
    int size1 = L1->size;
    int size2 = L2->size;
    int total_size = size1 + size2;

    // 分配足够的空间给 L3
    L3->array = (type*)malloc(total_size * sizeof(type));
    L3->size = total_size;

    int i = 0, j = 0, k = 0;

    // 依次比较 L1 和 L2 的元素，将较小的元素添加到 L3 中
    while (i < size1 && j < size2) {
        if (L1->array[i] <= L2->array[j]) {
            L3->array[k++] = L1->array[i++];
        }
        else {
            L3->array[k++] = L2->array[j++];
        }
    }

    // 将剩余的元素添加到 L3 中
    while (i < size1) {
        L3->array[k++] = L1->array[i++];
    }
    while (j < size2) {
        L3->array[k++] = L2->array[j++];
    }
}

int ListPrint(OList* list) {
    for (int i = 0;i < list->size; i++) {
        printf(TYPE, list->array[i]);
        //printf(" ");
    }
    printf("\n");
    return 1;
}