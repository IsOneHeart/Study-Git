#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ElemType int
#define bt "%d"

#include "YXbitree.h"

void getRandomNumAbs1000(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 2000 - 1000;
    }
}

void copyArray(int src[], int dest[], int n) { // 复制数组
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

BiTreeNode *BiTreeSearchWithCount(BiTreeNode *root, ElemType x, count *c) {
    BiTreeNode *p;
    if (root == NULL)
        return NULL; // 递归出口
    if (root->data == x)
        return root;// 递归出口
    if (root->left != NULL) { // 查询左子树
        p = BiTreeSearchWithCount(root->left, x, c);
        if (p != NULL)
            return p;
    }
    if (root->right != NULL) { // 查询右子树
        p = BiTreeSearchWithCount(root->right, x, c);
        if (p != NULL)
            return p;
    }
    c->compare += 6;
    return NULL;
}

void visit(int item) {
    printf("%d ", item);
}

void getSearchResult(BiTreeNode *root, int key) {
    count count;
    BiTreeNode *result = BiTreeSearchWithCount(root, key, &count);
    printf("查找%d：", key);
    if (result != NULL) {
        printf("成功，比较次数为%d，地址为%p\n", count.compare, (void *) result);
    } else {
        printf("失败。\n");
    }
}

int main() {
    srand(time(NULL));
    BiTreeNode *root;
    BiTreeInitiate(&root);
    int array[10];
    getRandomNumAbs1000(array, 10);
    printf("排序前：\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    BSTreeCreateByArray(&root, array, 10);
    printf("\n以中序RDL打印：\n");
    BiTreePrint_RDL(root);
    printf("中序表达式：");
    BiTreeTrav_Infix(root, visit);
    printf("\n");
    getSearchResult(root, 0);
    getSearchResult(root, array[4]);
    count c=BSTreeDelete(&root, array[4]);
    printf("删除%d：比较次数为%d，移动次数为%d。", array[4], c.compare,c.move);
    printf("\n中序表达式：");
    BiTreeTrav_Infix(root, visit);
    BiTreeDestory(&root);
    return 0;
}
