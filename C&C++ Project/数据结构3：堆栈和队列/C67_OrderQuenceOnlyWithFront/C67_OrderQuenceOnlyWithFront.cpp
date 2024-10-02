#include <stdio.h>
#define MaxQuenceSize 16
typedef int DataType;
#include "OrderQuenceOnlyWithFront.h"

int main() {
	FQNode queue;
	FQInitiate(&queue);

	FQAppend(&queue, 1);
	FQAppend(&queue, 2);
	FQAppend(&queue, 3);

	DataType data;
	FQGet(queue, &data);
	printf("取出的元素为：%d\n", data);

	FQDelete(&queue, &data);
	printf("删除的元素为：%d\n", data);

	return 0;
}