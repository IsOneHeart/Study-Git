typedef struct {
    int i;
    int j;
    float d;
} Datatype;

typedef struct {
    int md; // ����
    int nd; // ����
    int td; // ����Ԫ�ظ���
    Datatype* data; // ��������
} TriType;

int SparseMatrixInitiate(TriType* M, int i, int j) {
    if (i < 1 || j < 1) {
        printf("����i��j����\n");
        return 0;
    }
    M->md = i;
    M->nd = j;
    M->td = 0;
    M->data = NULL; // ��ʼʱ���������Ԫ������  
    return 1;
}

int SparseMatrixElm(TriType* M, int i, int j, float d) {
    if (i > M->md || j > M->nd || i < 1 || j < 1 || d == 0) {
        // ���洢��Ԫ��  
        return 0;
    }
    // ��̬���������С  
    Datatype* new_data = (Datatype*)realloc(M->data, sizeof(Datatype) * (M->td + 1));
    if (new_data == NULL) {
        printf("�ڴ����·���ʧ�ܣ�\n");
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
    // ��ʼ���������  
    if (!SparseMatrixInitiate(sum, A.md, A.nd)) {
        return 0;
    }

    // �����㹻�Ŀռ�������A��B�е����з���Ԫ��  
    sum->data = (Datatype*)malloc(sizeof(Datatype) * (A.td + B.td));
    if (sum->data == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 0;
    }
    int index = 0; // ���ڼ�¼sum�е�ǰ����Ԫ�ص�λ��  

    // ��Ӿ���A�еķ���Ԫ�ص�sum  
    for (int i = 0; i < A.td; i++) {
        sum->data[index++] = A.data[i];
    }

    // ��������B�еķ���Ԫ�أ�����ӵ�sum�л�ϲ����Ѵ��ڵ�Ԫ����  
    for (int i = 0; i < B.td; i++) {
        Datatype currentB = B.data[i];
        int found = 0; // ����Ƿ��ҵ���Ӧ��Ԫ�ؽ��кϲ�  

        // �����Ƿ�����B�е�ǰԪ����ͬλ�õ�Ԫ����sum��  
        for (int j = 0; j < index; j++) {
            if (sum->data[j].i == currentB.i && sum->data[j].j == currentB.j) {
                // �ϲ���ͬλ�õ�Ԫ��  
                sum->data[j].d += currentB.d;
                found = 1;
                break;
            }
        }

        // ���û���ҵ���ͬλ�õ�Ԫ�أ�����ӵ�sum��  
        if (!found) {
            sum->data[index++] = currentB;
        }
    }

    // ����sum�з���Ԫ������Ĵ�С  
    Datatype* resizedData = (Datatype*)realloc(sum->data, sizeof(Datatype) * index);
    if (resizedData == NULL) {
        printf("�ڴ����·���ʧ�ܣ�\n");
        free(sum->data); // �ͷ�ԭ�����ڴ�  
        return 0;
    }
    sum->data = resizedData;
    sum->td = index; // ���·���Ԫ�ص�����  

    return 1; // �ɹ�����1  
}

void SparseMatrixTransform(TriType A, TriType* D) {
    // ��ʼ��ת�ú��ϡ�����D  
    SparseMatrixInitiate(D, A.nd, A.md);

    // ����A�е����з���Ԫ��  
    for (int k = 0; k < A.td; k++) {
        int i = A.data[k].i; // ԭ�������
        int j = A.data[k].j; // ԭ�������
        float d = A.data[k].d; // ����Ԫ�ص�ֵ

        SparseMatrixElm(D, j, i, d);
    }
}

// ֻ��ӡ����Ԫ��
void SparseMatrixShow(TriType M) {
    for (int k = 0; k < M.td; k++) {
        printf("(%d, %d, %.2f)\n", M.data[k].i, M.data[k].j, M.data[k].d);
    }
}

// ��ӡ��������
void SparseMatrixShowDense(TriType M) { 
  
    // ���������ÿһ��  
    for (int i = 1; i <= M.md; i++) {  
        // ���������ÿһ��  
        for (int j = 1; j <= M.nd; j++) {  
            float value = 0; // Ĭ��ֵ��Ϊ0  
            // ���ҵ�ǰλ��(i, j)�Ƿ��ڷ���Ԫ���б���  
            for (int k = 0; k < M.td; k++) {  
                if (M.data[k].i == i && M.data[k].j == j) {  
                    value = M.data[k].d; // �ҵ���Ӧ�ķ���ֵ  
                    break;  
                }  
            }  
            // ���ո�ʽ��ӡԪ��ֵ  
            printf("%.2f ", value);  
        }  
        printf("\n"); // ÿ��ӡ��һ�к���  
    }  
}

void SparseMatrixFree(TriType* M) {
    if (M != NULL && M->data != NULL) {
        free(M->data);
        M->data = NULL;
    }
}