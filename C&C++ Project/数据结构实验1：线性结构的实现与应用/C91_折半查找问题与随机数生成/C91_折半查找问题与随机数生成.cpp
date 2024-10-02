#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ArraryMaxSize 10000

int BinarySearchRecursive(int a[], int low, int high, int target) {
	if (high >= low) {
		int mid = low + (high - low) / 2;
		if (a[mid] == target) {
			return mid;
		}
		else if (a[mid] > target) {
			return BinarySearchRecursive(a, low, mid - 1, target);
		}
		else {
			return BinarySearchRecursive(a, mid + 1, high, target);
		}
	}
	else
		return -1;
}

int BinarySearchIterative(int a[], int low, int high, int target) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (a[mid] == target) {
			return mid;
		}
		else if (a[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}

int compare(const void* a, const void* b) {
	int int_a = *((int*)a);
	int int_b = *((int*)b);

	// 返回值为负表示a小于b，为正表示a大于b，为0表示a等于b  
	if (int_a == int_b) return 0;
	else if (int_a < int_b) return -1;
	else return 1;
}

int main() {
	int a[ArraryMaxSize];
	srand((unsigned int)time(NULL));// 使用当前时间作为随机数发生器的种子
	for (int i = 0;i < ArraryMaxSize;i++) {
		a[i] = rand() % 10000; // 生成0到9999之间的随机数
	}
	qsort(a, ArraryMaxSize, sizeof(int), compare);
	int target1 = a[500]; // 假设这个元素在数组中，查找应该成功  
	int target2 = 499; // 假设这个元素不在数组中，查找应该不成功  

	int index1 = BinarySearchRecursive(a, 0, ArraryMaxSize - 1, target1);
	if (index1 != -1) {
		printf("递归查找成功！目标元素 %d 在数组中的索引是 %d\n", target1, index1);
	}
	else {
		printf("递归查找失败！目标元素 %d 不在数组中\n", target1);
	}

	int index2 = BinarySearchIterative(a, 0, ArraryMaxSize - 1, target1);
	if (index2 != -1) {
		printf("循环查找成功！目标元素 %d 在数组中的索引是 %d\n", target1, index2);
	}
	else {
		printf("循环查找失败！目标元素 %d 不在数组中\n", target1);
	}

	int index3 = BinarySearchRecursive(a, 0, ArraryMaxSize - 1, target2);
	if (index3 != -1) {
		printf("递归查找成功！目标元素 %d 在数组中的索引是 %d\n", target2, index3);
	}
	else {
		printf("递归查找失败！目标元素 %d 不在数组中\n", target2);
	}

	int index4 = BinarySearchIterative(a, 0, ArraryMaxSize - 1, target2);
	if (index4 != -1) {
		printf("循环查找成功！目标元素 %d 在数组中的索引是 %d\n", target2, index4);
	}
	else {
		printf("循环查找失败！目标元素 %d 不在数组中\n", target2);
	}

	return 0;
}