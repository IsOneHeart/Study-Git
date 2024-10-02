#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void getRandomNum0To1000(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}

void copyArray(int src[], int dest[], int n) { // 复制数组
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void copyCount(count src, count *dest) {
    dest->compare = src.compare;
    dest->move = src.move;
}

int main() {
    int n = 10;
    int array[n], array2[n], array3[n];
    srand(time(NULL));
    getRandomNum0To1000(array, n);
    copyArray(array, array2, n);
    copyArray(array, array3, n);
    printf("排序前：");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n堆排序后：");
    count c = heapSort(array, n); //获取比较次数和移动次数
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("（比较次数：%d，移动次数：%d）", c.compare, c.move);
    printf("\n快速排序后：");
    count c2 = quickSort(array2, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", array2[i]);
    }
    printf("（比较次数：%d，移动次数：%d）", c2.compare, c2.move);
    printf("\n归并排序后：");
    count c3 = mergeSort(array3, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", array2[i]);
    }
    printf("（比较次数：%d，移动次数：%d）", c3.compare, c3.move);
    return 0;
}
