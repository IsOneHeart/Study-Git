/*编写sort函数，实现对n个字符串按从大到小进行排序。
在主程序中输入5字符串，调用sort函数对5个字符串s进行排序，然后输出排序结果。
例如：输入字符串Li Xiao Wang Zhang Yu，输出Zhang Yu Xiao Wang Li。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MaxSize 32

// 交换两个字符串的函数
void swapStrings(char* a, char* b) {
    char temp[MaxSize];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// 排序函数
void sort(char strings[MaxSize][MaxSize], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) < 0) {
                // 交换两个字符串
                swapStrings(strings[j], strings[j + 1]);
            }
        }
    }
}

int main() {
    char strings[MaxSize][MaxSize];
    int i, n;
    printf("请输入字符串个数n：");
    scanf("%d", &n);
    printf("请输入%d个字符：\n", n);

    // 输入字符串数组
    for (i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // 调用排序函数对字符串数组进行排序
    sort(strings, n);

    printf("\n从大到小排序后的字符串：\n");

    // 输出排序后的字符串数组
    for (i = 0; i < n; i++) {
        printf("%s ", strings[i]);
    }

    return 0;
}