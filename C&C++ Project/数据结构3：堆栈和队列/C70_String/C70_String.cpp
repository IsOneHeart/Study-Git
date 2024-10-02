#include <stdio.h>
#include "XString.h"

int main() {
    Str str1, str2;
    StrInitiate(&str1, 10, "Hello");
    StrInitiate(&str2, 10, "World");

    // 测试字符串插入
    StrInsert(&str1, 2, str2);
    printf("插入后的字符串: %s\n", str1.str);

    // 测试字符串删除
    StrDelete(&str1, 2, 2);
    printf("删除后的字符串: %s\n", str1.str);

    // 测试字符串子串
    Str subStr;
    StrSub(&str1, 1, 2, &subStr);
    printf("子串: %s\n", subStr.str);

    // 测试字符串比较
    if (StrCompare(&str1, &str2)==1) {
        printf("S1>S2\n");
    }
    else if (StrCompare(&str1, &str2) == -1) {
        printf("S1<S2\n");
    }
    else
        printf("S1=S2\n");

    // 测试暴力搜索算法
    int index = BruteForce(str1, 0, subStr);
    if (index != -1) {
        printf("子串在原字符串中的位置: %d\n", index);
    }
    else {
        printf("未找到子串\n");
    }

    // 释放内存
    StrDestory(&str1);
    StrDestory(&str2);
    StrDestory(&subStr);

    return 0;
}