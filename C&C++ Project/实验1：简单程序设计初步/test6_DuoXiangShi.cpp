#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    double n,x;
    double S = 0.0;
    printf("����ʵ��n��Ϊ��ߴ���: ");
    scanf("%lf", &n);
    printf("����ʵ��x��Ϊ����: ");
    scanf("%lf", &x);
    for (int i = 1; i <= n; i++)
        {
            double power = pow(x, i) ;  // ��ǰ��
            S += power;  // �ۼӵ��ܺ�
        }
        printf("S=%.2lf\n", S);
    return 0;
}