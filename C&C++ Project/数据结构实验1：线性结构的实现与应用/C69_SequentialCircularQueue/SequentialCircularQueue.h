#pragma once
//����ͷ�ڵ�

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
		printf("�����������޷����룡");
		return 0;
	}
	else {
		Q->queue[Q->rear] = x;
		Q -> rear = (Q->rear + 1) % MaxSCQueueSize;
		/*
		% MaxSCQueueSize��
		�Խ������ȡģ���㣬ȷ��βָ�벻�ᳬ�����е����������
		���βָ���Ѿ�ָ����е����һ��λ�ã�ȡģ���㽫ʹ��ص����е���ʼλ�á�
		*/
		Q->count++;
		return 1;
	}
}

int SCQueueDelete(SCQueue* Q, type* d) {
	if (Q->count == 0) {
		printf("�����ѿգ�");
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
		printf("�����ѿգ�");
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