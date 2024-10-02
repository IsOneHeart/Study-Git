#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    double n,x;
    double S = 0.0;
    printf("输入实数n作为最高次幂: ");
    scanf("%lf", &n);
    printf("输入实数x作为底数: ");
    scanf("%lf", &x);
    for (int i = 1; i <= n; i++)
        {
            double power = pow(x, i) ;  // 当前项
            S += power;  // 累加到总和
        }
        printf("S=%.2lf\n", S);
    return 0;
}