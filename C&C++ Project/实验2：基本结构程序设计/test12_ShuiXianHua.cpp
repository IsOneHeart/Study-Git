#include <stdio.h>
int main() {
    printf("1-10000的水仙花数：\n");
    int N=0;//用N计数水仙花数
    for (int num = 1; num <= 10000; num++) {
        int storeN = num;//用storeN储存num
        int sum = 0;//用sum保存每位数字的立方和，每个for循环结束后归零
        while (storeN > 0) {
            int digit = storeN % 10;//分解storeN
            sum += digit * digit * digit;
            storeN/= 10;//减小storeN值，进入下一个循环求下一位数
        }

        if (sum == num) {
            printf("%d\n", num);
            ++N;
        }
    }
    printf("一共有%d个", N);
    return 0;
}