#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Xlink_OVP.h"

void ReadFile(OVPNode* headp, OVPNode* headq) {
    FILE* fp, * fq;
    char buffer[100];
    OVPNode* p, * q;

    if ((fp = fopen("px.dat", "r")) == NULL) {
        printf("�ļ�px.dat��ʧ�ܣ�");
        return;
    }
    p = headp;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {// ���ж�ȡ���ݲ��洢��������
        OVPNode* newNode = (OVPNode*)malloc(sizeof(OVPNode));
        if (newNode == NULL) {
            printf("�ڴ�����ʧ�ܣ�\n");
            return ;
        }
        sscanf(buffer, "%f %d", &(newNode->P), &(newNode->power));
        newNode->next = NULL;

        OVPInsert(headp, newNode->P, newNode->power);
        free(newNode);
        fflush(stdin);
    }
    if (fclose(fp) != 0) {
        printf("�ļ�px.dat���������رգ�");
        return;
    }

    if ((fq = fopen("qx.dat", "r")) == NULL) {
        printf("�ļ�qx.dat��ʧ�ܣ�");
        return;
    }
    q = headq;
    while (fgets(buffer, sizeof(buffer), fq) != NULL) {
        OVPNode* newNode = (OVPNode*)malloc(sizeof(OVPNode));
        if (newNode == NULL) {
            printf("�ڴ�����ʧ�ܣ�\n");
            return ;
        }
        sscanf(buffer, "%f %d", &(newNode->P), &(newNode->power));
        newNode->next = NULL;

        OVPInsert(headq, newNode->P, newNode->power);
        free(newNode);
        fflush(stdin);
    }
    if (fclose(fq) != 0) {
        printf("�ļ�qx.dat���������رգ�");
        return;
    }

}

void ReadKeyboard(OVPNode* head) {
    float P;
    int power;
    printf("������һԪ����ʽ���ݣ���ʽ��P power������0 0��ǽ�������\n");

    do {
        scanf_s("%f %d", &P, &power); 

        OVPInsert(head, P, power);
    } while (P != 0 || power != 0);
}

int main() {
	OVPNode* headp, * headq;
	OVPInitiate(&headp);
	OVPInitiate(&headq);
	printf("��ѡ��һԪ����ʽ��ȡ��ʽ��\n�ļ���ȡ��1�� �������롾2��\nѡ�������");

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
        printf("������Ч��");
        return 0;
    }

    printf("��ȡ/��������\np(x)=");
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