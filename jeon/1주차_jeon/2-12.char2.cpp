////2-12. char2.cpp: �ǽ����� 2.12
///*
//char p[10], char *q, char *r[10]�� ������
//�޸� �Ҵ� ��İ� ���� ����� �ٸ���
//*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//
//void strProcess(char* p[], char* q[], char r[], char s[]) {
//    printf("*p = %s, *q = %s\n", *p, *q);
//    printf("r = %s\n", r);
//
//    strcpy(s, r);
//
//    printf("\n\n*p[]->s[] ���ڿ� ������\n");
//    strcpy(s, *p);
//    printf("s = %s, *p = %s\n", s, *p);
//    printf("strcmp(s, *p) = %d (0->����, 0�ƴѼ���->�ٸ���)\n", strcmp(s, *p));
//}
//
//int main(void) {
//    const char* i = "monday";//������ �������� .rodata (read only ������ ����) �ּҸ� ������ i�� ����Ų��
//    const char* j;
//    char* p[10];
//    char* q[10];
//    char r[10] = "sunday";//����(Stack) ������ r�̶�� �迭�� �����ϰ�, ���ڿ� "sunday"�� ������ ����(Stack) ������ ����
//    char s[10];
//    //*i = "good";
//    j = i;
//    //s = r;//s�� lvalue�� �ƴϴ� �迭 �̸����� ����̴�.
//    //strcpy(i, "saturday");//runtime ���� �߻�, *i�� ��� �� "monday"�� ����, ���� �Ұ�
//    strcpy(r, "friday");
//    *p = "wednesday";//p�� array of pointer => p[0]�� �������̰� wednesday�� ����Ų�� 
//    *q = "thursday";
//
//    strProcess(p, q, r, s);
//
//    system("pause");
//    return 0;
//}
