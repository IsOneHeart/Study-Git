#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int n, num[9], temp = 0, index = 0, x;
	printf("������һ��������n��1<n<=9����");
	scanf("%d", &n);
	if (n <= 1 || n > 9)
		printf("nֵ��������1<n<=9��");
	else {
		printf("������%d��������ͬ��������", n);
		for (int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		printf("������Ҫɾ����������");
		scanf("%d", &x);
		printf("ɾ��%d�����������\n",x);
		for (int i = 0;i < n - 1;i++) {//ѡ��
			index = i;
			for (int j = i + 1;j < n;j++) {
				if (num[j] < num[index]) //�ж�num[j]��num[index]��С
					index = j;//��С�ĸ���j��ѭ����num[j]Ϊ��С����index��С
				}
			temp = num[index];//����Сֵ��ֵ����ʱ����
			num[index] = num[i];//�ѵ�һ�������ڡ���Сֵ����λ����
			num[i] = temp;//����ʱ��������������Сֵ����ֵ����һ����
			if (x == num[i]) {
				num[i] = num[n-1];
				n--;
				i--;
			}
			else
				printf("%d ", num[i]);//�����ӡ���һ����
		}
		printf("%d", num[n - 1]);//��ӡ���һ����
	}
}