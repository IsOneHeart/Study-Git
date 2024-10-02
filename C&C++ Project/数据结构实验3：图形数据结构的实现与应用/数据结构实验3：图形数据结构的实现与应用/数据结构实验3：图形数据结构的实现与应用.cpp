#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "YXgraph.h"

void PrintfVisit(VertType item) {
	printf("%c", item);
}

void menu() {
	system("cls");
	printf("[1]用邻接矩阵作为储结构存储图并输出该邻接矩阵（不提供文件操作）\n");
	printf("[2]通过文件读取方式输入带权无向图\n");
	printf("[3]用邻接链表作为储结构存储图并输出该邻接链表\n");
	printf("[4]按深度优先遍历(DFS)算法输出图中顶点的遍历序列\n");
	printf("[5]按广度优先遍历(BFS)算法输出图中顶点的遍历序列\n");
	printf("[6]图G中各顶点的入度和出度\n");
	printf("[7]使用Prime算法从某个指定的顶点出发输出图的最小生成树\n");
	printf("[8]使用Kruskal算法从某个指定的顶点出发输出图的最小生成树\n");
	printf("[9]退出\n");
	Graph G;
	GraphReadFile(&G, "graph.dat", CHAR, false);
	int key;
	printf("选择操作：");
	scanf_s("%d", &key);
	switch (key) {
	case 1:{
		AdjMGraph AdjMG;
		char v[] = { 'A','B','C','D','E','F','G','H','I','J' };
		int n = 10, e = 9;
		RowColWeight E[] = {
			{0,3,2},{0,6,6},{0,9,3},{1,2,1},{1,4,4},{1,4,8},{2,4,11},
			{3,5,5,},{4,9,7}
		};
		AdjMGraphCreate(&AdjMG, v, n, E, e);
		AdjMGraphPrint(AdjMG);
		break;
	}

	case 2: {
		printf("文件读取成功！");
		break;
	}

	case 3:
		GraphPrintForm(G);
		break;

	case 4:
		GraphDepthFirstSearch(G, PrintfVisit);
		printf("\n");
		break;

	case 5:
		GraphBroadFirstSearch(G, PrintfVisit);
		printf("\n");
		break;

	case 6:
		printf("入度：\n");
		GraphInDegree(G);
		printf("\n出度：");
		GraphOutDegree(G);
		break;

	case 7: {
		MinSpanTree mstEdges[MaxVertices * 2];
		int mstSize[MaxVertices * 2];
		GraphPrime(G, mstEdges, mstSize);
		break;
	}

	case 8: {
		MinSpanTree mstEdges[MaxVertices * 2];
		int mstSize[MaxVertices * 2];
		GraphKruskal(G, mstEdges, mstSize);
		break;
	}

	case 9:
		GraphDestory(&G);
		exit(0);
		break;
	}
	system("pause");
	GraphDestory(&G);
	menu();
}

int main() {
	menu();
	return 0;
}