
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 4


//���� �� ������ �ڵ�

//static ,,,,

void getmatrix(int[][ACOLS], int rows, int cols);

void getmatrix_b(int[][BCOLS], int rows, int cols);
//��ư �̷� �ߺ��ڵ��� ��������

void getmatrix(int* data, int rows, int cols) {

}

int* addMatrix(int* a,int* b,)


int** addM(int a[][ACOLS], int rowa_a, int d[][DCOLS], int rows_d);
int main() {
    srand(time(NULL));

    int a[AROWS][ACOLS], b[BROWS][BCOLS], d[DROWS][DCOLS];

    getMatrix(a, AROWS, ACOLS);
    //getMatrix2() �ߺ� �ڵ��� �ʿ� > ������ �ڵ� �ȵ�
    getMatrix(b, BROWS, BCOLS);
    getMatrix(d, DROWS, DCOLS);

    printf("Matrix A:\n");
    showMatrix((int**)a, AROWS, ACOLS);
    printf("Matrix B:\n");
    showMatrix((int**)b, BROWS, BCOLS);
    printf("Matrix D:\n");
    showMatrix((int**)d, DROWS, DCOLS);

    // Cascading Addition Example
    int** temp = addMatrix(a, AROWS, d, DROWS); // temp = A + D
    //addMatrix2() �ߺ� �ڵ��� �ʿ� > ������ �ڵ� �ȵ�
    int** e = addMatrix(temp, AROWS, a, DROWS); // E = (A + D) + A

    printf("Matrix E = ((A + D) + A):\n");
    showMatrix(e, DROWS, DCOLS);

    int(*result2)[CCOLS] = multiplyMatrix(a, AROWS, b, BROWS);
    printf("Matrix C = (A * B):\n");
    showMatrix_c(result2, CROWS);

    int** transResult = transposeMatrix(b, BROWS);
    printf("Transpose Matrix E = transpose(B)\n");
    showMatrix_c(transResult, EROWS);

    int** product = multiplyTransposeMatrix(a, AROWS, transResult, EROWS);
    printf("Matrix product = (A * transpose(B)):\n");
    showMatrix_c(product, CROWS);

    // �޸� ���� -> �ʼ�����... 
    //for ���� �����鼭 ���� ����
    freeMatrix(temp, DROWS);
    freeMatrix(e, DROWS);
    freeMatrix(transResult, BROWS);
    freeMatrix(product, AROWS);
    return 0;
}



int** addM(int a[][ACOLS], int rowa_a, int d[][DCOLS], int rows_d) {
    int** result = (int**)malloc(rows_a*sizeof(int*));

    for (int i = 0; i < rows_a; i++) {
        result[i] = (int*)malloc(ACOLS * sizeof(int*));
    }

    for () {
        for () {
            result[i][j] = a[i][j] + d[i][j];
        }
    }

    return result;

}