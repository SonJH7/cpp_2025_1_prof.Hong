
#include <iostream>
using namespace std;

// 함수 선언
void readOnly(const int* ptr);        // 포인터가 가리키는 값은 상수
void writeOnly(int* const ptr);       // 포인터 자체는 상수
void readWriteNoneConst(int* ptr);    // 둘 다 상수 아님
void fullyConst(const int* const ptr);// 포인터도 상수, 값도 상수

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    const int* p1 = &a;     // 가리키는 값이 상수 (read-only)
    int* const p2 = &b;     // 포인터 자체가 상수 (주소 고정)
    const int* const p3 = &c; // 둘 다 상수

    cout << "== 함수 호출 ==" << endl;

    readOnly(p1);           // OK
    // writeOnly(p1);       // ❌ 컴파일 오류 (const int* → int* const)
    // fullyConst(p1);      // OK (const int* → const int* const)

    // readOnly(p2);        // OK (int* → const int*)
    writeOnly(p2);          // OK
    // fullyConst(p2);      // ❌ (int* const → const int* const)

    // readOnly(p3);        // OK
    // writeOnly(p3);       // ❌
    // fullyConst(p3);      // OK

    int x = 100;
    readWriteNoneConst(&x); // OK


    return 0;
}

// 가리키는 값은 읽기만 가능
void readOnly(const int* ptr) {
    cout << "readOnly: " << *ptr << endl;
    // *ptr = 999; // ❌ 수정 불가
}

// 포인터는 고정되어 있으나 가리키는 값은 수정 가능
void writeOnly(int* const ptr) {
    *ptr = *ptr + 1; // ✅ 값 수정 가능
    cout << "writeOnly (after increment): " << *ptr << endl;
    // ptr = nullptr; // ❌ 포인터 주소 수정 불가
}

// 포인터도 수정 가능, 값도 수정 가능
void readWriteNoneConst(int* ptr) {
    *ptr = *ptr + 5;
    cout << "readWriteNoneConst: " << *ptr << endl;
}

// 포인터도 상수, 가리키는 값도 상수
void fullyConst(const int* const ptr) {
    cout << "fullyConst: " << *ptr << endl;
    // *ptr = 123; // ❌
    // ptr = nullptr; // ❌
}



/*===================================*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
    char* name;
    int age;
    char* city;
    Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent() const;
    ~Student(); // Destructor 추가
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};
void Student::updateStudentCity(const char* city) {
    //this->city = city;//const char *을 char*로 치환 못한다 이유는? 이해가 필요 
    //strcpy(this->city, city);
    this->city = strdup(city);
}
int Student::compareStudents(const Student* b) {
    return strcmp(this->name, b->name);

}
void Student::showStudent() const{
    printf("[%s, %d, %s]\n", name, age, city);
}
// Constructor 구현
Student::Student(const char* name, int age, const char* city) {
    /*
    this->name = name;//const를 사용하는 이유를 이해하는 것이 필요 
    this->age = age;
    this->city = city;//const를 사용하는 이유를 이해하는 것이 필요 
   */
    //*
    this->name = strdup(name);
    this->age = age;
    this->city = strdup(city);
    //*/
}

// Destructor 구현

Student::~Student() {
    if (name != nullptr) {
        free(name);
    }
    if (city != nullptr) {
        free(city);
    }
}
void Student::swap(Student* b) {
    std::swap(name, b->name);
    std::swap(age, b->age);
    std::swap(city, b->city);
}

void showStudents(string message, const Student* students[], int numStudents) {
    //void showStudent();를 사용한 객체 출력
    cout << message << ": " << endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i] == NULL)
            break;
        students[i]->showStudent();//const Student를 사용해야 한다.
    }
    cout << endl;
}

void selectionSortStudents(Student* students[], int numStudents) {
    // int compareStudents(const Student* b);를 사용한 정렬
    for (int i = 0; i < numStudents - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numStudents; ++j) {
            if (students[j]->compareStudents(students[minIndex]) < 0) {
                minIndex = j;

            }
        }
        if (minIndex != i) {
            students[i]->swap(students[minIndex]);
        }
    }
}
int main() {
    // 학생 객체 초기화
    int numStudents = 5;
    Student student1("Hong Gildong", 23, "houston");
    Student student2("hello", 22, "newyork");
    Student student3("houston", 13, "houston");
    Student student4("hong", 19, "busan");
    Student student5("kim", 33, "jeju");
    Student* students[5] = { &student1,&student2,&student3,&student4 ,&student5 };
    // 각 학생 정보 출력
    showStudents("Before Sort:", students, numStudents);
    student1.updateStudentCity("Busan");
    student1.showStudent();
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);
    system("pause");
    return 0;
}