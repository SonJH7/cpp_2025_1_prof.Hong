////2-6. arr3.cpp - double pointer ���: �ǽ����� 2.6
///*
//*A�� ��� �ǽ�, *A +1 �� ��� ����Ű��?
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// 2���� �迭�� �Լ��� �����Ͽ� ����ϴ� �Լ�
//void print2DArray(int(*arr)[4], int rows, int cols) {
//	printf("\n------ 2���� �迭 -------\n");
//	printf("A: %p\n", arr); //�ε����� �� ���̰� �迭 �̸��� ���� �ּ� ���
//	printf("*A: %p\n", *arr); //��������
//	printf("*(A+1): %p\n", *(arr + 1)); //��������
//	printf("*(*A+0): %d\n", *(*arr + 0));
//	printf("*(*A+1): %d\n", *(*arr + 1));
//	printf("**(A+1): %d\n", **(arr + 1));
//	printf("**A: %d\n", **arr);
//}
//
//// ���� �����͸� Ȱ���� �׽�Ʈ �Լ�
//void testDoublePointer(int** ptr, int cols) {
//	printf("\n------ ���� pointer: test = &p -------\n");
//	printf("**ptr: %d\n", **ptr);
//	printf("*(*ptr + 0): %d\n", *(*ptr + 0));
//	printf("*(*ptr + 1): %d\n", *(*ptr + 1));
//	printf("*(*ptr + 2): %d\n", *(*ptr + 2));
//	printf("*(*ptr + 3): %d\n", *(*ptr + 3));
//	printf("*(*ptr + 4): %d\n", *(*ptr + 4)); //���� ������ �Ѿ����...
//	printf("*(*ptr + 5): %d\n", *(*ptr + 5));
//	printf("ptr[0][0]: %d\n", ptr[0][0]);
//	printf("ptr[0][4]: %d\n", ptr[0][4]);
//	//printf("ptr[0][4]: %d\n", ptr[1][4]); -> ����
//
//}
//
//int main() {
//	int A[3][4] = { {11,12,13,14}, {21,22,23,24}, {31,32,33,34} };
//	int* p = *A; // *A�� ù ��° ���� ������
//	//int *p = A; // error 'int (*)[4]'���� 'int *'�� �ʱ�ȭ��  �� ����.
//	//int* p = *A; // *A= int[4], A= int[3][4], p= int *
//	// 2���� �迭�� �Լ��� �����Ͽ� ���
//	print2DArray(A, 3, 4);
//
//	// ���� ������ Ȱ�� �׽�Ʈ
//	int** test;
//	test = &p; // p�� ���� �����ͷ� �ʱ�ȭ -> �ϳ��� �࿡ A�� �� ���� ��ó�� ��
//	//*test = *A;//variable 'test'�� �ʱ�ȭ���� ����� �� ����
//	testDoublePointer(test, 4);
//
//
//	//�ּ�3
//	printf("\n------ ���� pointer: p2 = &pt  -------\n");
//	int* pt;
//	int ar2[3][2] = { {1,3},{5,7},{9,11} };// int (*)[2]
//	int** p2;  // a pointer to a pointer   
//	//pt = &ar2[0][0];
//	pt = ar2[0]; // both pointer-to-int
//	//pt = ar2; // int (*)[3] ������ ���� int * ������ ������ ġȯ�� �� ����
//	p2 = &pt;         // both pointer-to-int *
//	//*p2 = ar2[0];     // both pointer-to-int *
//	printf("*pt = %d, **p2 = %d\n\n", *pt, **p2);
//	(*p2)++;
//	printf("*pt = %d, **p2 = %d\n\n", *pt, **p2); //p2�� ������ pt���� �ݿ���... ����� ����,,,? �ּҸ� �ذŴϱ�,, ��ũ��� �����ϸ� �ɵ�
//	//p2 = ar2; // int (*)[2] ������ ���� int ** ������ ������ ġȯ�� �� ����
//	//*/
//	/*
//	int **p2 = (int **)malloc(3 * sizeof(int *)); // ��(3��) �Ҵ�
//
//    for (int i = 0; i < 3; i++) {
//        p2[i] = (int *)malloc(2 * sizeof(int));  // �� �࿡ ��(2��) �Ҵ�
//		//p2�� arrays of pointers > p2[0],p2[1],...
//		//*d[]�� ȣȯ�ȴ� 
//    }
//	*/
//	system("pause");
//	return 0;
//}
