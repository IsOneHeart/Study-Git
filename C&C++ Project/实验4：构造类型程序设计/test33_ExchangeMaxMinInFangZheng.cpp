//����һ��������n(1��n��6)��n�׷���A����������A�е����ֵ����Сֵλ�á��ٶ�����A�е����ֵ����Сֵ��Ψһ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 6
int main() {
	int n, A[MaxSize][MaxSize],w=MaxSize;
	printf("������������n��1��n��%d����",w);
	scanf("%d", &n);
	if (n < 1 || n> MaxSize)
		printf("������n������1��n��%d��", w);
	else {
		printf("�밴˳�����뷽��A������A�е����ֵ����Сֵ��Ψһ��:\n");
		for (int i = 0;i < n;i++) {//����=�������±��0��ʼ
			for (int j = 0;j < n;j++) {
				printf("��%d�е�%d�У�", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}
		int tempMax[3] = { A[0][0], 0, 0 }, tempMin[3] = { A[0][0], 0,0 }, Etemp = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (tempMax[0] < A[i][j]) {
					tempMax[0] = A[i][j];
					tempMax[1] = i;//������ʱ���ֵ��i��jֵ
					tempMax[2] = j;
				}
				if (tempMin[0] > A[i][j]) {
					tempMin[0] = A[i][j];
					tempMin[1] = i;
					tempMin[2] = j;
				}
			}
		}
		Etemp = A[tempMax[1]][tempMax[2]];//�������ֵ����Сֵ
		A[tempMax[1]][tempMax[2]] = A[tempMin[1]][tempMin[2]];
		A[tempMin[1]][tempMin[2]] = Etemp;
		printf("n�׷���A�������ֵ����Сֵ��Ľ��Ϊ��\n");
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}