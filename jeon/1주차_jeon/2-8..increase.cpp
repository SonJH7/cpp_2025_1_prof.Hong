////2-8. increase.cpp
//// 1���� �迭, 2���� �迭�� ���� ������Ű�� �Լ� ȣ�� -skip
//#include <stdio.h>
//#include <stdlib.h>
//#define ROW 3
//#define COL 5
//void increase(int (*a)[COL], int size);
//void increaseArrayPtr(int* [], int);
//
//void main(void)
//{
//	int a2[ROW][COL] = { {1,2,3,4,5}, {11,12,13,14,15}, {21,22,23,24,25} };
//
//	increase(a2, ROW);// int (*)[] ������ parameter�� int []�� ȣȯ���� �ʴ´�
//
//	printf("\n");
//	int a[2][3] = { 1,2,3,4,5,6 };
//	int* b[2] = { a[0], a[1] };
//	increaseArrayPtr(b, 2);
//	printf("\n");
//	//*/
//	system("pause");
//}
//void increaseArrayPtr(int *x[], int n) //array of pointer�� ����� parameter passing 
////int (*x)[]�� �����߻� 
//{
//	printf("\narray of pointer�� ����� ���\n");
//	for (int i = 0; i < n; i++)
//	{
//		//printf(" %d", *(x[i] + 1));
//		for (int j = 0; j < 3; j++)
//			printf(" %d", *(x[i] + j));
//		printf("\n");
//	}
//
//}
//void increase(int (*a)[COL], int size) {
//	printf("\npointer to array�� ����� ���\n");
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < COL; j++)
//			printf(" %d", *(a[i] + j));
//		printf("\n");
//	}
//}
