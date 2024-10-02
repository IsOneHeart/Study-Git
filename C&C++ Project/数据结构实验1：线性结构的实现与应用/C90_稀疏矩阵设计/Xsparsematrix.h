typedef struct {
    int i;
    int j;
    float d;
} Datatype;

typedef struct {
    int md; // 行数
    int nd; // 列数
    int td; // 非零元素个数
    Datatype* data; // 数据数组
} TriType;

int SparseMatrixInitiate(TriType* M, int i, int j) {
    if (i < 1 || j < 1) {
        printf("参数i或j出错！\n");
        return 0;
    }
    M->md = i;
    M->nd = j;
    M->td = 0;
    M->data = NULL; // 初始时不分配非零元素数组  
    return 1;
}

int SparseMatrixElm(TriType* M, int i, int j, float d) {
    if (i > M->md || j > M->nd || i < 1 || j < 1 || d == 0) {
        // 不存储零元素  
        return 0;
    }
    // 动态调整数组大小  
    Datatype* new_data = (Datatype*)realloc(M->data, sizeof(Datatype) * (M->td + 1));
    if (new_data == NULL) {
        printf("内存重新分配失败！\n");
        return 0;
    }
    M->data = new_data;
    M->data[M->td].i = i;
    M->data[M->td].j = j;
    M->data[M->td].d = d;
    M->td++;
    return 1;
}

int SparseMatrixAdd(TriType A, TriType B, TriType* sum) {
    // 初始化结果矩阵  
    if (!SparseMatrixInitiate(sum, A.md, A.nd)) {
        return 0;
    }

    // 分配足够的空间以容纳A和B中的所有非零元素  
    sum->data = (Datatype*)malloc(sizeof(Datatype) * (A.td + B.td));
    if (sum->data == NULL) {
        printf("内存分配失败！\n");
        return 0;
    }
    int index = 0; // 用于记录sum中当前非零元素的位置  

    // 添加矩阵A中的非零元素到sum  
    for (int i = 0; i < A.td; i++) {
        sum->data[index++] = A.data[i];
    }

    // 遍历矩阵B中的非零元素，并添加到sum中或合并到已存在的元素中  
    for (int i = 0; i < B.td; i++) {
        Datatype currentB = B.data[i];
        int found = 0; // 标记是否找到对应的元素进行合并  

        // 查找是否有与B中当前元素相同位置的元素在sum中  
        for (int j = 0; j < index; j++) {
            if (sum->data[j].i == currentB.i && sum->data[j].j == currentB.j) {
                // 合并相同位置的元素  
                sum->data[j].d += currentB.d;
                found = 1;
                break;
            }
        }

        // 如果没有找到相同位置的元素，则添加到sum中  
        if (!found) {
            sum->data[index++] = currentB;
        }
    }

    // 调整sum中非零元素数组的大小  
    Datatype* resizedData = (Datatype*)realloc(sum->data, sizeof(Datatype) * index);
    if (resizedData == NULL) {
        printf("内存重新分配失败！\n");
        free(sum->data); // 释放原来的内存  
        return 0;
    }
    sum->data = resizedData;
    sum->td = index; // 更新非零元素的数量  

    return 1; // 成功返回1  
}

void SparseMatrixTransform(TriType A, TriType* D) {
    // 初始化转置后的稀疏矩阵D  
    SparseMatrixInitiate(D, A.nd, A.md);

    // 遍历A中的所有非零元素  
    for (int k = 0; k < A.td; k++) {
        int i = A.data[k].i; // 原矩阵的行
        int j = A.data[k].j; // 原矩阵的列
        float d = A.data[k].d; // 非零元素的值

        SparseMatrixElm(D, j, i, d);
    }
}

// 只打印非零元素
void SparseMatrixShow(TriType M) {
    for (int k = 0; k < M.td; k++) {
        printf("(%d, %d, %.2f)\n", M.data[k].i, M.data[k].j, M.data[k].d);
    }
}

// 打印整个矩阵
void SparseMatrixShowDense(TriType M) { 
  
    // 遍历矩阵的每一行  
    for (int i = 1; i <= M.md; i++) {  
        // 遍历矩阵的每一列  
        for (int j = 1; j <= M.nd; j++) {  
            float value = 0; // 默认值设为0  
            // 查找当前位置(i, j)是否在非零元素列表中  
            for (int k = 0; k < M.td; k++) {  
                if (M.data[k].i == i && M.data[k].j == j) {  
                    value = M.data[k].d; // 找到对应的非零值  
                    break;  
                }  
            }  
            // 按照格式打印元素值  
            printf("%.2f ", value);  
        }  
        printf("\n"); // 每打印完一行后换行  
    }  
}

void SparseMatrixFree(TriType* M) {
    if (M != NULL && M->data != NULL) {
        free(M->data);
        M->data = NULL;
    }
}