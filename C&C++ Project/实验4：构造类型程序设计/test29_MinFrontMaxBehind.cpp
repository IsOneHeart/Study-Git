#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int n, num[10], temp = 0, min = 0, max = 0, i;
	printf("请输入一个正整数n（1<n<=10）：");
	scanf("%d", &n);
	if (n <= 1 || n > 10)
		printf("n值必须满足1<n<=10！");
	else {
		printf("请输入%d个互不相同的整数：", n);
		for (int j = 0;j < n;j++)
			scanf("%d", &num[j]);
		printf("互换后的n个整数依次是：");
		for (i = 0;i < n - 1;i++) {//选择法
			min = i, max = i;
			for (int j = i + 1;j < n;j++)
				if (num[j] < num[min])//判断num[j]和num[min]大小
					min = j;//把小的赋给j，循环后num[j]为最小，即min最小

			for (int j = i + 1;j < n;j++)
				if (num[j] > num[max])//判断num[j]和num[max]大小
					max = j;//把大的赋给j，循环后num[j]为最小，即max最小

			temp = num[min];//把最小值赋值给临时变量
			num[min] = num[0];//把第一个数放在“最小值”的位置上
			num[0] = temp;//把临时变量（储存着最小值）赋值给第一个数

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