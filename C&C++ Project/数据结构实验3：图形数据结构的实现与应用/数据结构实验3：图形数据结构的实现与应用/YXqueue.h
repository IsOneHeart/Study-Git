#pragma once
//不含头节点
typedef struct QNode {
	type data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* front;
	QNode* rear;
}Queue;

int QueueInitiate(Queue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	return 1;
}

int QueueNotEmpty(Queue Q) {
	if (Q.front == NULL)
		return 0;
	return 1;
}

int QueueAppend(Queue* Q, type x) {
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (Q->rear != NULL)
		Q->rear->next = p;
	Q->rear = p;
	if (Q->front == NULL)
		Q->front = p;
	return 1;
}

int QueueDelete(Queue* Q, type* d) {
	QNode* p;
	if (Q->front == NULL) {
		printf("队列已空！");
		return 0;
	}
	else {
		*d = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if (Q->front == NULL)
			Q->rear = NULL;
		free(p);
		return 1;
	}
}

int QueueGet(Queue Q, type* d) {
	if (Q.front == NULL) {
		printf("队列已空！");
		return 0;
	}
	else {
		*d = Q.front->data;
		return 1;
	}
}

int QueueDestroy(Queue* Q) {
	QNode* p, * p1;
	p = Q->front;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	return 1;
}

int QueuePrint(Queue* Q, void visit(type item)) {
	QNode* p = Q->front;
	while (p != NULL) {
		//printf("%d ", p->data);
		visit(p->data);
		p = p->next;
	}
	return 1;
}