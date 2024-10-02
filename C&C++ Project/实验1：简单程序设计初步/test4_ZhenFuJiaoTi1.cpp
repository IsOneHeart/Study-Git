#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
    int main() 
    {
        int n;
        double sum = 0.0;
        printf("输入正整数n: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("输入的数应为正整数。\n");
        }
        else {
            for (int i = 1; i <= n; i++) 
            {
                int deno = 2 * i - 1;  // 分母，奇数递增
                double term = pow(-1, i - 1) / deno;  // 当前项
                sum += term;  // 累加到总和
            }
            printf("前%d项的和约为%.2lf\n", n, sum);
        }
        return 0;
    }