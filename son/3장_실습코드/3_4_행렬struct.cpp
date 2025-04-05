// matrixMultiplication.cpp - 2차원 행렬을 struct으로 구현  - 자료구조 문제
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <windows.h>

// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩
struct Matrix {
	int rows;
	int cols;
	int* Term;
};

int getData(struct Matrix* a);
int showData(struct Matrix* a);// 행렬 모양: A[rows][cols] 출력
void add(struct Matrix*, struct Matrix*, struct Matrix*);
void transpose(struct Matrix*, struct Matrix*);
bool multiply(struct Matrix*, struct Matrix*, struct Matrix*);
void free(struct Matrix*);


//*/
int main()
{
	SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
	struct Matrix a = { 2,3,0 }, b = { 2,3,0 }, c = { 2,3,0 }, d = { 3,4,0 }, e = { 2,4,0 };
	srand(42);
	printf("matrix a[2][3]의 입력: \n");
	getData(&a);
	showData(&a);
	printf("matrix b[2][3]의 입력: \n");
	getData(&b);
	showData(&b);
	getData(&c);
	add(&a, &b, &c);
	showData(&c);
	printf("matrix d[3][4]의 입력: \n");
	getData(&d);
	showData(&d);
	//*
	getData(&e);
	multiply(&a, &d, &e);
	showData(&e);
	free(&a); free(&b); free(&c); free(&d); free(&e);
	//*/
	system("pause");
	return 0;
}
int getData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;
	a->Term = (int*)calloc(rows * cols, sizeof(int));

    for (int i=0; i< rows * cols; i++){
        a->Term[i] = rand()%10;
    }
	return 0;
}
int showData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a->Term[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
	return 1;
}
void add(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
	if (a->rows != b->rows || a->cols != b->cols) {
		printf("a, b는 incompatiable matrix\n");
		return;
	}
    int total = a->rows * a->cols;
    
	for(int i=0; i<total; i++){
        c->Term[i] = a->Term[i] + b->Term[i]; 
    }

}
//*

void transpose(struct Matrix* a, struct Matrix* a1) {
    // a1의 크기는 a의 전치행렬 크기, 즉 a1->rows = a->cols, a1->cols = a->rows 이어야 함
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a1->Term[j * a1->cols + i] = a->Term[i * a->cols + j];
        }
    }
}
bool multiply(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
    if (a->cols != b->rows) {
        printf("곱셈이 불가능한 행렬입니다.\n");
        return false;
    }
    // b의 전치행렬을 이용해 곱셈 수행 (효율적 캐시 활용)
    struct Matrix bXpose;
    bXpose.rows = b->cols;
    bXpose.cols = b->rows;
    bXpose.Term = NULL;
    getData(&bXpose);  // bXpose의 메모리 할당 (임시값은 이후 덮어씌워짐)
    transpose(b, &bXpose);

    // a (m x n)와 b (n x p)의 곱은 c (m x p)
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < bXpose.rows; j++) { // bXpose.rows == b->cols
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->Term[i * a->cols + k] * bXpose.Term[j * bXpose.cols + k];
            }
            c->Term[i * c->cols + j] = sum;
        }
    }
    free(bXpose.Term);
    return true;
}

void free(struct Matrix* m) {
    if (m->Term) {
        free(m->Term);
        m->Term = NULL;
    }
}
