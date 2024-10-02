#pragma once

#ifndef ElemType
#define ElemType char
#endif
#ifndef bt
#define bt "%c"
#endif
#ifndef MaxSaveSize
#define MaxSaveSize 100
#endif

typedef struct BTNode {
    ElemType data;
    struct BTNode *left;
    struct BTNode *right;
} BiTreeNode;

#define stype BiTreeNode*
#define type BiTreeNode*

#include "YXstack.h"
#include "YXqueue.h"

// 初始化建立二叉树的头节点
int BiTreeInitiate(BiTreeNode **root, ElemType data) {
    *root = (BiTreeNode *) malloc(sizeof(BiTreeNode));
    if (*root == NULL) {
        printf("初始化建立二叉树的头节点时分配内存块失败！\n");
        return 0;
    }
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
    return 1;
}

// 初始化建立二叉树的头节点（不初始化根元素的重载函数）
int BiTreeInitiate(BiTreeNode **root) {
    *root = (BiTreeNode *) malloc(sizeof(BiTreeNode));
    if (*root == NULL) {
        printf("初始化建立二叉树的头节点时分配内存块失败！\n");
        return 0;
    }
    (*root)->left = NULL;
    (*root)->right = NULL;
    return 1;
}

// 左插入节点
int LeftInsert(BiTreeNode **curr, ElemType data) {
    if (*curr == NULL) {
        return 0;
    }
    BiTreeNode *newleft, *oldleft;
    oldleft = (*curr)->left;
    newleft = (BiTreeNode *) malloc(sizeof(BiTreeNode));
    if (newleft == NULL) {
        printf("左节点内存分配失败！\n");
        return 0;
    }
    newleft->data = data;
    newleft->left = oldleft; // 将原左节点作为新左节点的左子树
    newleft->right = NULL;
    (*curr)->left = newleft;
    return 1;
}

// 右插入节点
int RightInsert(BiTreeNode **curr, ElemType data) {
    if (*curr == NULL) {
        return 0;
    }
    BiTreeNode *newright, *oldright;
    oldright = (*curr)->right;
    newright = (BiTreeNode *) malloc(sizeof(BiTreeNode));
    if (newright == NULL) {
        printf("右节点内存分配失败！\n");
        return 0;
    }
    newright->data = data;
    newright->left = oldright; // 将原右节点作为新右节点的右子树
    newright->right = NULL;
    (*curr)->right = newright;
    return 1;
}

// 释放树
void BiTreeDestory(BiTreeNode **root) {
    if (*root != NULL) { // 如果根节点不为空
        // 先递归销毁左子树
        BiTreeDestory(&(*root)->left);
        // 再递归销毁右子树
        BiTreeDestory(&(*root)->right);
        // 最后释放根节点
        free(*root);
        // 设置根节点指针为NULL，防止悬挂指针
        *root = NULL;
    }
}

// 删除左子树
int LeftDelete(BiTreeNode **curr) {
    if (*curr == NULL || (*curr)->left == NULL)
        return 0;
    BiTreeDestory(&(*curr)->left);
    (*curr)->left = NULL;
    return 1;
}

// 删除右子树
int RightDelete(BiTreeNode **curr) {
    if (*curr == NULL || (*curr)->right == NULL)
        return 0;
    BiTreeDestory(&(*curr)->right);
    (*curr)->right = NULL;
    return 1;
}

// 使用前缀表达式创建二叉树，'#'表示空
int BiTreeCreate(BiTreeNode **root, const char *str, int *index) {
    if (*index >= strlen(str) || str[*index] == '#') {
        *root = NULL;
        (*index)++;
        return 1;
    }
    *root = (BiTreeNode *) malloc(sizeof(BiTreeNode));
    if (!*root) {
        printf("内存分配失败！\n");
        return 0;
    }
    (*root)->data = str[*index];
    (*index)++; // 递增索引以指向下一个字符
    if (!BiTreeCreate(&(*root)->left, str, index))// 创建左子树
        return 0;
    if (!BiTreeCreate(&(*root)->right, str, index))// 创建右子树
        return 0;
    return 1;
}

void BiTreeCreate(BiTreeNode **root, const char *polish) {
    // 调用重载函数，引入第三个形参以判断是否结束递归
    int num = 0;
    BiTreeCreate(root, polish, &num);
}

// 从文件以前缀表达式读取二叉树 仅可用于当ElemType为char时
int BiTreeReadFile(BiTreeNode **root, const char *path) {
    FILE *fp;
    if (fopen_s(&fp, path, "r") != 0) {
        printf("打开%s失败！\n", path);
        return 0;
    }
    fseek(fp, 0, SEEK_END); // 将文件指针移到文件末尾
    long file_size = ftell(fp); // 获取文件大小
    fseek(fp, 0, SEEK_SET); // 将文件指针重新移到文件开头
    char *polish = (char *) malloc(static_cast<size_t>(file_size) + 1); // 加1用于存储字符串结束符'\0'
    if (polish == NULL) {
        printf("从文件以前缀表达式读取二叉树时内存分配失败！\n");
        fclose(fp);
        return 0;
    }
    fread(polish, 1, file_size, fp);
    polish[file_size] = '\0'; // 添加字符串结束符
    int num = 0;
    if (!BiTreeCreate(root, polish, &num)) {
        printf("创建二叉树失败！\n");
        free(polish);
        fclose(fp);
        return 0;
    }
    free(polish);
    fclose(fp);
    return 1;
}

void BiTreeSave(BiTreeNode *root, char *str, int *index) {
    if (root == NULL) {
        str[(*index)++] = '#';
        return;
    }
    str[(*index)++] = root->data;
    BiTreeSave(root->left, str, index);
    BiTreeSave(root->right, str, index);
    str[(*index)] = '\0';
}

int BiTreeWriteFile(BiTreeNode *root, const char *path) {
    char str[MaxSaveSize];
    int index = 0;
    BiTreeSave(root, str, &index);
    FILE *fp;
    if (fopen_s(&fp, path, "w") != 0) {
        printf("打开%s失败！\n", path);
        return 0;
    }
    fprintf(fp, "%s", str);
    fclose(fp);
    return 1;
}

// 用凹入表示法打印二叉树（中序RDL）
void BiTreePrint_RDL(BiTreeNode *root, int n) {
    if (root == NULL)
        return;
    BiTreePrint_RDL(root->right, n + 1);
    for (int i = 0; i < n; i++) {
        printf("   ");
    }
    if (n > 0) {
        printf("——");
    }
    //printf("[%c]\n", root->data);
    printf("[");
    printf(bt, root->data);
    printf("]\n");
    BiTreePrint_RDL(root->left, n + 1);
}

void BiTreePrint_RDL(BiTreeNode *root) {
    BiTreePrint_RDL(root, 0);
}

// 用凹入表示法打印二叉树（先序）
void BiTreePrint_DLR(BiTreeNode *root, int n) {
    if (root == NULL)
        return;
    for (int i = 0; i < n; i++) {
        printf("   ");
    }
    //printf("[%c]\n", root->data);
    printf("[");
    printf(bt, root->data);
    printf("]\n");
    if (root->left != NULL) {
        for (int i = 0; i < n; i++) {
            printf("   ");
        }
        printf("|——Left\n");
        BiTreePrint_DLR(root->left, n + 1);
    }
    if (root->right != NULL) {
        for (int i = 0; i < n; i++) {
            printf("   ");
        }
        printf("|——Right\n");
        BiTreePrint_DLR(root->right, n + 1);
    }
}

void BiTreePrint_DLR(BiTreeNode *root) {
    BiTreePrint_DLR(root, 0);
}

// 求二叉树的深度
int BiTreeDepth(BiTreeNode *root, int n) {
    if (root != NULL) {
        n++;
        if (BiTreeDepth(root->left, n) > BiTreeDepth(root->right, n))
            return BiTreeDepth(root->left, n);
        else
            return BiTreeDepth(root->right, n);
    } else
        return n;
}

int BiTreeDepth(BiTreeNode *root) {
    return BiTreeDepth(root, -1);
}

// 求当前指针所指节点的高度
int BiTreeNowHeight(BiTreeNode *root, BiTreeNode *curr) {
    if (root == NULL) {
        return -1;
    }
    if (root == curr) {
        return 0;
    }
    int leftDepth = BiTreeNowHeight(root->left, curr);
    if (leftDepth != -1) {
        return leftDepth + 1;
    }
    int rightDepth = BiTreeNowHeight(root->right, curr);
    return rightDepth != -1 ? rightDepth + 1 : -1;
}

// 绘制二叉树节点
void BiTreeDrawNode(BiTreeNode *curr, int n, int x, int y) {
    int tw = textwidth(curr->data), th = textheight(curr->data);
    int radius = (tw > th ? tw : th) / 2; // 半径是宽度和高度中较小值的一半
    int px = x, py = y - th / 2; // 文本中心位于y轴，圆的中心稍低于文本底部
    circle(px, py + radius, radius); // 绘制圆，圆心稍低于文本底部
    char data[2] = {(char) curr->data, '\0'};
    outtextxy(px - tw / 2, py, data); // 在文本中心位置输出字符
}

// 绘制二叉树
void BiTreeDrawPicture(BiTreeNode *root, int n, int x, int y) {
    if (root == NULL)
        return;
    int tw = textwidth(root->data), th = textheight(root->data);
    int radius = (tw > th ? tw : th) / 2;
    BiTreeDrawNode(root, n, x, y);
    double scaleFactor = pow(0.5, n);
    double minScaleFactor = 0.2; // 最小间距为原始间距的20%
    scaleFactor = fmax(scaleFactor, minScaleFactor);
    int leftX = x - textwidth(root->data) - (int) (radius * scaleFactor * 4); // 左子树水平位置
    int leftY = y + textheight(root->data) + (int) (radius * 2); // 垂直向下移动一定距离
    int rightX = x + textwidth(root->data) + (int) (radius * scaleFactor * 4); // 右子树水平位置
    int rightY = leftY; // 保持与左子树相同的垂直距离
    if (root->left != NULL) {
        // 绘制到左子树的线
        line(x - (int) (radius / sqrt(2)), y + (int) (radius / sqrt(2)), leftX + (int) (radius / sqrt(2)),
             leftY - (int) (radius / sqrt(2)));
        BiTreeDrawPicture(root->left, n + 1, leftX, leftY);
    }
    if (root->right != NULL) {
        // 绘制到右子树的线
        line(x + (int) (radius / sqrt(2)), y + (int) (radius / sqrt(2)), rightX - (int) (radius / sqrt(2)),
             rightY - (int) (radius / sqrt(2)));
        BiTreeDrawPicture(root->right, n + 1, rightX, rightY);
    }
}

// 创建绘图界面并保存二叉树图片
void BiTreeDraw(BiTreeNode *root, const char *path) {
    int depth = BiTreeDepth(root);
    int height = (depth + 1) * 150;
    int width = (depth + 1) * 160;
    initgraph(width, height, EX_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();
    setlinecolor(BLACK);
    settextcolor(BLACK);
    settextstyle(50, 0, "微软雅黑");
    setbkmode(TRANSPARENT);
    BiTreeDrawPicture(root, 0, getwidth() / 2, 50);
    if (strcmp(path, "") != 0) {
        saveimage(path);
        printf("二叉树图片已保存至%s", path);
    } else
        _getch();
    closegraph();
}

// 查找节点
BiTreeNode *BiTreeSearch(BiTreeNode *root, ElemType x) {
    BiTreeNode *p;
    if (root == NULL)
        return NULL; // 递归出口
    if (root->data == x)
        return root;// 递归出口
    if (root->left != NULL) { // 查询左子树
        p = BiTreeSearch(root->left, x);
        if (p != NULL)
            return p;
    }
    if (root->right != NULL) { // 查询右子树
        p = BiTreeSearch(root->right, x);
        if (p != NULL)
            return p;
    }
    return NULL;
}

// 非递归式输出先序表达式
void BiTreeOut_Prefix(BiTreeNode *root) {
    BiTreeNode *p = root;
    SNode *stack;
    StackInitiate(&stack);
    while (p != NULL || StackNotEmpty(stack)) {
        while (p != NULL) {
            printf(bt, p->data);
            StackPush(stack, p);
            p = p->left;
        }
        if (StackNotEmpty(stack)) {
            StackPop(stack, &p);
            p = p->right;
        }
    }
    StackDestory(&stack);
}

// 非递归式输出中序表达式
void BiTreeOut_Infix(BiTreeNode *root) {
    SNode *stack;
    StackInitiate(&stack);
    BiTreeNode *p = root;
    while (p != NULL || StackNotEmpty(stack)) {
        while (p != NULL) {
            StackPush(stack, p);
            p = p->left;
        }
        if (StackPop(stack, &p)) {
            printf(bt, p->data);
        }
        p = p->right;
    }
    StackDestory(&stack);
}

// 非递归式输出后序表达式
void BiTreeOut_Postfix(BiTreeNode *root) {
    SNode *stack;
    StackInitiate(&stack);
    BiTreeNode *p = root;
    BiTreeNode *prev = NULL; // 上一个访问的节点
    BiTreeNode *peek; // 临时存储栈顶元素
    while (p != NULL || StackNotEmpty(stack)) {
        // 遍历左子树
        while (p != NULL) {
            StackPush(stack, p);
            p = p->left;
        }
        // 访问栈顶节点，但不立即打印，先找到右子树的最右节点
        while (StackNotEmpty(stack)) {
            StackPop(stack, &peek);
            // 如果peek有右子节点且未被访问过，或者peek没有右子节点
            if (peek->right == NULL || peek->right == prev) {
                printf(bt, peek->data);
                prev = peek; // 更新prev为当前节点
                break;
            }
            // 否则将peek重新压入栈中，并继续遍历右子树
            StackPush(stack, peek);
            p = peek->right;
            while (p != NULL) {
                StackPush(stack, p);
                p = p->left;
            }
        }
        // 如果p为空，说明当前栈中的节点都没有右子节点或者右子节点都已经被访问过了
        p = NULL;
    }
    StackDestory(&stack);
}

// 递归式遍历先序表达式
void BiTreeTrav_Prefix(BiTreeNode *root, void visit(ElemType item)) {
    if (root != NULL) {
        visit(root->data);
        BiTreeTrav_Prefix(root->left, visit);
        BiTreeTrav_Prefix(root->right, visit);
    }
}

// 递归式遍历中序表达式
void BiTreeTrav_Infix(BiTreeNode *root, void visit(ElemType item)) {
    if (root != NULL) {
        BiTreeTrav_Infix(root->left, visit);
        visit(root->data);
        BiTreeTrav_Infix(root->right, visit);
    }
}

// 递归式遍历后序表达式
void BiTreeTrav_Postfix(BiTreeNode *root, void visit(ElemType item)) {
    if (root != NULL) {
        BiTreeTrav_Infix(root->left, visit);
        BiTreeTrav_Infix(root->right, visit);
        visit(root->data);
    }
}

// 二叉树的层序遍历
void BiTreeTrav_Leve(BiTreeNode *root, void visit(ElemType item)) {
    Queue queue;
    QueueInitiate(&queue);
    BiTreeNode *p = root;
    if (p != NULL) {
        QueueAppend(&queue, p); // 根结点入队
        while (QueueNotEmpty(queue)) {
            QueueDelete(&queue, &p);
            visit(p->data);
            if (p->left != NULL)
                QueueAppend(&queue, p->left); // 左结点入队
            if (p->right != NULL)
                QueueAppend(&queue, p->right); // 右结点入队
        }
    }
    QueueDestroy(&queue);
}

void BiTreeLeaf(BiTreeNode *root, void visit(ElemType item), bool isleap) {
    if (root == NULL)
        return;
    BiTreeNode *p = root;
    if (isleap) {
        if (p->left == NULL && p->right == NULL)
            visit(root->data);
        BiTreeLeaf(root->left, visit, true);
        BiTreeLeaf(root->right, visit, true);
    } else {
        if (p->left != NULL || p->right != NULL)
            visit(root->data);
        BiTreeLeaf(root->left, visit, false);
        BiTreeLeaf(root->right, visit, false);
    }
}

// 判断完全二叉树
bool BiTreeComplete(BiTreeNode *root) {
    if (root == NULL)
        return true;
    Queue queue;
    QueueInitiate(&queue);
    BiTreeNode *p = root;
    bool metNull = false;
    QueueAppend(&queue, p);
    while (QueueNotEmpty(queue)) {
        QueueDelete(&queue, &p);
        if (p == NULL) {
            // 如果遇到了空节点，设置标记并继续遍历，检查后面是否还有非空节点
            metNull = true;
            continue;
        }
        // 如果已经遇到了空节点，但当前节点不为空，则不是完全二叉树
        if (metNull) {
            return false;
        }
        QueueAppend(&queue, p->left);
        QueueAppend(&queue, p->right);
    }
    QueueDestroy(&queue);
    return true;
}

#ifndef MaxBit
#define MaxBit 10
#endif
#ifndef MaxValue
#define MaxValue 10000
#endif

typedef struct HaffNode {
    int weight;
    int flag;
    int parent;
    int left;
    int right;
} HaffNode;

typedef struct HaffCode {
    int bit[MaxBit];
    int start;
    int weight;
} HaffCode;

void HaffmanCreate(int weight[], int n, HaffNode HaffTree[]) {
    int i, j, m1, m2, x1, x2;
    for (i = 0; i < 2 * n - 1; i++) { // 初始化哈夫曼树，n个叶节点的二叉树共有2n-1个节点
        if (i < n)
            HaffTree[i].weight = weight[i];
        else
            HaffTree[i].weight = 0;
        HaffTree[i].parent = -1;
        HaffTree[i].flag = 0;
        HaffTree[i].left = -1;
        HaffTree[i].right = -1;
    }
    for (i = 0; i < n - 1; i++) {
        m1 = m2 = MaxValue;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++) { // 找出权值最小和次小的子树
            if (HaffTree[j].weight < m1 && HaffTree[j].flag == 0) {
                m2 = m1;
                x2 = x1;
                m1 = HaffTree[j].weight;
                x1 = j;
            } else if (HaffTree[j].weight < m2 && HaffTree[j].flag == 0) {
                m2 = HaffTree[j].weight;
                x2 = j;
            }
        }
        // 将找出的两棵权值最小的和次小的子树合并为一颗子树
        HaffTree[x1].parent = n + i;
        HaffTree[x2].parent = n + i;
        HaffTree[x1].flag = 1;
        HaffTree[x2].flag = 1;
        HaffTree[n + i].weight = HaffTree[x1].weight + HaffTree[x2].weight;
        HaffTree[n + i].left = x1;
        HaffTree[n + i].right = x2;
    }
}

int HaffmanCode(HaffNode haffTree[], int n, HaffCode haffCode[]) {
    HaffCode *cd = (HaffCode *) malloc(sizeof(HaffCode));
    if (cd == NULL)
        return 0;
    int i, j, child, parent;
    for (i = 0; i < n; i++) {
        cd->start = n - 1;
        cd->weight = haffTree[i].weight;
        child = i;
        parent = haffTree[child].parent;
        while (parent != -1) {
            if (haffTree[parent].left == child)
                cd->bit[cd->start] = 0;
            else
                cd->bit[cd->start] = 1;
            cd->start--;
            child = parent;
            parent = haffTree[child].parent;
        }
        for (j = cd->start + 1; j < n; j++)
            haffCode[i].bit[j] = cd->bit[j];
        haffCode[i].start = cd->start + 1;
        haffCode[i].weight = cd->weight;
    }
    return 1;
}

int BSTreeInsert(BiTreeNode **root, ElemType item) {
    int count=0;
    if (*root == NULL) {
        *root = (BiTreeNode *) malloc(sizeof(BiTreeNode));
        (*root)->data = item;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (item < (*root)->data)
            BSTreeInsert(&((*root)->left), item);
        else
            BSTreeInsert(&((*root)->right), item);
        count++;
    }
    count++;
    return count;
}

void BSTreeCreateByArray(BiTreeNode **root, ElemType data[], int length) {
    *root = NULL;
    for (int i = 0; i < length; i++) {
        BSTreeInsert(root, data[i]);
    }
}

struct count{
    int compare;
    int move;
};

count BSTreeDelete(BiTreeNode **root, ElemType item) {
    count count={0,0};
    BiTreeNode *p = *root, *parent = NULL;
    // 找到要删除的节点及其父节点
    while (p != NULL && p->data != item) {
        parent = p;
        if (item < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
        count.compare+=2;
    }
    if (p == NULL) {
        return count;
    }
    // 如果要删除的节点有两个子节点
    if (p->left != NULL && p->right != NULL) {
        BiTreeNode *successor = p, *successorParent = NULL;
        // 找到右子树的最小节点
        successor = p->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
            count.compare++;
            count.move++;
        }
        // 用右子树的最小节点替换要删除的节点
        p->data = successor->data;
        // 删除右子树的最小节点
        p = successor;
        parent = successorParent;
        count.move++;
    }
    // 要删除的节点只有一个子节点或没有子节点
    BiTreeNode *child;
    if (p->left != NULL) {
        child = p->left;
    }
    else {
        child = p->right;
    }
    // 更新父节点的指针
    if (parent == NULL) {
        *root = child;
    }
    else if (p == parent->left) {
        parent->left = child;
        count.compare++;
    }
    else {
        parent->right = child;
    }
    count.compare+=4;
    free(p);
    return count;
}
