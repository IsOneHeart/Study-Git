#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void dectobin(int n) {
    int depNum[32], n_ = n;// ��������洢����������ÿһλ,��n_����n
    for (int i = 0; i <32; i++) {// ��ʼ������
        depNum[i] = 0;
    }
    int index = 0;// ��ʼ������
    while (n> 0) { // ��ʮ������ת��Ϊ������
        depNum[index] = n % 2;
        n = n / 2;
        index++;
    }
    printf("��������%d��ʮ������Ϊ", n_);
    for (int i = index - 1; i >= 0; i--) // ������ĸ�λ����λ�����������
        printf("%d", depNum[i]);
    printf("\n");
}
int main() {
    int n;
    printf("������һ��������n��");
    scanf("%d", &n);
    dectobin(n);
    return 0;
}