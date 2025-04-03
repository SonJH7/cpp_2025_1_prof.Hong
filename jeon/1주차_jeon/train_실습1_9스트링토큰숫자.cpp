/*
������ �������� ���ڿ��� �и� : strtok()�� ����Ͽ� ����(" ")�� �������� ���ڿ��� �и�
���ڿ� �迭 ���� : C++�� qsort()�� ����Ͽ� ������ ����
���ڿ��� ������ ��ȯ: atoi()�� ����Ͽ� ���ڿ��� ������ ��ȯ
���� �迭 ���� : qsort()�� ����Ͽ� ���� �迭�� �������� ����
*/
#include <iostream>
#include <cstring>  // strtok, strcmp, atoi, qsort
#include <cstdlib>  // atoi

using namespace std;

// ���ڿ� �� �Լ� (qsort��)
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// ���� �� �Լ� (qsort��)
int compareIntegers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// ���ڿ��� ����(" ")���� �и��Ͽ� �迭�� �����ϰ� �����ϴ� �Լ�
int splitSortString(char* input, char* stringArray[], int maxTokens) {
    int count = 0;
    //���������� ���� �Ǵ� ����(static) ���¸� �����ϴ� ������� �����մϴ�.
    //strtok()�� ȣ���� ������ ���� ȣ�⿡�� ���ҵ� ��ġ�� ����ϰ�, 
    //���� ȣ�⿡�� ���� ��ū�� ��ȯ�մϴ�.
    char* token = strtok(input, " ");  // ������ �������� ���ڿ� �и�

    while (token != nullptr && count < maxTokens) {
        stringArray[count++] = token;  // �и��� ���ڿ� ����
        token = strtok(nullptr, " ");  // ���� ��ū
    }

    // ���ڿ� �迭 ���� (������ ����)
    qsort(stringArray, count, sizeof(char*), compareStrings);

    return count;  // �и��� ���ڿ� ���� ��ȯ
}

// ���ڿ� �迭�� ���� �迭�� ��ȯ�ϰ� �����ϴ� �Լ�
void convertSortToIntArray(char* stringArray[], int intArray[], int size) {
    // ���ڿ� �迭�� ���� �迭�� ��ȯ
    //atoi() ���

    // ���� �迭 ���� (��������)

}



int main() {
    char input[] = "12 111 911 921 94 23 214 222";  // ���� ���ڿ�
    char* sortedStringArray[20];  // �и��� ���ڿ� ���� �迭 (�ִ� 20������ ���� ����)
    int sortedIntArray[20];  // ���� �迭

    // ���ڿ��� �������� �и��ϰ� ����
    int size = splitSortString(input, sortedStringArray, 20);

    // ���ĵ� ���ڿ� �迭 ���
    cout << "Sorted String Array:" << endl;
    printStringArray(sortedStringArray, size);

    // ���ڿ� �迭�� ���� �迭�� ��ȯ �� ����
    convertSortToIntArray(sortedStringArray, sortedIntArray, size);

    // ���ĵ� ���� �迭 ���
    cout << "Sorted Integer Array:" << endl;
    printIntArray(sortedIntArray, size);
    system("pause");
    return 0;
}
