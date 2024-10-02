//使用函数重载求2个整数或3个整数的和

#include <stdio.h>

int sum(int n1, int n2) {
    return n1 + n2;
}

int sum(int n1, int n2, int n3) {
    return n1 + n2 + n3;
}

int main()
{
    printf("18+21=%d\n", sum(18, 21));
    printf("2022+4+4=%d\n", sum(2022, 4, 4));
    return 0;
}
