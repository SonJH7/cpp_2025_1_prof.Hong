////2-7. arr4.cpp
////array of pointers�� �ʱ�ȭ ���
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// ������ �迭�� �ʱ�ȭ�ϴ� �Լ�
//void initializePointerArray(int* b, int** q, int qSize) {
//    q[0] = b; // b�� ���� �ּ�
//    q[1] = b + 2;
//    q[2] = b + 4;
//    q[3] = b + 6;
//    q[4] = b + 8;
//
//    // Ư�� ��ġ�� �� ����
//    q[3][2] = 55; // b[8]�� 55�� ����
//}
//
//// ������ �迭�� ����ϴ� �Լ�
//void printPointerArray(int** q, int qSize) {
//    printf("------ ������ �迭 ��� ------\n");
//    printf("q[0]: %p, q[1]: %p, q[2]: %p, q[3]: %p, q[4]: %p\n",
//        q[0], q[1], q[2], q[3], q[4]);
//
//    printf("*q[0]: %d\n", *q[0]);
//    printf("*q[1]: %d\n", *q[1]);
//    printf("*q[2]: %d\n", *q[2]);
//    printf("*q[3]: %d\n", *q[3]);
//    printf("*q[4]: %d\n", *q[4]);
//    printf("q[3][2]: %d, q[4][0]: %d\n", q[3][2], q[4][0]); //q[3][2] == q[4][0]�ΰ� �ű�
//}
//
//int main() {
//    int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int* q[5]; // ������ �迭 ����
//
//    // ������ �迭 �ʱ�ȭ
//    initializePointerArray(b, q, 5);
//
//    // ������ �迭 ���
//    printPointerArray(q, 5);
//
//    // b �迭 ��ü ���
//    printf("\n------ b �迭 ��� ------\n");
//    for (int i = 0; i < 10; i++) {
//        printf(" %d", b[i]);
//    }
//    printf("\n");
//
//    system("pause");
//    return 0;
//}
