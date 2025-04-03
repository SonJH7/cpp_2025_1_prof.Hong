/*
2���� �迭�� �Լ��� �����Ͽ� �Լ����� ����Ͽ� �����ϴ� ���
int (*data)[]�� �����Ͽ� �Լ��� ����� �����ϴ� ���� - static int[][]�� ����Ͽ� ����
�޸� ���� ��� ���ϰ� ���� �ذ� �����ұ�?
=> �ߺ� �ڵ� �߻�: ������ �ڵ� ������ �ʿ�
*/
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
#define EROWS 3
#define ECOLS 4

void getMatrix(int matrix[][ACOLS], int rows);
void getMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix(int matrix[][ACOLS], int rows);
void showMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix_c(int matrix[][CCOLS], int rows);
int(*addMatrix(int a1[][ACOLS], int rows1, int a2[][ACOLS], int rows2))[ACOLS];

int(*multiplyMatrix(int a[][ACOLS], int rows_a, int b[][BCOLS], int rows_b))[CCOLS];
int(*transposeMatrix(int b[][BCOLS], int rows_b))[ECOLS];
int(*multiplyTransposeMatrix(int a[][ACOLS], int rows_a, int(*e)[ECOLS], int rows_e))[CCOLS];

int main() {
    srand(42);//seed ���� �־����� ���� ���� ����� �׻� ���� �������

    int a[AROWS][ACOLS], a2[AROWS][ACOLS], b[BROWS][BCOLS], c[CROWS][CCOLS], d[DROWS][DCOLS], e[DROWS][DCOLS];

    getMatrix(a, AROWS);
    getMatrix(a2, AROWS);

    printf("Matrix A1:\n");
    showMatrix(a, AROWS);

    printf("Matrix A1:\n");
    showMatrix(a2, AROWS);

    int(*result)[ACOLS] = addMatrix(a, AROWS, a2, AROWS);
    printf("Matrix E = A + A2:\n");

    printf("Matrix Result:\n");
    showMatrix(result, AROWS);

    int(*result2)[ACOLS] = addMatrix(result, AROWS, a2, AROWS);
    printf("Matrix Result2:\n");
    showMatrix(result2, AROWS);

    //����
    getMatrix_b(b, BROWS);
    printf("Matrix B:\n");
    showMatrix_b(b, BROWS);
    int(*result2)[CCOLS] = multiplyMatrix(a, AROWS, b, BROWS);
    printf("Matrix C = (A * B):\n");
    showMatrix_c(result2, CROWS);

    int(*transResult)[BROWS] = transposeMatrix(b, BROWS);
    printf("Transpose Matrix E = transpose(B)\n");
    showMatrix_c(transResult, EROWS);

    int(*product)[CCOLS] = multiplyTransposeMatrix(a, AROWS, transResult, EROWS);
    printf("Matrix product = (A * transpose(B)):\n");
    showMatrix_c(product, CROWS);

    system("pause");
    return 0;
}


//�Լ� ��ȯ���� ���� ��� ���� �ڷ��� ���������� �߿�
int(*addMatrix(int a1[][ACOLS], int rows1, int a2[][ACOLS], int rows2))[ACOLS] {
    static int result[AROWS][ACOLS];
    int(*result)[ACOLS];
    for()
        for () {
           result[i][j] = a1[i][j] + a2[i][j]
        }

    return result;
    }