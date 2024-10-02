#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DataType int
#define MaxQuenceSize 16

#include "E:/StudyE/C&C++/数据结构3：堆栈和队列/C67_OrderQuenceOnlyWithFront/OrderQuenceOnlyWithFront.h"

void RadixSort(int a[], int n, int m, int d) {
    int i, j, k, power = 1;
    FQNode *tub = (FQNode *) malloc(sizeof(FQNode) * d);
    for (i = 0; i < d; i++) {
        FQInitiate(&tub[i]); //初始化d个队列
    }
    for (i = 0; i < m; i++) {
        if (i == 0) {
            power = 1;
        } else
            power *= d;
        //将数据元素按关键字第k位的数值放到相应的队列中
        for (j = 0; j < n; j++) {
            k = a[j] / power - (a[j] / (power * d)) * d;
            FQAppend(&tub[k], a[j]);
        }
        //将d个队列中的数据元素依次出队，存放到数组a中
        k = 0;
        for (j = 0; j < d; j++) {
            while (FQNotEmpty(tub[j]) != 0) {
                FQDelete(&tub[j], &a[k]);
                k++;
            }
        }
    }
    free(tub);
}

void getRandomNum0To1000(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}

int main() {
    srand(time(NULL));
    int a[10];
    getRandomNum0To1000(a, 10);
    printf("基数排序前：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    RadixSort(a, 10, 4, 10);
    printf("\n基数排序后：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
