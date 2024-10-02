//输入一个正整数n(1≤n≤6)和n阶方阵A，交换方阵A中的最大值与最小值位置。假定方阵A中的最大值与最小值都唯一。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 6
int main() {
	int n, A[MaxSize][MaxSize],w=MaxSize;
	printf("请输入正整数n（1≤n≤%d）：",w);
	scanf("%d", &n);
	if (n < 1 || n> MaxSize)
		printf("正整数n需满足1≤n≤%d。", w);
	else {
		printf("请按顺序输入方阵A（方阵A中的最大值与最小值都唯一）:\n");
		for (int i = 0;i < n;i++) {//不能=，数组下标从0开始
			for (int j = 0;j < n;j++) {
				printf("第%d行第%d列：", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}
		int tempMax[3] = { A[0][0], 0, 0 }, tempMin[3] = { A[0][0], 0,0 }, Etemp = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (tempMax[0] < A[i][j]) {
					tempMax[0] = A[i][j];
					tempMax[1] = i;//储存临时最大值的i和j值
					tempMax[2] = j;
				}
				if (tempMin[0] > A[i][j]) {
					tempMin[0] = A[i][j];
					tempMin[1] = i;
					tempMin[2] = j;
				}
			}
		}
		Etemp = A[tempMax[1]][tempMax[2]];//交换最大值和最小值
		A[tempMax[1]][tempMax[2]] = A[tempMin[1]][tempMin[2]];
		A[tempMin[1]][tempMin[2]] = Etemp;
		printf("n阶方阵A交换最大值和最小值后的结果为：\n");
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}