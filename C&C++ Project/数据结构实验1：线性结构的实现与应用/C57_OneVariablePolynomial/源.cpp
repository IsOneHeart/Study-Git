#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Xlink_OVP.h"

void ReadFile(OVPNode* headp, OVPNode* headq) {
    FILE* fp, * fq;
    char buffer[100];
    OVPNode* p, * q;

    if ((fp = fopen("px.dat", "r")) == NULL) {
        printf("文件px.dat打开失败！");
        return;
    }
    p = headp;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {// 逐行读取数据并存储到链表中
        OVPNode* newNode = (OVPNode*)malloc(sizeof(OVPNode));
        if (newNode == NULL) {
            printf("内存块分配失败！\n");
            return ;
        }
        sscanf(buffer, "%f %d", &(newNode->P), &(newNode->power));
        newNode->next = NULL;

        OVPInsert(headp, newNode->P, newNode->power);
        free(newNode);
        fflush(stdin);
    }
    if (fclose(fp) != 0) {
        printf("文件px.dat不能正常关闭！");
        return;
    }

    if ((fq = fopen("qx.dat", "r")) == NULL) {
        printf("文件qx.dat打开失败！");
        return;
    }
    q = headq;
    while (fgets(buffer, sizeof(buffer), fq) != NULL) {
        OVPNode* newNode = (OVPNode*)malloc(sizeof(OVPNode));
        if (newNode == NULL) {
            printf("内存块分配失败！\n");
            return ;
        }
        sscanf(buffer, "%f %d", &(newNode->P), &(newNode->power));
        newNode->next = NULL;

        OVPInsert(headq, newNode->P, newNode->power);
        free(newNode);
        fflush(stdin);
    }
    if (fclose(fq) != 0) {
        printf("文件qx.dat不能正常关闭！");
        return;
    }

}

void ReadKeyboard(OVPNode* head) {
    float P;
    int power;
    printf("请输入一元多项式数据（格式：P power，输入0 0标记结束）：\n");

    do {
        scanf_s("%f %d", &P, &power); 

        OVPInsert(head, P, power);
    } while (P != 0 || power != 0);
}

int main() {
	OVPNode* headp, * headq;
	OVPInitiate(&headp);
	OVPInitiate(&headq);
	printf("请选择一元多项式读取方式：\n文件读取【1】 键盘输入【2】\n选择操作：");

	int HowRead;
	scanf_s("%d",& HowRead);
    if (HowRead == 1) {
        printf("\n");
        ReadFile(headp, headq);
    }
    else if (HowRead == 2) {
        ReadKeyboard(headp);
        ReadKeyboard(headq);
    }
    else {
        printf("操作无效！");
        return 0;
    }

    printf("读取/输入结果：\np(x)=");
	OVPPrint(headp);
	printf("\nq(x)=");
	OVPPrint(headq);
    printf("\n\n");

    printf("p(x)+q(x)=");
    OVPPrint(OVPAdd(headp, headq));
    printf("\n");
    printf("p(x)-q(x)=");
    OVPPrint(OVPMinus(headp, headq));
    printf("\n");

    OVPDestory(&headp);
    OVPDestory(&headq);

	return 0;
}