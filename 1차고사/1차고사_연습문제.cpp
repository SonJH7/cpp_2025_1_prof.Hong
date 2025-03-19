#include <stdio.h>
#include <stdlib.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

// 함수 선언
void getMatrix(int matrix[][ACOLS], int rows);
void getMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix_c(int matrix[][CCOLS], int rows);
void multiplyMatrix(int a[][ACOLS], int rows_a,
                    int b[][BCOLS], int rows_b,
                    int c[][CCOLS], int rows_c);

// 함수 정의
void getMatrix(int matrix[][ACOLS], int rows) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<ACOLS; j++){
            matrix[i][j] = rand() % 100; // 0~99
        }
    }
}

void getMatrix_b(int matrix[][BCOLS], int rows) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<BCOLS; j++){ // BCOLS 사용
            matrix[i][j] = rand() % 100;
        }
    }
}

void multiplyMatrix(int a[][ACOLS], int rows_a,
                    int b[][BCOLS], int rows_b,
                    int c[][CCOLS], int rows_c)
{
    // A: rows_a x ACOLS
    // B: rows_b x BCOLS
    // => C: rows_a x BCOLS
    // 여기서 ACOLS == rows_b == 4

    for(int i=0; i<rows_a; i++){
        for(int j=0; j<BCOLS; j++){
            c[i][j] = 0; // 누적 전 초기화
            for(int k=0; k<ACOLS; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void showMatrix_c(int matrix[][CCOLS], int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<CCOLS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int seed = 0;
    scanf("%d", &seed);  // 시드 입력
    srand(seed);         // 시드 설정

    int a[AROWS][ACOLS], b[BROWS][BCOLS], c[CROWS][CCOLS];

    getMatrix(a, AROWS);       // A에 난수 채우기
    getMatrix_b(b, BROWS);     // B에 난수 채우기

    multiplyMatrix(a, AROWS, b, BROWS, c, CROWS);
    showMatrix_c(c, CROWS);    // 결과 행렬 C 출력

    return 0;
}
