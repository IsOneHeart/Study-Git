#include <stdio.h>
int main() {
    printf("1-10000��ˮ�ɻ�����\n");
    int N=0;//��N����ˮ�ɻ���
    for (int num = 1; num <= 10000; num++) {
        int storeN = num;//��storeN����num
        int sum = 0;//��sum����ÿλ���ֵ������ͣ�ÿ��forѭ�����������
        while (storeN > 0) {
            int digit = storeN % 10;//�ֽ�storeN
            sum += digit * digit * digit;
            storeN/= 10;//��СstoreNֵ��������һ��ѭ������һλ��
        }

        if (sum == num) {
            printf("%d\n", num);
            ++N;
        }
    }
    printf("һ����%d��", N);
    return 0;
}