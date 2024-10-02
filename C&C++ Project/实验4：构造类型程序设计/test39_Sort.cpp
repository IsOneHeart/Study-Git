/*输入整数n（1≤n≤10）和n个整数存入数组，要求定义一个函数void sort(int *list，int n)，
使用选择排序法对指针list所指数组进行升序排列，n为list所指向数组的元素个数。
在main函数中调用sort函数实现排序，最后输出排序后的结果。*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 64
#include <stdio.h>
void sort(int* list, int n) {//list指向num
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
	printf("请输入整数n：");
	scanf("%d", &n);
	printf("请输入%d个整数：",n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &num[i]);
	}
	sort(num, n);
	printf("排序后的结果为：");
	for (int i = 0;i < n;i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
}
