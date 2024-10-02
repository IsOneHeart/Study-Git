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

/* �ڽӾ��� */
typedef struct AdjMGraph {
	Node* Vertices; //��Ŷ��������
	int edge[MaxVertices][MaxVertices]; //��űߵ��ڽӾ���
	int numOfEdges; //�ߵ�����
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
		printf("����v1��v2Խ�����");
		return;
	}
	G->edge[v1][v2] = weight;
	G->numOfEdges++;
}

void AdjMGraphDeleteEdge(AdjMGraph* G, int v1, int v2) {
	int len = ListLen(G->Vertices);
	if (v1<0 || v1> len || v2 < 0 
		|| v2 >= len|| v1 == v2) {
		printf("����v1��v2����");
		return;
	}
	if (G->edge[v1][v2] == MaxWeight || v1 == v2) {
		printf("�ñ߲����ڣ�");
		return;
	}
	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}

int AdjMGraphGetFirstVex(AdjMGraph G, int v) {
	int col;
	int len = ListLen(G.Vertices);
	if (v < 0 || v >= len) {
		printf("����vԽ�����");
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
		printf("����v1�����v2Խ�����");
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
	printf("���㼯�ϣ�\n");
	ListPrint(G.Vertices);
	printf("Ȩֵ���ϣ�\n");
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
	int dest; //�ڽӱߵĻ�ͷ�������
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
		printf("����Խ�磡\n");
}

void GraphInsertEdge(Graph* G, int v1, int v2, bool isDirected, int weight = 0) {
	Edge* p;
	if (v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts) {
		printf("����v1�����v2Խ�����");
		return;
	}

	// �����v1��v2�ı�  
	p = (Edge*)malloc(sizeof(Edge));
	if (p == NULL) {
		printf("�ڴ�����ʧ�ܣ�\n");
		return;
	}
	p->dest = v2;
	p->weight = weight;
	p->next = G->a[v1].adj;
	G->a[v1].adj = p;
	G->numOfEdges++;

	// ���������ͼ����������v2��v1�ı�  
	if (!isDirected) {
		p = (Edge*)malloc(sizeof(Edge));
		if (p == NULL) {
			printf("�ڴ�����ʧ�ܣ�\n");
			return;
		}
		p->dest = v1;
		p->weight = weight;
		p->next = G->a[v2].adj;
		G->a[v2].adj = p;
		//G->numOfEdges++; // ��������ͼ��ÿ���һ���ߣ���������2����Ϊ˫��  
	}
}

void GraphDeleteEdge(Graph* G, int v1, int v2) {
	Edge* curr, * pre;
	if (v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts) {
		printf("����v1��v2Խ�����");
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
		printf("����v1��v2Խ�����");
		return -1;
	}
	p = G.a[v].adj;
	if (p != NULL)
		return p->dest;
	return -1;
}

int GraphGetNextVex(Graph G, int v1, int v2) {
	Edge* p;
	Edge* prev = NULL; // ���ڱ���ǰһ��ָ��
	if (v1 < 0 || v1 >= G.numOfVerts || v2 < 0 || v2 >= G.numOfVerts) {
		printf("����v1��v2Խ�����");
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
		prev = p; // ����prevΪ��ǰ�ڵ�  
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
		Edge* p = G.a[i].adj; // ��ȡ��ǰ������ڽӱ�ͷָ��  
		while (p != NULL) { // ������ǰ��������б�  
			// ��ӡ�ߵ���ʼ���㡢��ֹ�����Ȩ��  
			printf("(%c, %c, %d)\n", G.a[i].data, G.a[p->dest].data, p->weight);
			p = p->next; // �ƶ�����һ����  
		}
	}
}

#define INF -1
void GraphPrintForm(Graph G) {
	printf("\n");
	printf("��-��\t");
	for (int j = 0; j < G.numOfVerts; j++) {
		printf(vt"\t", G.a[j].data); // ��ӡ�б��⣨�����㣩  
	}
	printf("\n\n");

	for (int i = 0; i < G.numOfVerts; i++) {
		printf(vt"\t", G.a[i].data); // ��ӡ�б��⣨����㣩  
		for (int j = 0; j < G.numOfVerts; j++) {
			int weight = INF; // �����ʼȨ��Ϊ������ޱߣ�  
			Edge* p = G.a[i].adj; // ��ȡ��ǰ������ڽӱ�ͷָ��  
			while (p != NULL && p->dest != j) { // ������ǰ��������бߣ��ҵ���j�ı�  
				p = p->next;
			}
			if (p != NULL) { // ����ҵ��˵�j�ı�  
				weight = p->weight; // ��ȡ�ߵ�Ȩ��  
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
			q = p->next; // ������һ���ߵ�ָ��  
			free(p);     // �ͷŵ�ǰ�ߵ��ڴ�  
			p = q;       // �ƶ�����һ����  
		}
		G->a[i].adj = NULL; // ����ǰ������ڽӱ�ͷ����ΪNULL  
	}  
}

void GraphDepthFirstSearch(Graph G, int v, int visited[], void visit(VertType item)) {
	Edge* p;

	// ���ʽڵ�v  
	visit(G.a[v].data);
	visited[v] = 1;

	// �����ڵ�v�������ڽӽڵ�  
	for (p = G.a[v].adj; p != NULL; p = p->next) {
		int w = p->dest; // ����Edge�ṹ������һ��dest��Ա��ʾĿ��ڵ�  
		if (!visited[w]) {
			GraphDepthFirstSearch(G, w, visited, visit);
		}
	}
}

int GraphDepthFirstSearch(Graph G, void visit(VertType item)) {
	int* visited = (int*)malloc(sizeof(int) * G.numOfVerts);
	if (visited == NULL) {
		printf("�����ڴ��ʧ�ܣ�");
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
		printf("�����ڴ��ʧ�ܣ�");
		return 0;
	}
	QueueInitiate(&queue); // ��ʼ������  
	for (i = 0; i < G.numOfVerts; i++) {
		visited[i] = 0;
	} 
	for (i = 0; i < G.numOfVerts; i++) {
		if (!visited[i]) {
			GraphBroadFirstSearch(G, i, visited, visit, &queue); // ������е�ָ��  
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
		printf("�ļ���ʧ�ܣ�");
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
		if (fgets(line, MaxVertices * 2, fp)) { // ��ȡһ��  
			char* token;
			strtok_s(line, " \t\n", &token); // ʹ�ÿո��Ʊ���ͻ��з���Ϊ�ָ���  
			while (token != NULL && int_count < MaxVertices) { // ��������������ֱ��û�и����ﵽ�����С  
				ints[int_count++] = atoi(token); // ���ַ���ת��Ϊ�������洢  
				strtok_s(NULL, " \t\n", &token); // ����������һ������  
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
	int inDegree[MaxVertices] = { 0 }; // ���ڴ洢ÿ����������  

	// ����ͼ�е�ÿ����  
	for (int i = 0; i < G.numOfVerts; i++) {
		Edge* p = G.a[i].adj;
		while (p != NULL) {
			// ����ÿ���ߣ��������յ�����  
			inDegree[p->dest]++;
			p = p->next;
		}
	}

	// ��ӡÿ����������  
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

// ����ķ�㷨����С������  
void GraphPrime(Graph G, MinSpanTree* mstEdges, int* mstSize) {
	int n = G.numOfVerts;
	int* lowCost = (int*)malloc(sizeof(int) * n);
	int* parent = (int*)malloc(sizeof(int) * n); // ��¼ÿ�������ǰ������  
	bool* inMST = (bool*)malloc(sizeof(bool) * n); // ��Ƕ����Ƿ�����С��������  
	if (lowCost == NULL || parent == NULL || inMST == NULL) {
		printf("�ڴ�����ʧ�ܣ�");
		return;
	}
	for (int i = 0; i < n; i++) {
		lowCost[i] = INT_MAX; // ��ʼ��Ϊ�����  
		inMST[i] = false; // ��ʼʱ���ж��㶼������С��������  
		parent[i] = -1; // ��ʼ��ǰ������Ϊ-1����ʾδ����  
	}
	lowCost[0] = 0; // ��ʼ���㵽����ľ���Ϊ0  

	int count = 0; // ��¼�Ѿ����뵽��С�������ı�����  
	for (int i = 0; i <= n - 1; i++) { // n-1�����γ���С������  
		int minIndex = -1;
		int minCost = INT_MAX;

		// �ҵ���ǰδ������С��������Ȩ����С�Ķ���  
		for (int j = 0; j < n; j++) {
			if (!inMST[j] && lowCost[j] < minCost) {
				minCost = lowCost[j];
				minIndex = j;
			}
		}
		// ���ҵ��Ķ�����뵽��С��������  
		inMST[minIndex] = true;
		if (parent[minIndex] != -1) { // ȷ����ǰ������  
			mstEdges[count].vertexA = G.a[parent[minIndex]].data;
			mstEdges[count].vertexB = G.a[minIndex].data;
			mstEdges[count].weight = minCost;  
			printf("( ");
			printf(vt", ", mstEdges[count].vertexA);
			printf(vt", ", mstEdges[count].vertexB);
			printf("%d )\n", mstEdges[count].weight);
			count++;
		}
		// �������ڶ����Ȩ��  
		for (Edge* p = G.a[minIndex].adj; p != NULL; p = p->next) {
			int dest = p->dest;
			if (!inMST[dest] && p->weight < lowCost[dest]) {
				lowCost[dest] = p->weight;
				parent[dest] = minIndex; // ����ǰ������  
			}
		}
	}
	*mstSize = count; // ������С�������ı���  
	free(lowCost);
	free(parent);
	free(inMST);
}

int FindSet(int parent[], int i) {
	if (parent[i] != i) {
		// ·��ѹ��  
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
			rank[rootX]++; // �������ͬ��������rootX����  
		}
	}
}

void SortEdges(MinSpanTree edges[], int edgesIndex) {
	for (int i = 0; i < edgesIndex - 1; i++) {
		for (int j = 0; j < edgesIndex - i - 1; j++) {
			if (edges[j].weight > edges[j + 1].weight) {
				// ����edges[j]��edges[j+1]  
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
			edges[*edgesIndex].vertexA = i; // ���  
			edges[*edgesIndex].vertexB = p->dest; // �յ�  
			edges[*edgesIndex].weight = p->weight; // Ȩ��  
			(*edgesIndex)++;
			p = p->next; // ������һ����  
		}
	}
}

// ��³˹�����㷨����С������  
void GraphKruskal(Graph G, MinSpanTree* mstEdges, int* mstSize) {
	int n = G.numOfVerts;
	int e = 0; // ��¼��ǰ������С�������ı���  
	int* parent = (int*)malloc(sizeof(int) * n); // ���鼯��parent����  
	int* rank = (int*)malloc(sizeof(int) * n); // ���鼯��rank����  
	MinSpanTree* edges = (MinSpanTree*)malloc(sizeof(MinSpanTree) * G.numOfEdges * n); // ����ÿ���߶�Ψһ�����ܹ�����䣩  
	int edgesIndex = 0; // �ߵ�����  
	// ��ʼ�����鼯  
	for (int i = 0; i < n; i++) {
		parent[i] = i; // ÿ�����㿪ʼʱ�����Լ����ϵĴ���  
		rank[i] = 0; // �ȳ�ʼ��Ϊ0  
	}
	// �������ж��㣬�ռ����еıߵ�edges������  
	CollectEdges(G.a, G.numOfVerts, edges, &edgesIndex);
	// ��edges�����еı߽������򣨰�Ȩ������  
	SortEdges(edges, edgesIndex);
	// ѡ��߲�������С����������������maxEdges����  
	for (int i = 0; i < edgesIndex && e < MaxEdges && e < n - 1; i++) { // �����Ҫn-1������������С����������������maxEdges  
		int rootA = FindSet(parent, edges[i].vertexA);
		int rootB = FindSet(parent, edges[i].vertexB);
		if (rootA != rootB) { // ����������㲻��ͬһ�������У��������ɻ���  
			mstEdges[e].vertexA = edges[i].vertexA;
			mstEdges[e].vertexB = edges[i].vertexB;
			mstEdges[e].weight = edges[i].weight;
			printf("( ");
			printf(vt", ", mstEdges[e].vertexA+65);
			printf(vt", ", mstEdges[e].vertexB+65);
			printf("%d )\n", mstEdges[e].weight);
			e++;
			Union(parent, rank, rootA, rootB); // �ϲ���������  
		}
	}
	*mstSize = e; // ������С�������ı���  
	// �ͷ��ڴ�  
	free(parent);
	free(rank);
	free(edges);
}