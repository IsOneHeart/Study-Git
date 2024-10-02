#include <stdio.h>
#include <stdlib.h>
typedef int type;
#include"Xquence.h"

int main() {
    Quence Q;
    type data;

    QuenceInitiate(&Q);

    // 测试入队
    QuenceAppend(&Q, 10);
    QuenceAppend(&Q, 20);
    QuenceAppend(&Q, 30);
    QuencePrint(&Q);
    printf("\n");

    // 测试取队首元素
    QuenceGet(Q, &data);
    printf("队首元素为: %d\n", data);
    QuencePrint(&Q);
    printf("\n");

    // 测试出队
    QuenceDelete(&Q, &data);
    printf("出队元素为: %d\n", data);
    QuencePrint(&Q);
    printf("\n");

    // 测试销毁队列
    QuenceDestory(&Q);

    return 0;
}