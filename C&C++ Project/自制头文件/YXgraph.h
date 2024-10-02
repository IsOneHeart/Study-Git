#pragma once

#define MaxWeight -1
#define MaxEdges 64
#ifndef VertType
#define VertType char
#endif
#ifndef vt
#define vt "%c"
#endif
#ifndef MaxVertices
#define MaxVertices 64
#endif

#define type VertType
#define TYPE vt
#include "YXlist.h"
#include "YXqueue.h"

/* 邻接矩阵 */
typedef struct AdjMGraph {
	Node* Vertices; //存放顶点的链表
	int edge[MaxVertices][MaxVertices]; //存放边的邻接矩阵
	int numOfEdges; //边的条数
}AdjMGraph;

void AdjMGraphInitiate(AdjMGraph* G, int n) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = MaxWeight;
		}
	}
	G->numOfEdges = 0;
	ListInitiate(&G->Vertices);
}

void AdjMGraphInsertVertex(AdjMGraph* G, VertType vertex) {
	ListInsert(G->Vertices, ListLen(G->Vertices), vertex);
}

void AdjMGraphInsertEdge(AdjMGraph* G, int v1, int v2, int weight) {
	int len = ListLen(G->Vertices);
	if (v1 < 0 || v1 >= len || v2 < 0 || v2 >= len) {
		printf("参数v1或v2越界出错！");
		return;
	}
	G->edge[v1][v2] = weight;
	G->numOfEdges++;
}

void AdjMGraphDeleteEdge(AdjMGraph* G, int v1, int v2) {
	int len = ListLen(G->Vertices);
	if (v1<0 || v1> len || v2 < 0 
		|| v2 >= len|| v1 == v2) {
		printf("参数v1或v2出错！");
		return;
	}
	if (G->edge[v1][v2] == MaxWeight || v1 == v2) {
		printf("该边不存在！");
		return;
	}
	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}

int AdjMGraphGetFirstVex(AdjMGraph G, int v) {
	int col;
	int len = ListLen(G.Vertices);
	if (v < 0 || v >= len) {
		printf("参数v越界出错！");
		return -1;
	}
	for (col = 0;col < len;col++) {
		if (G.edge[v][0] > 0 && G.edge[v][0] < MaxWeight)
			return col;
	}
	return -1;
}

int AdjMGraphGetNextVex(AdjMGraph G, int v1, int v2) {
	int col;
	int len = ListLen(G.Vertices);
	if (v1<0 || v1 > len || v2 < 0 || v2 >= len) {
		printf("参数v1或参数v2越界出错！");
		return -1;
	}
	for (col = v2 + 1;col < len;col++) {
		if (G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight)
			return col;
	}
	return -1;
}

typedef struct RowColWeight {
	int row;
	int col;
	int weight;
}RowColWeight;

void AdjMGraphCreate(AdjMGraph* G, VertType V[], int n, RowColWeight E[], int e) {
	int i, k;
	AdjMGraphInitiate(G, n);
	for (i = 0;i < n;i++)
		AdjMGraphInsertVertex(G, V[i]);
	for (k = 0;k < e;k++)
		AdjMGraphInsertEdge(G, E[k].row, E[k].col, E[k].weight);
}

void AdjMGraphPrint(AdjMGraph G) {
	int len = ListLen(G.Vertices);
	printf("顶点集合：\n");
	ListPrint(G.Vertices);
	printf("权值集合：\n");
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < len;j++) {
			if (G.edge[i][j] == MaxWeight)
				printf("%s\t", "INF");
			else
				printf("%d\t", G.edge[i][j]);
		}
		printf("\n");
	}
}

typedef struct Edge {
	int dest; //邻接边的弧头顶点序号
	struct Edge* next;
	int weight;
}Edge;

typedef struct GNode {
	VertType data;
	int source;
	Edge* adj;
}GNode;

typedef struct Graph {
	GNode a[MaxVertices];
	int numOfVerts;
	int numOfEdges;
}Graph;

void GraphInitiate(Graph* G) {
	int i;
	G->numOfVerts = 0;
	G->numOfEdges = 0;
	for (i = 0;i < MaxVertices;i++) {
		G->a[i].source = i;
		G->a[i].adj = NULL;
	}
}

void GraphInsertVertex(Graph* G, int i, VertType vertex) {
	if (i >= 0 && i < MaxVertices) {
		G->a[i].data = vertex;
		G->numOfVerts++;
	}
	else
		printf("顶点越界！\n");
}

void GraphInsertEdge(Graph* G, int v1, int v2, bool isDirected, int weight = 0) {
	Edge* p;
	if (v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts) {
		printf("参数v1或参数v2越界出错！");
		return;
	}

	// 插入从v1到v2的边  
	p = (Edge*)malloc(sizeof(Edge));
	if (p == NULL) {
		printf("内存块分配失败！\n");
		return;
	}
	p->dest = v2;
	p->weight = weight;
	p->next = G->a[v1].adj;
	G->a[v1].adj = p;
	G->numOfEdges++;

	// 如果是无向图，则还需插入从v2到v1的边  
	if (!isDirected) {
		p = (Edge*)malloc(sizeof(Edge));
		if (p == NULL) {
			printf("内存块分配失败！\n");
			return;
		}
		p->dest = v1;
		p->weight = weight;
		p->next = G->a[v2].adj;
		G->a[v2].adj = p;
		//G->numOfEdges++; // 对于无向图，每添加一条边，边数增加2（因为双向）  
	}
}

void GraphDeleteEdge(Graph* G, int v1, int v2) {
	Edge* curr, * pre;
	if (v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts) {
		printf("参数v1或v2越界出错！");
		return;
	}
	pre = NULL;
	curr = G->a[v1].adj;
	while (curr != NULL && curr->dest != v2) {
		pre = curr;
		curr = curr->next;
	}
	if (curr != NULL && curr->dest == v2 && pre == NULL) {
		G->a[v1].adj = curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else if (curr != NULL && curr->dest == v2 && pre != NULL) {
		pre->next = curr->next;
		free(curr);
		G->numOfEdges--;
	}
}

int GraphGetFirstVex(Graph G, int v) {
	Edge* p;
	if (v<0 || v>G.numOfVerts) {
		printf("参数v1或v2越界出错！");
		return -1;
	}
	p = G.a[v].adj;
	if (p != NULL)
		return p->dest;
	return -1;
}

int GraphGetNextVex(Graph G, int v1, int v2) {
	Edge* p;
	Edge* prev = NULL; // 用于保存前一个指针
	if (v1 < 0 || v1 >= G.numOfVerts || v2 < 0 || v2 >= G.numOfVerts) {
		printf("参数v1或v2越界出错！");
		return -1;
	}
	p = G.a[v1].adj;
	while (p != NULL) {
		if (p->dest == v2) {
			if (p->next != NULL) {
				return p->next->dest;  
			}
			else {
				return -1;
			}
		}
		prev = p; // 更新prev为当前节点  
		p = p->next;
	}
	return -1;
}

void GraphPrintVerts(Graph G) {
	for (int i = 0; i < G.numOfVerts; i++) {
		printf(vt"", G.a[i].data);
	}
}

void GraphPrintEdges(Graph G) {
	printf("\n");
	for (int i = 0; i < G.numOfVerts; i++) {
		Edge* p = G.a[i].adj; // 获取当前顶点的邻接表头指针  
		while (p != NULL) { // 遍历当前顶点的所有边  
			// 打印边的起始顶点、终止顶点和权重  
			printf("(%c, %c, %d)\n", G.a[i].data, G.a[p->dest].data, p->weight);
			p = p->next; // 移动到下一条边  
		}
	}
}

#define INF -1
void GraphPrintForm(Graph G) {
	printf("\n");
	printf("点-边\t");
	for (int j = 0; j < G.numOfVerts; j++) {
		printf(vt"\t", G.a[j].data); // 打印列标题（即顶点）  
	}
	printf("\n\n");

	for (int i = 0; i < G.numOfVerts; i++) {
		printf(vt"\t", G.a[i].data); // 打印行标题（即起点）  
		for (int j = 0; j < G.numOfVerts; j++) {
			int weight = INF; // 假设初始权重为无穷大（无边）  
			Edge* p = G.a[i].adj; // 获取当前顶点的邻接表头指针  
			while (p != NULL && p->dest != j) { // 遍历当前顶点的所有边，找到到j的边  
				p = p->next;
			}
			if (p != NULL) { // 如果找到了到j的边  
				weight = p->weight; // 获取边的权重  
				if (i == j)
					weight = INF;
			}
			printf(weight == INF ? ".\t" : "%d", weight);
			if (weight != INF) {
				printf(":");
				printf(vt, G.a[i].data);
				printf("->");
				printf(vt"\t", G.a[j].data);
			}
		}
		printf("\n\n");
	}
}

void GraphDestory(Graph* G) {
	int i;
	Edge* p, * q;
	for (i = 0; i < G->numOfVerts; i++) {
		p = G->a[i].adj;
		while (p != NULL) {
			q = p->next; // 保存下一条边的指针  
			free(p);     // 释放当前边的内存  
			p = q;       // 移动到下一条边  
		}
		G->a[i].adj = NULL; // 将当前顶点的邻接表头设置为NULL  
	}  
}

void GraphDepthFirstSearch(Graph G, int v, int visited[], void visit(VertType item)) {
	Edge* p;

	// 访问节点v  
	visit(G.a[v].data);
	visited[v] = 1;

	// 遍历节点v的所有邻接节点  
	for (p = G.a[v].adj; p != NULL; p = p->next) {
		int w = p->dest; // 假设Edge结构体中有一个dest成员表示目标节点  
		if (!visited[w]) {
			GraphDepthFirstSearch(G, w, visited, visit);
		}
	}
}

int GraphDepthFirstSearch(Graph G, void visit(VertType item)) {
	int* visited = (int*)malloc(sizeof(int) * G.numOfVerts);
	if (visited == NULL) {
		printf("分配内存块失败！");
		return 0;
	}
	for (int i = 0; i < G.numOfVerts; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < G.numOfVerts; i++) {
		if (!visited[i]) {
			GraphDepthFirstSearch(G, i, visited, visit);
		}
	}
	free(visited);
	return 1;
}

void GraphBroadFirstSearch(Graph G, int v, int visited[], void visit(VertType item), Queue* queue) {
	visit(G.a[v].data);
	visited[v] = 1;
	QueueAppend(queue, v);
	while (!QueueNotEmpty(*queue)) {
		char u;
		QueueDelete(queue, &u);

		int w = GraphGetFirstVex(G, u);
		while (w != -1) {
			if (!visited[w]) {
				visit(G.a[w].data);
				visited[w] = 1;
				QueueAppend(queue, w);
			}
			w = GraphGetNextVex(G, u, w); 
		}
	}
}

int GraphBroadFirstSearch(Graph G, void visit(VertType item)) {
	int i;
	int* visited = (int*)malloc(sizeof(int) * G.numOfVerts);
	Queue queue;

	if (visited == NULL) {
		printf("分配内存块失败！");
		return 0;
	}
	QueueInitiate(&queue); // 初始化队列  
	for (i = 0; i < G.numOfVerts; i++) {
		visited[i] = 0;
	} 
	for (i = 0; i < G.numOfVerts; i++) {
		if (!visited[i]) {
			GraphBroadFirstSearch(G, i, visited, visit, &queue); // 传入队列的指针  
		}
	}
	QueueDestroy(&queue);
	free(visited);
	return 1;
}

void GraphCreate(Graph* G, VertType v[], int numOfVerts, RowColWeight d[], int numOfEdges, bool usingWeight, bool isDirected) {
	GraphInitiate(G);
	for (int i = 0;i < numOfVerts;i++)
		GraphInsertVertex(G, i, v[i]);
	if(usingWeight==false)
		for (int i = 0;i < numOfEdges;i++)
			GraphInsertEdge(G, d[i].row, d[i].col, isDirected);
	else
		for (int i = 0;i < numOfEdges;i++)
			GraphInsertEdge(G, d[i].row, d[i].col, isDirected, d[i].weight);
}

#define CHAR 0
#define INT 1
int GraphReadFile(Graph* G, const char* path, int WhatType, bool isDirected) {
	FILE* fp;
	if (fopen_s(&fp, path, "r") != 0) {
		printf("文件打开失败！");
		return 0;
	}
	char v[MaxVertices] = {};
	int line_len;
	int ints[MaxVertices] = {};
	int int_count = 0;
	if (WhatType == CHAR) {
		if (fgets(v, MaxVertices, fp)) {
			line_len = (int)strlen(v);
			v[line_len] = '\0';
		}
	}
	else if (WhatType == INT) {
		char line[MaxVertices*2];
		if (fgets(line, MaxVertices * 2, fp)) { // 读取一行  
			char* token;
			strtok_s(line, " \t\n", &token); // 使用空格、制表符和换行符作为分隔符  
			while (token != NULL && int_count < MaxVertices) { // 遍历所有整数，直到没有更多或达到数组大小  
				ints[int_count++] = atoi(token); // 将字符串转换为整数并存储  
				strtok_s(NULL, " \t\n", &token); // 继续查找下一个整数  
			}
		}
	}
	char line[16];
	RowColWeight d[MaxVertices > 2 ? MaxVertices * (MaxVertices - 1) / 2 : 2] = {};
	int i = 0;
	bool weightflag = false;
	while (fgets(line, 16, fp)) {
		sscanf_s(line, "%d %d %d", &d[i].col, &d[i].row, &d[i].weight);
		if (d[i].weight != 0)
			weightflag = true;
		i++;
	}
	if (WhatType == CHAR) {
		GraphCreate(G, (VertType*)v, line_len - 1, d, i + 1, weightflag, isDirected);
	}
	else if (WhatType == INT) {
		GraphCreate(G, (VertType*)ints, int_count, d, i + 1, weightflag, isDirected);
	}
	fclose(fp);
	return 1;
}

void GraphOutDegree(Graph G) {
	for (int i = 0 ;i < G.numOfVerts;i++) {
		Edge* p = G.a[i].adj;
		int count = 0;
		while (p != NULL) {
			if (p->dest != i) {
				count++;
			}
			p = p->next;
		}
		printf(vt": %d\n", G.a[i].data, count);
	}
}

void GraphInDegree(Graph G) {
	int inDegree[MaxVertices] = { 0 }; // 用于存储每个顶点的入度  

	// 遍历图中的每条边  
	for (int i = 0; i < G.numOfVerts; i++) {
		Edge* p = G.a[i].adj;
		while (p != NULL) {
			// 对于每条边，增加其终点的入度  
			inDegree[p->dest]++;
			p = p->next;
		}
	}

	// 打印每个顶点的入度  
	for (int i = 0; i < G.numOfVerts; i++) {
		printf(vt": %d\n", G.a[i].data, inDegree[i]);
	}
}

typedef struct MinSpanTree {
	VertType vertexA;
	VertType vertexB;
	int weight;
} MinSpanTree;
#include <limits.h>

// 普里姆算法求最小生成树  
void GraphPrime(Graph G, MinSpanTree* mstEdges, int* mstSize) {
	int n = G.numOfVerts;
	int* lowCost = (int*)malloc(sizeof(int) * n);
	int* parent = (int*)malloc(sizeof(int) * n); // 记录每个顶点的前驱顶点  
	bool* inMST = (bool*)malloc(sizeof(bool) * n); // 标记顶点是否在最小生成树中  
	if (lowCost == NULL || parent == NULL || inMST == NULL) {
		printf("内存块分配失败！");
		return;
	}
	for (int i = 0; i < n; i++) {
		lowCost[i] = INT_MAX; // 初始化为无穷大  
		inMST[i] = false; // 初始时所有顶点都不在最小生成树中  
		parent[i] = -1; // 初始化前驱顶点为-1，表示未设置  
	}
	lowCost[0] = 0; // 起始顶点到自身的距离为0  

	int count = 0; // 记录已经加入到最小生成树的边数量  
	for (int i = 0; i <= n - 1; i++) { // n-1条边形成最小生成树  
		int minIndex = -1;
		int minCost = INT_MAX;

		// 找到当前未加入最小生成树且权重最小的顶点  
		for (int j = 0; j < n; j++) {
			if (!inMST[j] && lowCost[j] < minCost) {
				minCost = lowCost[j];
				minIndex = j;
			}
		}
		// 将找到的顶点加入到最小生成树中  
		inMST[minIndex] = true;
		if (parent[minIndex] != -1) { // 确保有前驱顶点  
			mstEdges[count].vertexA = G.a[parent[minIndex]].data;
			mstEdges[count].vertexB = G.a[minIndex].data;
			mstEdges[count].weight = minCost;  
			printf("( ");
			printf(vt", ", mstEdges[count].vertexA);
			printf(vt", ", mstEdges[count].vertexB);
			printf("%d )\n", mstEdges[count].weight);
			count++;
		}
		// 更新相邻顶点的权重  
		for (Edge* p = G.a[minIndex].adj; p != NULL; p = p->next) {
			int dest = p->dest;
			if (!inMST[dest] && p->weight < lowCost[dest]) {
				lowCost[dest] = p->weight;
				parent[dest] = minIndex; // 更新前驱顶点  
			}
		}
	}
	*mstSize = count; // 更新最小生成树的边数  
	free(lowCost);
	free(parent);
	free(inMST);
}

int FindSet(int parent[], int i) {
	if (parent[i] != i) {
		// 路径压缩  
		parent[i] = FindSet(parent, parent[i]);
	}
	return parent[i];
}

void Union(int parent[], int rank[], int x, int y) {
	int rootX = FindSet(parent, x);
	int rootY = FindSet(parent, y);

	if (rootX != rootY) {
		if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++; // 如果秩相同，则增加rootX的秩  
		}
	}
}

void SortEdges(MinSpanTree edges[], int edgesIndex) {
	for (int i = 0; i < edgesIndex - 1; i++) {
		for (int j = 0; j < edgesIndex - i - 1; j++) {
			if (edges[j].weight > edges[j + 1].weight) {
				// 交换edges[j]和edges[j+1]  
				MinSpanTree temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
}

void CollectEdges(GNode* vertices, int numOfVerts, MinSpanTree* edges, int* edgesIndex) {
	for (int i = 0; i < numOfVerts; i++) {
		Edge* p = vertices[i].adj;
		while (p != NULL) {
			edges[*edgesIndex].vertexA = i; // 起点  
			edges[*edgesIndex].vertexB = p->dest; // 终点  
			edges[*edgesIndex].weight = p->weight; // 权重  
			(*edgesIndex)++;
			p = p->next; // 遍历下一条边  
		}
	}
}

// 克鲁斯卡尔算法求最小生成树  
void GraphKruskal(Graph G, MinSpanTree* mstEdges, int* mstSize) {
	int n = G.numOfVerts;
	int e = 0; // 记录当前加入最小生成树的边数  
	int* parent = (int*)malloc(sizeof(int) * n); // 并查集的parent数组  
	int* rank = (int*)malloc(sizeof(int) * n); // 并查集的rank数组  
	MinSpanTree* edges = (MinSpanTree*)malloc(sizeof(MinSpanTree) * G.numOfEdges * n); // 假设每条边都唯一（可能过多分配）  
	int edgesIndex = 0; // 边的索引  
	// 初始化并查集  
	for (int i = 0; i < n; i++) {
		parent[i] = i; // 每个顶点开始时都是自己集合的代表  
		rank[i] = 0; // 秩初始化为0  
	}
	// 遍历所有顶点，收集所有的边到edges数组中  
	CollectEdges(G.a, G.numOfVerts, edges, &edgesIndex);
	// 对edges数组中的边进行排序（按权重升序）  
	SortEdges(edges, edgesIndex);
	// 选择边并加入最小生成树，但不超过maxEdges条边  
	for (int i = 0; i < edgesIndex && e < MaxEdges && e < n - 1; i++) { // 最多需要n-1条边来构成最小生成树，但不超过maxEdges  
		int rootA = FindSet(parent, edges[i].vertexA);
		int rootB = FindSet(parent, edges[i].vertexB);
		if (rootA != rootB) { // 如果两个顶点不在同一个集合中（即不构成环）  
			mstEdges[e].vertexA = edges[i].vertexA;
			mstEdges[e].vertexB = edges[i].vertexB;
			mstEdges[e].weight = edges[i].weight;
			printf("( ");
			printf(vt", ", mstEdges[e].vertexA+65);
			printf(vt", ", mstEdges[e].vertexB+65);
			printf("%d )\n", mstEdges[e].weight);
			e++;
			Union(parent, rank, rootA, rootB); // 合并两个集合  
		}
	}
	*mstSize = e; // 更新最小生成树的边数  
	// 释放内存  
	free(parent);
	free(rank);
	free(edges);
}