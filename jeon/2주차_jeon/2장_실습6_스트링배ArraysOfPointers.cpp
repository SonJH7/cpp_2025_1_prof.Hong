#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define ROWS 5

/*
char  *strings[10] = { "apple", "banana", "orange", "grape", "kiwi" }; 
strcpy(strings[0],strings[1]); ������ ����? ������? ������ > ��Ʈ�� ���ͷ��� �����Ͱ� ����Ų��
char  (*strings)[10] = { "apple", "banana", "orange", "grape", "kiwi" };>> �����Ͱ� �迭�� ����Ų�� 
*/
void bubbleSort(char* arr[ROWS], int n);
void showData(char* message, char* data[ROWS], int n);
int main() {
    //��Ʈ�� �迭 �ʱ�ȭ ��� 2���� ����
    //char strings[ROWS][SIZE] = { "apple", "banana", "orange", "grape", "kiwi" };//�ǽ�5���� ����
    char  *strings[ROWS] = { "apple", "banana", "orange", "grape", "kiwi" };//�����Ͱ� ��Ʈ���� ����ų �� ������ ��

    int n = sizeof(strings) / sizeof(strings[0]);
    printf("\nn=%d", n);//n = 5�� ���Ǵ� ������ �˾ƾ� �Ѵ�

    showData("������", strings, ROWS);

    bubbleSort(strings, ROWS);
    showData("����gn", strings, ROWS);

    system("pause");
    return 0;
}
void bubbleSort(char* arr[ROWS], int n) { //char **arr�� ����. 
    // char arr[][10] ǥ���� char (*arr)[SIZE]�� ����
    char temp[10];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);//access ���� ���� �߻�
            }
        }
    }
}
void showData(char* message, char* data[ROWS], int n) {
    printf("%s\n", message);
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(data + i));
    }
}