/*��������n��1��n��10����n�������������飬Ҫ����һ������void sort(int *list��int n)��
ʹ��ѡ�����򷨶�ָ��list��ָ��������������У�nΪlist��ָ�������Ԫ�ظ�����
��main�����е���sort����ʵ�����������������Ľ����*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 64
#include <stdio.h>
void sort(int* list, int n) {//listָ��num
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}
void main() {
	int n = 0, num[MaxSize];
	printf("����������n��");
	scanf("%d", &n);
	printf("������%d��������",n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &num[i]);
	}
	sort(num, n);
	printf("�����Ľ��Ϊ��");
	for (int i = 0;i < n;i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
}
