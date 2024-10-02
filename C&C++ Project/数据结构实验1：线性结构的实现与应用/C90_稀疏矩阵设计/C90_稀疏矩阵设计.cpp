#include <stdio.h>
#include <stdlib.h>
#include "Xsparsematrix.h"

int main() {
    TriType A, B, C, D;
    SparseMatrixInitiate(&A, 3, 3);
    SparseMatrixInitiate(&B, 3, 3);

    SparseMatrixElm(&A, 1, 1, 1);
    SparseMatrixElm(&A, 3, 2, 2);
    SparseMatrixElm(&A, 2, 1, 2);

    SparseMatrixElm(&B, 2, 1, 2);
    SparseMatrixElm(&B, 3, 1, 3);

    printf("矩阵A：\n");
    SparseMatrixShowDense(A);
    printf("\n矩阵B：\n");
    SparseMatrixShowDense(B);

    if (!SparseMatrixAdd(A, B, &C)) {
        printf("A、B无法相加！\n");
        return 1;
    }

    printf("\n矩阵C(A+B)：\n");
    SparseMatrixShowDense(C);

    SparseMatrixTransform(A, &D);

    printf("\n矩阵D(矩阵A的转置矩阵)：\n");
    SparseMatrixShowDense(D);

    SparseMatrixFree(&A);
    SparseMatrixFree(&B);
    SparseMatrixFree(&C);
    SparseMatrixFree(&D);

    return 0;
}