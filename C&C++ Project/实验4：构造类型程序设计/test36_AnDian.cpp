/*����һ��������n(1��n��6)��n�׷���A���ڷ���A�в��Ұ��㣬
����ҵ�A�İ��㣬����������±꣬�������"NO"����A�������1�����㣩��
�������Ԫ��ֵ�ڸ���������ڸ�������С��Ԫ�ء�*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 6
int main() {
	int n, A[MaxSize][MaxSize], w = MaxSize;
	printf("������������n��1��n��%d����", w);
	scanf("%d", &n);
	if (n < 1 || n> MaxSize)
		printf("������n������1��n��%d��", w);
	else {
		printf("�밴˳�����뷽��A:\n");
		for (int i = 0;i < n;i++) {//����=�������±��0��ʼ
			for (int j = 0;j < n;j++) {
				printf("��%d�е�%d�У�", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}
		printf("����ķ���Ϊ��\n");
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		printf("���㣺\n");
		int i = 0 , tempMax[3] = { A[i][0], 0, 0 }, tempMin[3] = { A[0][i], 0,0 };
		for (;i < n;i++) {
			tempMax[0] = A[i][0] , tempMin[0] =  A[0][i];
			for (int j = 0;j < n;j++) {
				if (tempMax[0] < A[i][j]) {
					tempMax[0] = A[i][j];
					tempMax[1] = i;//������ʱ���ֵ��i��jֵ
					tempMax[2] = j;
				}
			}
			for(int j=0;j<n;j++){
				if (tempMin[0] > A[j][i]) {
					tempMin[0] = A[j][i];
					tempMin[1] = j;
					tempMin[2] = i;
				}
			}
			if (tempMax[1] == tempMin[1]|| tempMax[2] == tempMin[2]) {
				printf("��%d�е�%d��", tempMax[1] + 1, tempMax[2] + 1);
				return 0;
			}
		}
			printf("NO");
	}
	return 0;
}