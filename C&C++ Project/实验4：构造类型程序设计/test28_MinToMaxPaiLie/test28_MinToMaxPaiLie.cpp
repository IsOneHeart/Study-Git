#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int n, num[9], temp = 0, index = 0, x;
	printf("请输入一个正整数n（1<n<=9）：");
	scanf("%d", &n);
	if (n <= 1 || n > 9)
		printf("n值必须满足1<n<=9！");
	else {
		printf("请输入%d个互不相同的整数：", n);
		for (int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		printf("请输入要删除的整数：");
		scanf("%d", &x);
		printf("删除%d后的排序结果：\n",x);
		for (int i = 0;i < n - 1;i++) {//选择法
			index = i;
			for (int j = i + 1;j < n;j++) {
				if (num[j] < num[index]) //判断num[j]和num[index]大小
					index = j;//把小的赋给j，循环后num[j]为最小，即index最小
				}
			temp = num[index];//把最小值赋值给临时变量
			num[index] = num[i];//把第一个数放在“最小值”的位置上
			num[i] = temp;//把临时变量（储存着最小值）赋值给第一个数
			if (x == num[i]) {
				num[i] = num[n-1];
				n--;
				i--;
			}
			else
				printf("%d ", num[i]);//不会打印最后一个数
		}
		printf("%d", num[n - 1]);//打印最后一个数
	}
}