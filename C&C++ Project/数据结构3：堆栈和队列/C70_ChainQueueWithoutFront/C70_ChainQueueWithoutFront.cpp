#include <stdio.h>
#include <stdlib.h>
typedef char type;
#include "ChainQueueWithoutFront.h"

int main() {
    Queue q;
    QueueInitiate(&q);

    // 测试入队列
    for (int i = 1; i <= 5; i++) {
        QueueAppend(&q, i);
    }

    // 测试出队列
    type data;
    while (QueueDelete(&q, &data)) {
        printf("%d ", data);
    }

    // 测试释放队列
    QueueDestory(&q);

    return 0;
}