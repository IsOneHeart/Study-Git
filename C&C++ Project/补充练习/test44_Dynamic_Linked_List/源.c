#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* malloc() realloc() */
void mallocTest() {
	int n, i, * a;
	printf("���������鳤�ȣ�");
	scanf("%d", &n);
	if ((a = (int*)malloc(n * sizeof(int))) == NULL) {
		printf("���䴢���ʧ�ܣ�");
		exit(0);
	}
	for (i = 0;i < n;i++) {
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
	int add;
	printf("������Ҫ���ӵ���������");
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
	printf("���������鳤�ȣ�");
	scanf("%d", &n);
	if ((a = (int*)calloc(n,sizeof(int))) == NULL) {
		printf("���䴢���ʧ�ܣ�");
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