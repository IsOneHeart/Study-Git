#pragma once
//不含头节点
typedef struct QNode {
	type data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* front;
	QNode* rear;
}Quence;

int QuenceInitiate(Quence* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	return 1;
}

int QuenceNotEmpty(Quence Q) {
	if (Q.front == NULL)
		return 0;
	return 1;
}

int QuenceAppend(Quence* Q, type x) {
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

int QuenceDelete(Quence* Q, type* d) {
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

int QuenceGet(Quence Q, type* d) {
	if (Q.front == NULL) {
		printf("队列已空！");
		return 0;
	}
	else {
		*d = Q.front->data;
		return 1;
	}
}

int QuenceDestory(Quence* Q) {
	QNode* p, * p1;
	p = Q->front;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	return 1;
}

int QuencePrint(Quence* Q) {
	QNode* p = Q->front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return 1;
}