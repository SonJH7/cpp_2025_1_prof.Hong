////2-5. arr2.cpp: �ǽ� ���� 2.5
//#include <stdio.h>
//#include <stdlib.h>
////�迭 �̸��� ���Ͽ� pointer ǥ������ ����Ͽ� ����
//
//// 1���� �迭 ��� �Լ�
//void print1DArray(int* arr, int size) {
//    printf("\n1���� �迭\n");
//    printf("a1[0] = %d\n", arr[0]);
//    printf("*(arr) = %d\n\n", *(arr));
//
//    printf("a1[1] = %d\n", arr[1]); // ���� element
//    printf("*(arr+1) = %d\n\n", *(arr + 1)); // ���� element
//}
//
//// 2���� �迭 ��� �Լ�
//void print2DArray(int(*arr)[5], int rows, int cols) {
//    printf("\n2���� �迭\n");
//    printf("a2[0][0] = %d\n", arr[0][0]);
//    printf("(*arr)[0] = %d\n\n", (*arr)[0]);
//
//    printf("a2[1][3] = %d\n", arr[1][3]);
//    printf("(*(arr+1))[3] = %d\n\n", (*(arr + 1))[3]);
//
//    printf("a2[1][2] = %d\n", arr[1][2]);
//    printf("*(*(arr+1)+2) = %d\n\n", *(*(arr + 1) + 2));
//
//    printf("a2[0][0] = %d\n", arr[0][0]);
//    printf("**(arr+0) = %d\n\n", **(arr + 0));
//}
//
//int main() {
//    // 1���� �迭 ���� �� �ʱ�ȭ
//    int a1[5] = { 5, 4, 3, 2, 1 };
//    // 2���� �迭 ���� �� �ʱ�ȭ
//    int a2[3][5] = { {0, 5, 10, 15, 20}, {1, 6, 11, 16, 21}, {2, 7, 12, 17, 22} };
//
//    printf("�迭�� �Լ��� �����Ͽ� �׽�Ʈ\n");
//
//    // 1���� �迭 �Լ� ȣ��
//    print1DArray(a1, 5);
//
//    // 2���� �迭 �Լ� ȣ��
//    print2DArray(a2, 3, 5);
//
//    printf("\n������ �ּ��� ������ ���� ����\n");
//    printf("*(a1+1) = %d\n", *(a1 + 1));
//    printf("*(*(a2+1)+1) = %d\n", *(*(a2 + 1) + 1));
//    printf("\n");
//
//    system("pause");
//    return 0;
//}
