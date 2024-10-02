/*输入一个正整数n(1≤n≤6)和n阶方阵A，在方阵A中查找鞍点，
如果找到A的鞍点，就输出它的下标，否则，输出"NO"（设A中最多有1个鞍点）。
鞍点就是元素值在该行上最大，在该列上最小的元素。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 6
int main() {
	int n, A[MaxSize][MaxSize], w = MaxSize;
	printf("请输入正整数n（1≤n≤%d）：", w);
	scanf("%d", &n);
	if (n < 1 || n> MaxSize)
		printf("正整数n需满足1≤n≤%d。", w);
	else {
		printf("请按顺序输入方阵A:\n");
		for (int i = 0;i < n;i++) {//不能=，数组下标从0开始
			for (int j = 0;j < n;j++) {
				printf("第%d行第%d列：", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}
		printf("输入的方阵为：\n");
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		printf("鞍点：\n");
		int i = 0 , tempMax[3] = { A[i][0], 0, 0 }, tempMin[3] = { A[0][i], 0,0 };
		for (;i < n;i++) {
			tempMax[0] = A[i][0] , tempMin[0] =  A[0][i];
			for (int j = 0;j < n;j++) {
				if (tempMax[0] < A[i][j]) {
					tempMax[0] = A[i][j];
					tempMax[1] = i;//储存临时最大值的i和j值
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
				printf("第%d行第%d列", tempMax[1] + 1, tempMax[2] + 1);
				return 0;
			}
		}
			printf("NO");
	}
	return 0;
}