#pragma once
typedef struct QNode {
	type data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* rear;
}Queue;

int QueueInitiate(Queue* Q) {
	Q->rear = NULL;
	return 1;
}

int QueueAppend(Queue* Q, type x) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		return 0; // 内存分配失败
	}
	newNode->data = x;
	newNode->next = NULL;

	if (Q->rear == NULL) {
		Q->rear = newNode;
		Q->rear->next = Q->rear; // 队列中只有一个节点时，节点的next指向自己
	}
	else {
		newNode->next = Q->rear->next;
		Q->rear->next = newNode;
		Q->rear = newNode;
	}

	return 1;
}

int QueueDelete(Queue* Q, type* d) {
	if (Q->rear == NULL) {
		return 0; // 队列为空
	}

	QNode* front = Q->rear->next; // 循环链表
	*d = front->data;

	if (Q->rear == front) {
		Q->rear = NULL; // 队列中只有一个节点时，出队列后队列为空
	}
	else {
		Q->rear->next = front->next;
	}

	free(front);
	return 1;
}

int QueueDestory(Queue* Q) {
	while (Q->rear != NULL) {
		QNode* temp = Q->rear->next;
		if (Q->rear == temp) {
			Q->rear = NULL;
		}
		else {
			Q->rear->next = temp->next;
		}
		free(temp);
	}
	return 1;
}