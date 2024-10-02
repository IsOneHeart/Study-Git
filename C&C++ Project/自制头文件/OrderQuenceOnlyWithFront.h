#pragma once
typedef struct {
	DataType quence[MaxQuenceSize];
	int front;
	int count;
}FQNode;

int FQInitiate(FQNode* Q) {
	Q->front = 0;
	Q->count = 0;
	return 1;
}

int FQNotEmpty(FQNode Q) {
	if (Q.count != 0)
		return 1;
	return 0;
}

int FQAppend(FQNode* Q, DataType x) {
	if (Q->count == MaxQuenceSize) {
		printf("队列已满无法插入！");
		return 0;
	}
	int rear = (Q->front + Q->count) % MaxQuenceSize;
	Q->quence[rear] = x;
	Q->count++;
}

int FQDelete(FQNode* Q, DataType* d) {
	if (Q->count == 0) {
		printf("队列一空！");
		return 0;
	}
	else {
		*d = Q->quence[Q->front];
		Q->front = (Q->front + 1) % MaxQuenceSize;
		Q->count--;
		return 1;
	}
}

int FQGet(FQNode Q, DataType* d) {
	if (Q.count == 0) {
		printf("队列已空！");
		return 0;
	}
	else {
		*d = Q.quence[Q.front];
		return 1;
	}
}