#pragma once
//不含头节点

typedef struct {
	type queue[MaxSCQueueSize];
	int rear;
	int front;
	int count;
}SCQueue;

int SCQueueInitiate(SCQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	Q->count = 0;
	return 1;
}

int SCQueueNotEmpty(SCQueue Q) {
	if (Q.count == 0)
		return 0;
	return 1;
}

int SCQueueAppend(SCQueue* Q, type x) {
	if (Q->count > 0 && Q->rear == Q->front) {
		printf("队列已满，无法插入！");
		return 0;
	}
	else {
		Q->queue[Q->rear] = x;
		Q -> rear = (Q->rear + 1) % MaxSCQueueSize;
		/*
		% MaxSCQueueSize：
		对结果进行取模运算，确保尾指针不会超过队列的最大容量。
		如果尾指针已经指向队列的最后一个位置，取模运算将使其回到队列的起始位置。
		*/
		Q->count++;
		return 1;
	}
}

int SCQueueDelete(SCQueue* Q, type* d) {
	if (Q->count == 0) {
		printf("队列已空！");
		return 0;
	}
	else {
		*d = Q->queue[Q->front];
		Q->front = (Q->front + 1) % MaxSCQueueSize;
		Q->count--;
		return 1;
	}
}

int SCQueueGet(SCQueue Q, type* d) {
	if (Q.count == 0) {
		printf("队列已空！");
		return 0;
	}
	else
		*d = Q.queue[Q.front];
	return 1;
}

int SCQueueLen(SCQueue Q) {
	return Q.count;
}

void SCQueuePrint(SCQueue Q) {
	int i = Q.front;
	while (i != Q.rear) {
		printf("%c", Q.queue[i]);
		i = (i + 1) % MaxSCQueueSize;
	}
	printf("\n");
}