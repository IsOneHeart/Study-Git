#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* malloc() realloc() */
void mallocTest() {
	int n, i, * a;
	printf("请输入数组长度：");
	scanf("%d", &n);
	if ((a = (int*)malloc(n * sizeof(int))) == NULL) {
		printf("分配储存块失败！");
		exit(0);
	}
	for (i = 0;i < n;i++) {
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
	int add;
	printf("请输入要增加的数组数：");
	scanf("%d", &add);
	a = (int*)realloc(a, add * sizeof(int));
	for (int i = 0;i < add;i++) {
		printf("a[%d]=", i+n);
		scanf("%d", &a[i+n]);
	}
	free(a);
}

/* calloc() */
void callocTest() {
	int n, i, * a;
	printf("请输入数组长度：");
	scanf("%d", &n);
	if ((a = (int*)calloc(n,sizeof(int))) == NULL) {
		printf("分配储存块失败！");
		exit(0);
	}
	for (i = 0;i < n;i++) {
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
	free(a);
}

void main() {
	mallocTest();
	//callocTest();
}