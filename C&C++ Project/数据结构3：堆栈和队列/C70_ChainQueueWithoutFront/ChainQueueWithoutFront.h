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
		return 0; // �ڴ����ʧ��
	}
	newNode->data = x;
	newNode->next = NULL;

	if (Q->rear == NULL) {
		Q->rear = newNode;
		Q->rear->next = Q->rear; // ������ֻ��һ���ڵ�ʱ���ڵ��nextָ���Լ�
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
		return 0; // ����Ϊ��
	}

	QNode* front = Q->rear->next; // ѭ������
	*d = front->data;

	if (Q->rear == front) {
		Q->rear = NULL; // ������ֻ��һ���ڵ�ʱ�������к����Ϊ��
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