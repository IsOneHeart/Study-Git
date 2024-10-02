#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char type;
#define TYPE "%c"
#include "Xlist_OL.h"

int main() {
    OList *list1,  *list2, *list3;
    list1 = (OList*)malloc(sizeof(OList));
    list2 = (OList*)malloc(sizeof(OList));
    printf("输入list1：\n");
    ListInitiate(list1, 3);
    printf("输入list2：\n");
    ListInitiate(list2, 3);

    type c2;
    ListGet(list1, 1, &c2);
    printf("list1第2个元素是%c\n", c2);

    printf("list1：");
    ListPrint(list1);
    printf("list2：");
    ListPrint(list2);

    printf("向list1插入字符c\n");
    ListInsert(list1, 'c');
    printf("list1：");
    ListPrint(list1);
    printf("list1有%d个元素\n", ListSize(list1));

    printf("向list1删除第1个字符\n");
    ListDelete(list1,1);
    printf("list1：");
    ListPrint(list1);
    printf("list1有%d个元素\n", ListSize(list1));

    list3 = (OList*)malloc(sizeof(OList));
    ListInitiate(list3,0);
    list3 = (OList*)malloc(sizeof(OList));
    ListMerge(list1, list2, list3);
    printf("list3：");
    ListPrint(list3);
    return 0;
}