#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* ��Ʈ�� �迭�� �Լ��� ������ �� ���������͸� ����ϴ� ���
*/
void showData(char* message, char* data[5], int n); //������ �迭 -> ���� �����Ͱ� ����� ���ڿ��̴ϱ� �׷��� �����͵��̶� �����ϸ� ���ڿ����̶� ��������
void swap(char* p[5], int i, int j);
char** bubbleSort(char* arr[5], int n);
void freeMemory(char** p, int n);
int main() {
	char* strings[5] = { "������", "����", "��", "�����", "����" };

	int n = sizeof(strings) / sizeof(strings[0]);

	showData("������", strings, n);

	char** result = bubbleSort(strings, n);
	showData("������", result, n);
	freeMemory(result, n);
	system("pause");
	return 0;
}



