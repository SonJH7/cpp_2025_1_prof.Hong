////2-4. pointer_array.cpp: �ǽ����� 2.4
///*
//lvalue Ư¡ 3����:
// 1) �޸� �ּҸ� ���´�
// 2) &�����ڸ� ������ �� �ִ�
// 3) assign ������ ���� ���� ����
//
// �迭�̸� : '������ �� ���� lvalue'
//*/
//#include <stdio.h>
//#include <stdlib.h>
//
//void testPointers(int a1[], int a2[][4]) {//C������ ������ �迭�� �Լ��� ������ �� ù ��° ������ �����ͷ� ��ȯ
//    //�Լ� ������ int *a1, int (*a2)[4]�� �ؼ��ϱ� ������ a2[][]���� ����
//    //�׷��� ���� ���� ��߸� �ϴ°���.
//    int* ap1 = a1;
//    //4���� ���� ������ �迭�� ����Ű�� array to pointer ����
//    int(*ap2)[4];
//    ap2 = a2;
//    //lvalue
//    //*ap2 = a2; // *ap2�� �迭 [5]�� ����Ű�� �迭 �̸� ����� ����, lvalue�� �ƴϴ�.
//    //*ap2 = *a2; // ���� �ǿ����ڴ� l-value�̾�� �մϴ�.
//    *ap2[0] = 100;//*ap2�� rvalue�̰� *ap2[0]�� lvalue�̴�
//
//    // int *ap3; ap3 = *a2;�� ���� �����̴�. ap3�� row 0�� �����ּҸ� ���´�.
//    int* ap3 = *a2; //ù row
//    int* p = (*a2 + 1); //���� column
//    //int *q[3] = a2; //q�� array�̹Ƿ� �ʱ�ȭ�ϱ� ���� {..}�� �ʿ��ϴ�.
//    int(*q)[4] = a2; //q�� pointer to array�̹Ƿ� �迭 ��� �̸����� �ʱ�ȭ ����
//    ap3++;
//    //1�� �ּ�
//    //*
//    printf("a2 = %p, ap3 = %p, p = %p\n", a2, ap3, p);
//    //pointer-to-array�� �̿��� ����
//    //�迭��� pointer-to-array�� access�ϴ� ���� ����.
//
//    printf("\n\n �迭��� pointer�� ����� ����:\n");
//    printf("a1[0] : %d\n", a1[0]);
//    // �迭�� �ּҸ� ������ �ִ� pointer�� ����� ���� ap1�� �迭 ���¿� ���� 
//    //   ����Ͽ� 0�� °�� �ش��ϴ� �迭 ������ ���� ������ �� �ִ�.
//    printf("ap1[0] : %d\n", ap1[0]);
//   
//    printf("*a1 : %d\n", *a1);//a1++�� ���ȴ�  
//    printf("*ap1 : %d\n", *ap1++); //ap1++�� ����> ++�� ���� �����ϰ� ������ * ������ �����Ѵ� 
//    printf("*ap1++ : %d\n", *ap1);
//    ap3++;
//
//    printf("\n Array a2[][]�� ���� ����\n");
//    printf("a2[0][0] : %d\n", a2[0][0]);
//    printf("ap2[0][0] : %d\n", ap2[0][0]);
//    printf("**a2 : %d\n", **a2);
//    printf("**ap2 : %d\n", **ap2);
//    printf("ap3[1] : %d\n", ap3[1]);
//    printf("*p : %d\n", *p);
//    printf("*(p+1) : %d\n", *(p + 1));
//    printf("*q : %p\n", *q);
//    printf("*q[0] : %d\n", *q[0]);
//
//    printf("\n\n2�� �ּ�\n\n");
//    printf("a1 = %p, ap1 = %p\n", a1, ap1);
//    printf("a2 = %p, ap2 = %p, ap3 = %p\n", a2, ap2, ap3);
//    printf("ap1++  ap2++  ap3++ ���� ��\n");
//    printf("*ap1 = %d\n", *ap1);
//    printf("**ap2 = %d\n", **ap2);
//    printf("*ap3 = %d\n", *ap3);
//    ap1++;
//    ap2++;//������ �󸶳� �����ϴ����� ���ذ� �ʿ� -> ���� ������ ��������
//    ap3++;
//    printf("\nap1++  ap2++  ap3++ ���� ��\n");
//    printf("a1 = %p, ap1 = %p\n", a1, ap1);
//    printf("a2 = %p, ap2 = %p, ap3 = %p\n", a2, ap2, ap3);
//    printf("*ap1 = %d\n", *ap1);
//    printf("**ap2 = %d\n", **ap2);
//    printf("*ap3 = %d\n", *ap3);
//}
//
//int main() {
//    int a1[4] = { 11,12,13,14 };
//    int a2[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//
//    testPointers(a1, a2);
//
//    system("pause");
//
//    return 0;
//}
