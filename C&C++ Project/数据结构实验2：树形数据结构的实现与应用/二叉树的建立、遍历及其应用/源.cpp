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
    printf("请输入一个由L和R组成的字符串，现指针指向根节点，L使指针指向左孩子，R使指针指向右孩子：\n>>");
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
            printf("指针操作错误！");
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
        printf("已成功读取%s的二叉树！\n请选择操作：\n", path);
        printf("查找元素      [Q]   以先序打印    [W]   以中序RDL打印 [E]   绘制二叉树图像[R]   保存二叉树图像[T]   层序输出      [Y]\n");
        printf("非递归先序输出[U]   非递归中序输出[I]   非递归后序输出[O]   递归式先序输出[P]   递归式中序输出[A]   递归式后序输出[S]\n");
        printf("左插入节点    [D]   右插入节点    [F]   删除左子树    [G]   删除右子树    [H]   查看二叉树深度[J]   查看(非)叶节点[K]\n");
        printf("判断完全二叉树[L]   文件保存二叉树[Z]   安全结束程序  [ESC]\n\n");
        
        char key = _getch();
        key = (key >= 'a' && key <= 'z') ? key - 'a' + 'A' : key;
        ElemType data;
        switch (key) {

        case 'Q':
            printf("请输要查找的元素：");
            scanf_s(" %c", &data, static_cast<unsigned int>(sizeof(data)));
            if (BiTreeSearch(*root, data) != NULL)
                printf("已找到data=%c的节点", data);
            else
                printf("未找到data=%c的节点", data);
            break;

        case 'W':
            printf("以先序打印：\n");
            BiTreePrint_DLR(*root);
            break;

        case 'E':
            printf("以中序RDL打印：\n");
            BiTreePrint_RDL(*root);
            break;

        case 'R':
            BiTreeDraw(*root, "");
            printf("二叉树图像已绘制，见绘图界面...\n");
            printf("关闭绘图界面后可继续运行程序...\n");
            break;

        case 'T': { // 避免“控制传输跳过的实例化”
            printf("请输入保存二叉树图像的相对路径或绝对路径：");
            char path[200];
            scanf_s("%s", path, static_cast<unsigned int>(sizeof(path)));
            BiTreeDraw(*root, path);
            break;
        }

        case 'Y':
            printf("层序输出：");
            BiTreeTrav_Leve(*root, PrintfVisit);
            break;

        case 'U':
            printf("先序表达式：");
            BiTreeOut_Prefix(*root);
            break;

        case 'I':
            printf("中序表达式：");
            BiTreeOut_Infix(*root);
            break;

        case 'O':
            printf("后序表达式：");
            BiTreeOut_Postfix(*root);
            break;

        case 'P':
            printf("先序表达式：");
            BiTreeTrav_Prefix(*root, PrintfVisit);
            break;

        case 'A':
            printf("中序表达式：");
            BiTreeTrav_Infix(*root, PrintfVisit);
            break;

        case 'S':
            printf("后序表达式：");
            BiTreeTrav_Postfix(*root, PrintfVisit);
            break;

        case 'D': // 不使用括号：“p”的初始化操作由“case”标签跳过，并且p重复定义
        {
            BiTreePrint_DLR(*root);
            printf("左插入节点：\n");
            printf("请输入要插入的节点的data域：");
            ElemType data1;
            scanf_s(" %c", &data1, static_cast<unsigned int>(sizeof(data1)));
            BiTreeNode* p = GetP(*root);
            if (LeftInsert(&p, data1)) {
                printf("插入成功！\n");
                BiTreePrint_DLR(*root);
            }
            break;
        }

        case 'F':
        {
            BiTreePrint_DLR(*root);
            printf("右插入节点：\n");
            printf("请输入要插入的节点的data域：");
            ElemType data2;
            scanf_s(" %c", &data2, static_cast<unsigned int>(sizeof(data2)));
            BiTreeNode* p = GetP(*root);
            if (RightInsert(&p, data2)) {
                printf("插入成功！\n");
                BiTreePrint_DLR(*root);
            }
            break;
        }

        case 'G':
        {
            BiTreePrint_DLR(*root);
            printf("左删除节点：\n");
            BiTreeNode* p = GetP(*root);
            LeftDelete(&p);
            printf("删除成功！\n");
            BiTreePrint_DLR(*root);
            break;
        }

        case 'H':
        {
            BiTreePrint_DLR(*root);
            printf("右删除节点：\n");
            BiTreeNode* p = GetP(*root);
            RightDelete(&p);
            printf("删除成功！\n");
            BiTreePrint_DLR(*root);
            break;
        }

        case 'J':
            printf("二叉树深度：%d",BiTreeDepth(*root));
            break;

        case 'K':
            printf("叶子节点：");
            BiTreeLeaf(*root, PrintfVisit, true);
            printf("\n非叶子节点：");
            BiTreeLeaf(*root, PrintfVisit, false);
            break;

        case 'L':
            if (BiTreeComplete(*root) == true)
                printf("该二叉树是完全二叉树。\n");
            else
                printf("该二叉树不是完全二叉树。\n");
            break;

        case 'Z':
            BiTreeWriteFile(*root, path);
            printf("二叉树已保存至%s", path);
            break;

        case 27:
            system("cls");
            printf("已退出菜单。");
            BiTreeDestory(root);
            while_break = true;
            break;
        }
        if (while_break == true)
            break;
        else {
            printf("\n\n点击任意键继续...");
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
    
    printf("\n测试哈夫曼编码：\n");
    int i, j, n = 4;
    int weight[] = { 1, 3, 5, 7 };
    HaffNode* myHaffTree = (HaffNode*)malloc(sizeof(HaffNode) * (2 * static_cast<unsigned long long>(n) - 1));
    HaffCode* myHaffCode = (HaffCode*)malloc(sizeof(HaffCode) * n);
    if (myHaffTree == NULL || myHaffCode == NULL)
        exit(0);
    if (n > MaxBit) {
        printf("n越界！");
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