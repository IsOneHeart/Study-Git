#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <string.h>

#define MaxBit 100
#include "Xbitree.h"

void PrintfVisit(ElemType item) {
    printf("%c", item);
}

BiTreeNode* GetP(BiTreeNode* root) {
    printf("������һ����L��R��ɵ��ַ�������ָ��ָ����ڵ㣬Lʹָ��ָ�����ӣ�Rʹָ��ָ���Һ��ӣ�\n>>");
    char p_path[50];
    scanf_s("%s", p_path, static_cast<unsigned int>(sizeof(p_path)));
    BiTreeNode* p = root;
    for (int i = 0;p != NULL && p_path[i] != '\0';i++) {
        if (p->left != NULL && p_path[i] == 'L') {
            p = p->left;
        }
        else if (p->right != NULL && p_path[i] == 'R') {
            p = p->right;
        }
        else {
            printf("ָ���������");
            return NULL;
        }
    }
    return p;
}

void BiTreeMenu(BiTreeNode** root, const char* path) {
    bool while_break = false;
    while (1) {
        system("cls");
        //fflush(stdin);
        printf("�ѳɹ���ȡ%s�Ķ�������\n��ѡ�������\n", path);
        printf("����Ԫ��      [Q]   �������ӡ    [W]   ������RDL��ӡ [E]   ���ƶ�����ͼ��[R]   ���������ͼ��[T]   �������      [Y]\n");
        printf("�ǵݹ��������[U]   �ǵݹ��������[I]   �ǵݹ�������[O]   �ݹ�ʽ�������[P]   �ݹ�ʽ�������[A]   �ݹ�ʽ�������[S]\n");
        printf("�����ڵ�    [D]   �Ҳ���ڵ�    [F]   ɾ��������    [G]   ɾ��������    [H]   �鿴���������[J]   �鿴(��)Ҷ�ڵ�[K]\n");
        printf("�ж���ȫ������[L]   �ļ����������[Z]   ��ȫ��������  [ESC]\n\n");
        
        char key = _getch();
        key = (key >= 'a' && key <= 'z') ? key - 'a' + 'A' : key;
        ElemType data;
        switch (key) {

        case 'Q':
            printf("����Ҫ���ҵ�Ԫ�أ�");
            scanf_s(" %c", &data, static_cast<unsigned int>(sizeof(data)));
            if (BiTreeSearch(*root, data) != NULL)
                printf("���ҵ�data=%c�Ľڵ�", data);
            else
                printf("δ�ҵ�data=%c�Ľڵ�", data);
            break;

        case 'W':
            printf("�������ӡ��\n");
            BiTreePrint_DLR(*root);
            break;

        case 'E':
            printf("������RDL��ӡ��\n");
            BiTreePrint_RDL(*root);
            break;

        case 'R':
            BiTreeDraw(*root, "");
            printf("������ͼ���ѻ��ƣ�����ͼ����...\n");
            printf("�رջ�ͼ�����ɼ������г���...\n");
            break;

        case 'T': { // ���⡰���ƴ���������ʵ������
            printf("�����뱣�������ͼ������·�������·����");
            char path[200];
            scanf_s("%s", path, static_cast<unsigned int>(sizeof(path)));
            BiTreeDraw(*root, path);
            break;
        }

        case 'Y':
            printf("���������");
            BiTreeTrav_Leve(*root, PrintfVisit);
            break;

        case 'U':
            printf("������ʽ��");
            BiTreeOut_Prefix(*root);
            break;

        case 'I':
            printf("������ʽ��");
            BiTreeOut_Infix(*root);
            break;

        case 'O':
            printf("������ʽ��");
            BiTreeOut_Postfix(*root);
            break;

        case 'P':
            printf("������ʽ��");
            BiTreeTrav_Prefix(*root, PrintfVisit);
            break;

        case 'A':
            printf("������ʽ��");
            BiTreeTrav_Infix(*root, PrintfVisit);
            break;

        case 'S':
            printf("������ʽ��");
            BiTreeTrav_Postfix(*root, PrintfVisit);
            break;

        case 'D': // ��ʹ�����ţ���p���ĳ�ʼ�������ɡ�case����ǩ����������p�ظ�����
        {
            BiTreePrint_DLR(*root);
            printf("�����ڵ㣺\n");
            printf("������Ҫ����Ľڵ��data��");
            ElemType data1;
            scanf_s(" %c", &data1, static_cast<unsigned int>(sizeof(data1)));
            BiTreeNode* p = GetP(*root);
            if (LeftInsert(&p, data1)) {
                printf("����ɹ���\n");
                BiTreePrint_DLR(*root);
            }
            break;
        }

        case 'F':
        {
            BiTreePrint_DLR(*root);
            printf("�Ҳ���ڵ㣺\n");
            printf("������Ҫ����Ľڵ��data��");
            ElemType data2;
            scanf_s(" %c", &data2, static_cast<unsigned int>(sizeof(data2)));
            BiTreeNode* p = GetP(*root);
            if (RightInsert(&p, data2)) {
                printf("����ɹ���\n");
                BiTreePrint_DLR(*root);
            }
            break;
        }

        case 'G':
        {
            BiTreePrint_DLR(*root);
            printf("��ɾ���ڵ㣺\n");
            BiTreeNode* p = GetP(*root);
            LeftDelete(&p);
            printf("ɾ���ɹ���\n");
            BiTreePrint_DLR(*root);
            break;
        }

        case 'H':
        {
            BiTreePrint_DLR(*root);
            printf("��ɾ���ڵ㣺\n");
            BiTreeNode* p = GetP(*root);
            RightDelete(&p);
            printf("ɾ���ɹ���\n");
            BiTreePrint_DLR(*root);
            break;
        }

        case 'J':
            printf("��������ȣ�%d",BiTreeDepth(*root));
            break;

        case 'K':
            printf("Ҷ�ӽڵ㣺");
            BiTreeLeaf(*root, PrintfVisit, true);
            printf("\n��Ҷ�ӽڵ㣺");
            BiTreeLeaf(*root, PrintfVisit, false);
            break;

        case 'L':
            if (BiTreeComplete(*root) == true)
                printf("�ö���������ȫ��������\n");
            else
                printf("�ö�����������ȫ��������\n");
            break;

        case 'Z':
            BiTreeWriteFile(*root, path);
            printf("�������ѱ�����%s", path);
            break;

        case 27:
            system("cls");
            printf("���˳��˵���");
            BiTreeDestory(root);
            while_break = true;
            break;
        }
        if (while_break == true)
            break;
        else {
            printf("\n\n������������...");
            char key=_getch();
        }
    }
}

int main() {
    BiTreeNode* root;
    BiTreeInitiate(&root);
    char path[20] = "bitree.dat";
    BiTreeReadFile(&root, path);
    BiTreeMenu(&root, path);
    BiTreeDestory(&root);
    
    printf("\n���Թ��������룺\n");
    int i, j, n = 4;
    int weight[] = { 1, 3, 5, 7 };
    HaffNode* myHaffTree = (HaffNode*)malloc(sizeof(HaffNode) * (2 * static_cast<unsigned long long>(n) - 1));
    HaffCode* myHaffCode = (HaffCode*)malloc(sizeof(HaffCode) * n);
    if (myHaffTree == NULL || myHaffCode == NULL)
        exit(0);
    if (n > MaxBit) {
        printf("nԽ�磡");
        exit(1);
    }
    HaffmanCreate(weight, n, myHaffTree);
    HaffmanCode(myHaffTree, n, myHaffCode);
    for (i = 0; i < n; i++) {
        printf("Weight= %d\tCode= ", myHaffCode[i].weight);
        for (j = myHaffCode[i].start; j < n; j++)
            printf("%d", myHaffCode[i].bit[j]);
        printf("\n");
    }
    free(myHaffTree);
    free(myHaffCode);
    return 0;
}