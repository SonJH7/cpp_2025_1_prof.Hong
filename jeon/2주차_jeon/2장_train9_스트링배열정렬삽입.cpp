/*
��Ʈ�� �迭 ���İ� insert ���� �ذ�
*/
#include <iostream>
#include <cstring> // strcmp, strcpy_s

using namespace std;

#define MAX_LEN 20
#define SIZE 8

void showData(const char* msg, char* arr[], int size);
void swapStrings(char*& a, char*& b);
void sortData(char* arr[], int size);
char** insertData(char* data[], int size, const char* value);
int main() {
    // �ʱ� ���ڿ� ������ ���� �Ҵ�
    char* data[] = {
        new char[MAX_LEN] {"avocado"},
        new char[MAX_LEN] {"grape"},
        new char[MAX_LEN] {"persimmon"},
        new char[MAX_LEN] {"pear"},
        new char[MAX_LEN] {"blueberry"},
        new char[MAX_LEN] {"strawberry"},
        new char[MAX_LEN] {"melon"},
        new char[MAX_LEN] {"jujube"}
    };

    showData("���� ��", data, SIZE);

    sortData(data, SIZE);

    showData("���� �� (��������)", data, SIZE);

    // ������ ������
    const char* realData[3] = { "waterMelon", "kiwi", "apple" };

    for (const char* newData : realData) {
        char** result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " ���� ��: ";
        showData("���� �� ���ĵ� �迭", result, SIZE + 1);

        // ���� �Ҵ�� �޸� ����
        for (int i = 0; i < SIZE + 1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    // ���� �迭�� �޸� ����
    for (int i = 0; i < SIZE; i++) {
        delete[] data[i];
    }
    system("pause");
    return 0;
}
