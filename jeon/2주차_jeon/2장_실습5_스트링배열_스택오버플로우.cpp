//��Ʈ�� �迭 ����: ���� �����÷ο� �ذ� 
#include <iostream>
#include <cstring>
using namespace std;

void sortStrings(char*[], int );
void swap(char*, char*);
int main() {
    const int SIZE = 5;
    char str1[] = "banana";
    char str2[] = "apple";
    char str3[] = "grape";
    char str4[] = "orange";
    char str5[] = "melon";

    // ������ �迭 ���
    char* words[SIZE] = { str1, str2, str3, str4, str5 };

    cout << "���� ��:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << words[i] << endl;
    }

    sortStrings(words, SIZE);

    cout << "\n���� ��:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << words[i] << endl;
    }
    system("pause");
    return 0;
    //Run-Time Check Failure #2 - Stack around the variable 'str5' was corrupted ������ �迭 ��踦 �Ѿ� �޸𸮸� �������� �� �߻�
    //�ذ� �����?
}
void swap(char* s, char *t) {
    char temp[10];
    strcpy(temp, s);
    strcpy(s, t);
    strcpy(t, temp);

}
// ���ڿ� ���� �Լ� (���� ���� ���)
void sortStrings(char* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}