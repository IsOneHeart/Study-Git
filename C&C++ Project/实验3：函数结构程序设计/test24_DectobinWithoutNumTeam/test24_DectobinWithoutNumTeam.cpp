#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long dectobin(int n) {
    int depNum = 0, ws = 0;
    long transform = 0;
    while (n!=0) {
        depNum = n % 2;
        n /= 2;
        for (int i = 0;i < ws;i++) 
            depNum *= 10;
        transform += depNum;
        ws++;
    }
    return transform;
}
int main() {
    int n;
    printf("������һ��������n��");
    scanf("%d", &n);
    printf("��������%d��ʮ������Ϊ", n);
    printf("%ld", dectobin(n));
    return 0;
}