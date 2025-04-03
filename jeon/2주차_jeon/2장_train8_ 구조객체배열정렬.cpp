#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student ����ü ����
struct Student {
    char* name;
    int age;
    char* city;
};
void swap(struct Student* a, struct Student* b);
void interchangeSort(struct Student** arr, int n);
void showStudents(char* message, struct Student** arr, int n);
int main() {
    struct Student student1 = { "ȫ�浿", 20, "����" };
    struct Student student2 = { "��ö��", 22, "�λ�" };
    struct Student student3 = { "��浿", 19, "����" };
    struct Student student4 = { "�浿", 39, "����" };
    struct Student student5 = { "ȫ���", 49, "����" };
    struct Student student6 = { "�̱浿", 59, "�뱸" };
    struct Student student7 = { "��浿", 9, "��õ" };

    struct Student* students[10] = { &student1, &student2, &student3, &student4,&student5,&student6,&student7 };
    // ������ ��ҵ��� �����ͷ� �ʱ�ȭ�Ͻÿ�


    // �迭�� ũ�� ���
    int numStudents = sizeof(students) / sizeof(students[0]);
    showStudents("������ �迭", students, numStudents);
    // ���� �� ���

    // interchangeSort �Լ��� ����Ͽ� ����ü ��ü �迭 ����
    interchangeSort(students, numStudents);

    // ���� �� ���
    showStudents("������ �迭", students, numStudents);

    system("pause");

    return 0;
}
// �� Student ��ü�� ��ȯ�ϴ� �Լ�
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// ����ü ��ü �迭�� �̸�(name)�� �������� �������� �����ϴ� �Լ�
