#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
    int main() 
    {
        int n;
        double sum = 0.0;
        printf("����������n: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("�������ӦΪ��������\n");
        }
        else {
            for (int i = 1; i <= n; i++) 
            {
                int deno = 2 * i - 1;  // ��ĸ����������
                double term = pow(-1, i - 1) / deno;  // ��ǰ��
                sum += term;  // �ۼӵ��ܺ�
            }
            printf("ǰ%d��ĺ�ԼΪ%.2lf\n", n, sum);
        }
        return 0;
    }