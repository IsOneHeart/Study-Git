#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int n, num[10], temp = 0, min = 0, max = 0, i;
	printf("������һ��������n��1<n<=10����");
	scanf("%d", &n);
	if (n <= 1 || n > 10)
		printf("nֵ��������1<n<=10��");
	else {
		printf("������%d��������ͬ��������", n);
		for (int j = 0;j < n;j++)
			scanf("%d", &num[j]);
		printf("�������n�����������ǣ�");
		for (i = 0;i < n - 1;i++) {//ѡ��
			min = i, max = i;
			for (int j = i + 1;j < n;j++)
				if (num[j] < num[min])//�ж�num[j]��num[min]��С
					min = j;//��С�ĸ���j��ѭ����num[j]Ϊ��С����min��С

			for (int j = i + 1;j < n;j++)
				if (num[j] > num[max])//�ж�num[j]��num[max]��С
					max = j;//�Ѵ�ĸ���j��ѭ����num[j]Ϊ��С����max��С

			temp = num[min];//����Сֵ��ֵ����ʱ����
			num[min] = num[0];//�ѵ�һ�������ڡ���Сֵ����λ����
			num[0] = temp;//����ʱ��������������Сֵ����ֵ����һ����

			if (max == i)
				max == min;

			temp = num[max];
			num[max] = num[n - 1];
			num[n - 1] = temp;
		}

		for(int j=0;j<n;j++)
			printf("%d ", num[j]);
	}
}