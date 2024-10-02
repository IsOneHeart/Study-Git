#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void dectobin(int n) {
    int depNum[32], n_ = n;// 创建数组存储二进制数的每一位,用n_储存n
    for (int i = 0; i <32; i++) {// 初始化数组
        depNum[i] = 0;
    }
    int index = 0;// 初始化索引
    while (n> 0) { // 将十进制数转换为二进制
        depNum[index] = n % 2;
        n = n / 2;
        index++;
    }
    printf("二进制数%d的十进制数为", n_);
    for (int i = index - 1; i >= 0; i--) // 从数组的高位到低位输出二进制数
        printf("%d", depNum[i]);
    printf("\n");
}
int main() {
    int n;
    printf("请输入一个正整数n：");
    scanf("%d", &n);
    dectobin(n);
    return 0;
}