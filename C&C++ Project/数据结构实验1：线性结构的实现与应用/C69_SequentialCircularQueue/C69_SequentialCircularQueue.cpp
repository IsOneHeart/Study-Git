/*
设计采取少用一个存储单元的方法解决队列满和队列空判断。设队列的元素类型为char，实现顺序循环队列的各种基本操作：
① 初始化队列Q；
② 判断队列Q是否为空；
③ 入队操作；
④ 出队操作；
⑤ 输出队列元素个数；
⑥ 输出队列序列；
⑦ 编写一个测试主函数，要求将若干个元素（不少于8个）入队；出队若干个元素（同时输出出队元素）；输出队列序列；通过函数调用实现以上各项操作。
测试数据：建议用自己姓名的全拼。
*/
#include <stdio.h>
#include <stdlib.h>
typedef char type;
#define MaxSCQueueSize 64
#include "SequentialCircularQueue.h"

int main() {
	SCQueue Q;
	SCQueueInitiate(&Q);

	printf("队列%s。\n", SCQueueNotEmpty(Q) ? "非空" : "为空");

	SCQueueAppend(&Q, 'a');
	SCQueueAppend(&Q, 'b');
	SCQueueAppend(&Q, 'c');
	printf("已插入a,b,c。\n");

	printf("队列%s。\n", SCQueueNotEmpty(Q) ? "非空" : "为空");

	printf("队列长度: %d。\n", SCQueueLen(Q));

	printf("队列元素: ");
	SCQueuePrint(Q);

	type x;
	SCQueueDelete(&Q, &x);
	printf("出队元素: %c\n", x);

	printf("队列长度: %d\n", SCQueueLen(Q));

	printf("队列元素: ");
	SCQueuePrint(Q);

	return 0;
}