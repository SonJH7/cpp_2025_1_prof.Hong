#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> 

using namespace std;
//Rectangle 이름은 Window.h에서 사용하므로 복수 클래스 이름 사용
class Rectangles { //맛보기 예제
private:
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
public:
    //생성자
    Rectangles(int x, int y, int w, int h) :
        leftBottomX(x), leftBottomY(y), width(w), height(h) {}
    void showRectangles();
    int compareRectangless(const Rectangles* b);
    void swap(Rectangles* b);
};

void Rectangles::showRectangles() {
    printf("[%d, %d, %d, %d]\n", leftBottomX, leftBottomY, width, height);
}

int Rectangles::compareRectangless(const Rectangles* b) {
    int LBXCompare = leftBottomX - b->leftBottomX;
    int LBYCompare = leftBottomY - b->leftBottomY;
    int widthCompare = width - b->width;
    int heightCompare = height - b->height;
    if (LBXCompare != 0)
        return LBXCompare;
    else if (LBYCompare != 0)
        return LBYCompare;
    else if (widthCompare != 0)
        return widthCompare;
    return heightCompare;
}
void Rectangles::swap(Rectangles* b) {
    std::swap(leftBottomX, b->leftBottomX);
    std::swap(leftBottomY, b->leftBottomY);
    std::swap(width, b->width);
    std::swap(height, b->height);
}
void showRectangless(string message, Rectangles* rectangles[], int numRectangless) {
    cout << message << ": " << endl;
    for (int i = 0; i < numRectangless; ++i) {
        rectangles[i]->showRectangles();
    }
    cout << endl;
}
void selectionSortRectangless(Rectangles* rectangles[], int numRectangless) {
    // int compareRectangless(const Rectangles* b);를 사용한 정렬
    for (int i = 0; i < numRectangless - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numRectangless; ++j) {
            if (rectangles[j]->compareRectangless(rectangles[minIndex]) < 0) {
                minIndex = j;

            }
        }
        if (minIndex != i) {
            rectangles[i]->swap(rectangles[minIndex]);
        }
    }
}
int main(void) {
    const int numRectangless = 5;
    Rectangles* rectangles[numRectangless] = {
        new Rectangles(3, 5, 10, 15),
        new Rectangles(3, 5, 10, 12),
        new Rectangles(3, 5, 6, 10),
        new Rectangles(3, 6, 7, 8),
        new Rectangles(2, 3, 9, 14)
    };
    /* 입력 버전    
    int numRectangles;
    cout << "사각형의 개수를 입력하세요: ";
    cin >> numRectangles;

    // 동적 배열 할당: 사용자 입력 개수만큼의 사각형 포인터 배열 생성
    Rectangles** rectangles = new Rectangles*[numRectangles];
    
    // 각 사각형의 정보를 사용자로부터 입력받아서 객체 생성
    for (int i = 0; i < numRectangles; i++) {
        int x, y, w, h;
        cout << "사각형 " << i + 1 << "의 좌측 하단 x, 좌측 하단 y, 폭, 높이를 입력하세요: ";
        cin >> x >> y >> w >> h;
        rectangles[i] = new Rectangles(x, y, w, h);
    }*/

    showRectangless("정렬전:", rectangles, numRectangless);

    selectionSortRectangless(rectangles, numRectangless);

    showRectangless("정렬후:", rectangles, numRectangless);

    for (int i = 0; i < numRectangless; ++i) {
        delete rectangles[i];
    }
    //delete[] rectangles;
    system("pause");
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

class Student {
public:
    char* name;
    int age;
    char* city;
    
    Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent();
    ~Student(); // Destructor
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};

// Constructor 구현 - 동적 메모리 할당과 깊은 복사 구현
Student::Student(const char* name, int age, const char* city) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    
    this->age = age;
    
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
}

// Destructor 구현 - 동적 할당 해제
Student::~Student() {
    delete [] name;
    delete [] city;
}

// updateStudentCity: 기존 메모리를 해제하고 새 문자열로 대체
void Student::updateStudentCity(const char* city) {
    delete [] this->city;
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
}

// compareStudents: 이름을 기준으로 비교 (사전순)
int Student::compareStudents(const Student* b) {
    return strcmp(this->name, b->name);
}

// showStudent: 객체 정보 출력
void Student::showStudent() {
    cout << "Name: " << name << ", Age: " << age << ", City: " << city << endl;
}

// swap: 두 Student 객체의 데이터를 교환 (포인터 자체를 교환하는 것이 아니라 내부 멤버를 교환)
void Student::swap(Student* b) {
    // 이름 교환
    char* tempName = this->name;
    this->name = b->name;
    b->name = tempName;
    
    // 나이 교환
    int tempAge = this->age;
    this->age = b->age;
    b->age = tempAge;
    
    // 도시 교환
    char* tempCity = this->city;
    this->city = b->city;
    b->city = tempCity;
/*
    std::swap(name, b->name);
    std::swap(age, b->age);
    std::swap(city, b->city);
*/
}

// 전체 학생 객체를 출력하는 함수
void showStudents(string message,const Student* students[], int numStudents) {
    cout << message << endl;
    for (int i = 0; i < numStudents; i++) {
        students[i]->showStudent();
    }
    cout << endl;
}

// selectionSortStudents: 선택 정렬 알고리즘을 이용하여 학생들을 이름 기준으로 정렬
void selectionSortStudents(Student* students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < numStudents; j++) {
            if (students[j]->compareStudents(students[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // swap 함수를 이용하여 두 학생 데이터 교환
            students[i]->swap(students[minIdx]);
        }
    }
}

int main() {
    // 한글 깨짐 방지를 위한 코드 (Windows 전용)
    SetConsoleOutputCP(CP_UTF8);
    
/*int numStudents;
    cout << "학생의 수를 입력하세요: ";
    cin >> numStudents;
    cin.ignore();  // 개행 문자 제거
    
    // 동적 할당을 이용하여 Student 포인터 배열 생성
    Student** students = new Student*[numStudents];
    
    for (int i = 0; i < numStudents; i++) {
        char name[100];
        char city[100];
        int age;
        
        cout << "\n" << i + 1 << "번째 학생의 이름을 입력하세요: ";
        cin.getline(name, 100);
        
        cout << i + 1 << "번째 학생의 나이를 입력하세요: ";
        cin >> age;
        cin.ignore();  // 나이 입력 후 남은 개행문자 제거
        
        cout << i + 1 << "번째 학생의 도시를 입력하세요: ";
        cin.getline(city, 100);
        
        // 사용자 입력으로 학생 객체 생성 (동적 할당)
        students[i] = new Student(name, age, city);
    } */

    // 학생 객체 초기화
    int numStudents = 5;
    Student student1("홍길동", 23, "부산");
    Student student2("강감찬", 22, "의주");
    Student student3("을지문덕", 13, "살수");
    Student student4("이순신", 19, "한산도");
    Student student5("계백", 33, "공주");
    
    // 객체 배열(포인터 배열) 생성
    Student* students[5] = { &student1, &student2, &student3, &student4, &student5 };
    
    // 정렬 전 학생 정보 출력
    showStudents("정렬전:", students, numStudents);
    
    // student1의 city를 "나주"로 변경 후 출력
    student1.updateStudentCity("나주");
    student1.showStudent();
    cout << endl;
    
/*    if (numStudents > 0) {
        students[0]->updateStudentCity("나주");
        cout << "첫 번째 학생의 도시가 '나주'로 업데이트되었습니다:" << endl;
        students[0]->showStudent();
        cout << endl;
    }
    */

    // 학생 객체들을 이름을 기준으로 정렬 후 출력
    selectionSortStudents(students, numStudents);
    showStudents("정렬후:", students, numStudents);
    /*
        // 동적 할당 해제
    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }
    delete[] students;
    */
    system("pause");
    return 0;
}
//-------------------------------------------------------------------------------------------------------------------------
//4_17_static_cast
#include <iostream>

using namespace std;

// 열거형(enum) Menu 정의
enum Menu { ADD = 1, DELETE, SEARCH, PRINT, EXIT };

int main() {
    int choice;

    while (true) {
        // 메뉴 출력
        cout << "\n===== Menu =====\n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 정수를 enum 타입으로 변환
        Menu selectedMenu = static_cast<Menu>(choice);

        // switch 문으로 메뉴 선택
        switch (selectedMenu) {
        case ADD:
            cout << "You selected ADD.\n";
            break;
        case DELETE:
            cout << "You selected DELETE.\n";
            break;
        case SEARCH:
            cout << "You selected SEARCH.\n";
            break;
        case PRINT:
            cout << "You selected PRINT.\n";
            break;
        case EXIT:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            break;
        }
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring> // strcmp, strcpy_s

using namespace std;

#define MAX_LEN 20
#define SIZE 8

// 배열 출력 함수
void showData(const char* msg, char* arr[], int size) {
    cout << msg << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 문자열 교환 함수 (swap)
void swapStrings(char*& a, char*& b) {
    //a,b는 포인터를 참조하는 변수
    //a는 포인터를 가리키는 참조변수라는 의미
    char* temp = a;
    a = b;
    b = temp;
    //main 함수의 포인터가 변경됨
}

void swapStrings(char* a, char* b) {//a,b 포인터 값이 복사됨
    char* temp = a;
    a = b;
    b = temp;
    //main 함수의 포인터가 변경되지 않음
}

// 버블 정렬 함수 (오름차순) - Sort() 함수 사용 금지 -swap() 사용
void sortData(char* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) { // 오름차순 정렬 (A-Z)
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

// 문자열 삽입 후 크기 증가된 정렬 배열 반환 - Sort() 사용금지 O(n) 시간 복잡도로 해결- while 문 1개로 해결 
char** insertData(char* data[], int size, const char* value) {
    char* newValue = new char[MAX_LEN]; // 동적 메모리 할당
    strcpy_s(newValue, MAX_LEN, value);

    // 새로운 배열 생성 (size + 1 크기)
    char** newData = new char* [size + 1];
    for (int i = 0; i < size + 1; i++) {
        newData[i] = new char[MAX_LEN];
    }

    int i = size - 1;
    bool tag = true;

    // 기존 데이터를 복사하면서 새로운 데이터 삽입
    while (i >= 0) {
        if (strcmp(data[i], newValue) > 0) {
            strcpy_s(newData[i + 1], MAX_LEN, data[i]);
            i--;
            if (tag && i < 0) {
                strcpy_s(newData[i + 1], MAX_LEN, newValue);
                break;
            }
        }
        else {
            if (tag) {
                strcpy_s(newData[i + 1], MAX_LEN, newValue);
                tag = false;
                continue;
            }
            else {
                strcpy_s(newData[i], MAX_LEN, data[i]);
                i--;
            }
        }
    }

    delete[] newValue; // 동적 메모리 해제
    return newData;
}

int main() {
    // 초기 문자열 데이터 동적 할당
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

    showData("정렬 전", data, SIZE);

    sortData(data, SIZE);

    showData("정렬 후 (오름차순)", data, SIZE);

    // 삽입할 데이터
    const char* realData[3] = { "waterMelon", "kiwi", "apple" };

    for (const char* newData : realData) {
        char** result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " 삽입 후: ";
        showData("삽입 후 정렬된 배열", result, SIZE + 1);

        // 동적 할당된 메모리 해제
        for (int i = 0; i < SIZE + 1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    // 원래 배열의 메모리 해제
    for (int i = 0; i < SIZE; i++) {
        delete[] data[i];
    }
    system("pause");
    return 0;
}
/*int main() {
    int n, m;
    // 초기 문자열 개수 입력
    cin >> n;
    // n개의 문자열을 저장할 배열 동적 할당
    char** data = new char*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new char[MAX_LEN];
        cin >> data[i];
    }

    showData("정렬 전", data, n);
    sortData(data, n);
    showData("정렬 후 (오름차순)", data, n);

    // 삽입할 문자열 개수 입력
    cin >> m;
    // 각 삽입 연산마다 새로운 문자열 입력 및 결과 출력
    for (int j = 0; j < m; j++) {
        char temp[MAX_LEN];
        cin >> temp;
        char** result = insertData(data, n, temp);
        cout << "\n" << temp << " 삽입 후:";
        showData("삽입 후 정렬된 배열", result, n + 1);
        // 동적 할당된 result 메모리 해제
        for (int i = 0; i < n + 1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    // 원래 배열 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}*/
//-------------------------------------------------------------
#include <iostream>
#include <cstring>

using namespace std;

// 자동차 클래스 (데이터 멤버를 private으로 변경)
class Car {
private:
    char manufacturer[50]; // 제조사 char *manufacturer; 구현할 줄 알아야 한다.
    char model[50];        // 모델명 char *model; 구현할 줄 알아야 한다.
    double weight;         // 차중량 (kg)
    int length;            // 전장(mm)
    int width;             // 전폭(mm)
    int speed;             // 속도

public:
    // 생성자 선언
    Car(const char* m, const char* mod, double w, int l, int wdt, int s);
    Car();

    // Getter & Setter
    void setManufacturer(const char* m);
    const char* getManufacturer() const;
    void setModel(const char* mod);
    const char* getModel() const;
    void setWeight(double w);
    double getWeight() const;
    void setLength(int l);
    int getLength() const;
    void setWidth(int w);
    int getWidth() const;
    void setSpeed(int s);
    int getSpeed() const;

    // 전장 기준으로 차급 세그먼트 분류
    const char* getSegment();

    // 과속 여부 판단 메소드
    void checkSpeeding(int speedLimit);
    void checkSpeeding();

    // 객체 정보를 출력하는 연산자 오버로딩
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// 자동차 클래스 멤버 함수 구현
// =============================

// 생성자 정의
Car::Car(const char* m, const char* mod, double w, int l, int wdt, int s) {
    strncpy(manufacturer, m, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
    weight = w;
    length = l;
    width = wdt;
    speed = s;
}

Car::Car() {
    manufacturer[0] = '\0';
    model[0] = '\0';
    weight = 0.0;
    length = 0;
    width = 0;
    speed = 0;
}

// Getter & Setter 구현
void Car::setManufacturer(const char* m) {
    strncpy(manufacturer, m, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
}
const char* Car::getManufacturer() const {
    return manufacturer;
}
void Car::setModel(const char* mod) {
    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
}
const char* Car::getModel() const {
    return model;
}
void Car::setWeight(double w) {
    weight = w;
}
double Car::getWeight() const {
    return weight;
}
void Car::setLength(int l) {
    length = l;
}
int Car::getLength() const {
    return length;
}
void Car::setWidth(int w) {
    width = w;
}
int Car::getWidth() const {
    return width;
}
void Car::setSpeed(int s) {
    speed = s;
}
int Car::getSpeed() const {
    return speed;
}

// 전장 기준으로 차급 세그먼트 분류
const char* Car::getSegment() {
    if (length < 4200)
        return "B-세그먼트 (소형차)";
    else if (length < 4600)
        return "C-세그먼트 (준중형, 소형 패밀리카)";
    else if (length < 4900)
        return "D-세그먼트 (중형차, 패밀리 세단)";
    else if (length < 5100)
        return "E-세그먼트 (대형차, 고급 세단)";
    else
        return "F-세그먼트 (초대형차, 플래그십 세단)";
}

// 과속 여부 판단
void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "과속 경고! (제한 속도: " << speedLimit << " km/h)" << endl;
    else
        cout << "정상 주행" << endl;
}
void Car::checkSpeeding() {
    checkSpeeding(60);
}

// 객체 정보를 출력하는 연산자 오버로딩
ostream& operator<<(ostream& os, const Car& car) {
    os << "제조사 = " << car.manufacturer
        << ", 모델 = " << car.model
        << ", 중량 = " << car.weight << " kg"
        << ", 전장 = " << car.length << " mm"
        << ", 전폭 = " << car.width << " mm"
        << ", 속도 = " << car.speed << " km/h";
    return os;
}

// 메인 함수
int main() {
    // 자동차 객체 생성
    Car car1("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car car2("BMW", "M3", 1200, 4500, 1700, 110);

    // 객체 멤버 변경 (setter 사용)
    car1.setSpeed(80);
    car2.setManufacturer("Mercedes");

    cout << "수정된 차량 정보:" << endl;
    cout << car1 << endl;
    cout << car2 << endl;

    // 기본 생성자 사용
    Car c1;
    c1.setManufacturer("Toyota");
    c1.setModel("Camry");
    c1.setSpeed(70);

    cout << "기본 생성자로 생성된 차량 정보:" << endl;
    cout << c1 << endl;

    /*
        int n;
    cout << "자동차의 개수를 입력하세요: ";
    cin >> n;

    // 동적으로 Car 객체 배열 생성
    Car* cars = new Car[n];

    // 각 자동차의 정보를 입력받음
    // 입력 순서: 제조사, 모델, 중량(kg), 전장(mm), 전폭(mm), 속도(km/h)
    for (int i = 0; i < n; i++) {
        char manuf[50], model[50];
        double weight;
        int length, width, speed;
        cout << "\n자동차 " << i + 1 << "의 정보를 입력하세요:" << endl;
        cout << "제조사: ";
        cin >> manuf;
        cout << "모델: ";
        cin >> model;
        cout << "중량 (kg): ";
        cin >> weight;
        cout << "전장 (mm): ";
        cin >> length;
        cout << "전폭 (mm): ";
        cin >> width;
        cout << "속도 (km/h): ";
        cin >> speed;

        // 입력받은 정보를 바탕으로 객체 생성
        cars[i] = Car(manuf, model, weight, length, width, speed);
    }

    cout << "\n입력된 차량 정보:" << endl;
    for (int i = 0; i < n; i++) {
        cout << cars[i] << endl;
    }

    // 동적으로 할당한 메모리 해제
    delete[] cars;
    */
    return 0;
}

//this 포인터//-------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string manufacturer;
    int speed;

public:
    // 생성자에서 this 포인터 사용
    Car(string manufacturer, int speed) {
        this->manufacturer = manufacturer;  // this-> 사용
        this->speed = speed;
    }

    // Setter에서 this 포인터 사용
    Car& setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
        return *this;  // this 포인터를 사용하여 객체 자신을 반환
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // 멤버 함수에서 this 포인터 사용
    void printCarInfo() {
        cout << "제조사: " << this->manufacturer << ", 속도: " << this->speed << " km/h" << endl;
    }
};

int main() {
    Car car1("Hyundai", 80);

    car1.setSpeed(100);
    // this 포인터 활용: Method Chaining
    car1.setManufacturer("Toyota").setSpeed(100).printCarInfo();

    return 0;
}

//------------------------------------------------------------------- 복사 생성자
#include <iostream>

using namespace std;
class Car {
private:
    char *manufacturer;
    int speed;

public:
    // 기본 생성자 (Default Constructor)
    Car() {
        manufacturer = "Unknown";
        speed = 0;
        cout << "Default Constructor 호출" << endl;
    }

    // 일반 생성자 (Parameterized Constructor)
    Car(char* manufacturer, int speed) {
        this->manufacturer = manufacturer;
        this->speed = speed;
        cout << "Parameterized Constructor 호출" << endl;
    }

    // 복사 생성자 (Copy Constructor)
    Car(const Car& other) {
        this->manufacturer = other.manufacturer;
        this->speed = other.speed;
        cout << "Copy Constructor 호출" << endl;
    }
/*    // 복사 생성자 (Deep Copy Implementation) -- > 소멸자에서 delete[] manufacturer
    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        cout << "Copy Constructor 호출 (Deep Copy)" << endl;
    }*/ 

    // 소멸자 (Destructor)
    ~Car() {
        cout << "Destructor 호출: " << manufacturer << endl;
    }

    // Setter에서 this 포인터 사용 (Method Chaining)
    Car& setManufacturer(char * manufacturer) {
        this->manufacturer = manufacturer;
        return *this;  // this 포인터를 사용하여 객체 자신을 반환
    }
/*    // Setter에서 this 포인터 사용 (Method Chaining) --> deep copy 버전에서의 setter
    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer; // 기존 메모리 해제
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        return *this;  // this 포인터를 사용하여 객체 자신을 반환
    }
*/

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // 멤버 함수에서 this 포인터 사용
    void printCarInfo() {
        cout << "제조사: " << this->manufacturer << ", 속도: " << this->speed << " km/h" << endl;
    }
};

int main() {
    cout << "=== Default Constructor 실습 ===" << endl;
    Car car1; // 기본 생성자 호출
    car1.printCarInfo();

    cout << "\n=== Parameterized Constructor 실습 ===" << endl;
    Car car2("Hyundai", 80); // 일반 생성자 호출
    car2.printCarInfo();

    cout << "\n=== Copy Constructor 실습 ===" << endl;
    Car car3 = car2; // 복사 생성자 호출
    car3.printCarInfo();

    cout << "\n=== Method Chaining 실습 ===" << endl;
    car2.setManufacturer("Toyota").setSpeed(100).printCarInfo();
/* 고급과정
    // 동적 할당된 객체를 삭제 (소멸자 호출됨)
    delete car1;
    delete car2;
    delete car3;

    //난이도 상 - 고급과정
    Car* carSet = new Car[10]; //10개의 객체를 생성 - Car()를 호출
    carSet[0].setManufacturer("Toyota");
    carSet[1].setSpeed(120);
    carSet[2].printCarInfo();

    //Car* carSet = new Car[10]("Hyundai", 100); // 에러

    Car* carSet2[10];
    for (int i = 0; i < 10; ++i) {
        carSet2[i] = new Car("Hyundai", 100 + i * 10); // 각각 생성자 호출
    }

    for (int i = 0; i < 10; ++i)
        delete carSet2[i];

    int num;
    cin >> num;
*/

    return 0; // 소멸자 자동 호출
}


//-------------------------------------------------------------------
//이거 문제 냈음 

#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char* manufacturer; //인스턴트 변수수
    int speed;

    static int count; //클래스 변수

public:
    static int getCarCount() { // 클래스 메서드
        return count;
    }

    Car() {
        manufacturer = new char[8];
        strcpy(manufacturer, "Unknown");
        speed = 0;
        ++count;
        cout << "Default Constructor 호출" << endl;
    }

    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        ++count;
        cout << "Parameterized Constructor 호출" << endl;
    }

    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        ++count;
        cout << "Copy Constructor 호출" << endl;
    }

    ~Car() {
        cout << "Destructor 호출: " << manufacturer << endl;
        delete[] manufacturer;
        --count;
    }

    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        return *this;
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    void showCars() const {
        cout << "제조사: " << manufacturer
            << ", 속도: " << speed << " km/h"
            << ", 현재 Car 객체 수: " << count << endl;
    }
};

int Car::count = 0;

// ===================== main =====================
int main() {
    const int SIZE = 5;

    // Car 객체 배열을 포인터 변수로 관리 (heap에 배열 생성)
    Car* carSet = new Car[SIZE]; // Default Constructor 5번 호출됨

    // 일부 객체 정보 설정 및 출력
    carSet[0].setManufacturer("Hyundai").setSpeed(100);
    carSet[1].setManufacturer("Toyota").setSpeed(120);
    carSet[2].setManufacturer("Kia").setSpeed(90);

    cout << "\n=== carSet[i].showCars() ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].showCars();  // 객체 정보 및 전체 객체 수 출력
    }

    cout << "\n현재 전체 Car 객체 수: " << Car::getCarCount() << endl;

    // 메모리 해제
    delete[] carSet;  // 모든 객체의 소멸자 자동 호출됨

    cout << "Car 객체 모두 삭제 후 수: " << Car::getCarCount() << endl;

    return 0;
}

//string 버전



#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string manufacturer;
    string licensePlate;
    int speed;

    static int count;

public:
    Car() {
        manufacturer = "Unknown";
        licensePlate = "None";
        speed = 0;
        ++count;
        cout << "Default Constructor 호출" << endl;
    }

    Car(string manufacturer, string licensePlate, int speed) {
        this->manufacturer = manufacturer;
        this->licensePlate = licensePlate;
        this->speed = speed;
        ++count;
        cout << "Parameterized Constructor 호출" << endl;
    }

    ~Car() {
        cout << "Destructor 호출: " << manufacturer << " (" << licensePlate << ")" << endl;
        --count;
    }

    // setters
    Car& setManufacturer(const string& m) {
        manufacturer = m;
        return *this;
    }

    Car& setLicensePlate(const string& l) {
        licensePlate = l;
        return *this;
    }

    Car& setSpeed(int s) {
        speed = s;
        return *this;
    }

    void show() const {
        cout << "제조사: " << manufacturer
            << ", 번호판: " << licensePlate
            << ", 속도: " << speed << " km/h"
            << ", 전체 객체 수: " << count << endl;
    }

    static int getCount() {
        return count;
    }
};

// static 변수 정의
int Car::count = 0;

// ===================== main =====================
int main() {
    const int SIZE = 3;

    /*    int n;
    cout << "몇 개의 Car 객체를 생성할까요? : ";
    cin >> n;
    cin.ignore(); // 남은 개행 문자 제거*/
    Car* carSet = new Car[SIZE];  // 힙에 Car 객체 배열 생성

    carSet[0].setManufacturer("Hyundai").setLicensePlate("12가3456").setSpeed(100);
    carSet[1].setManufacturer("Toyota").setLicensePlate("78나9012").setSpeed(120);
    carSet[2].setManufacturer("Kia").setLicensePlate("34다5678").setSpeed(90);


    /*    // 각 Car 객체에 대해 사용자 입력 받기
    for (int i = 0; i < n; i++) {
        string manufacturer, licensePlate;
        int speed;
        cout << "\nCar " << i + 1 << "의 제조사를 입력하세요: ";
        getline(cin, manufacturer);
        cout << "Car " << i + 1 << "의 번호판을 입력하세요: ";
        getline(cin, licensePlate);
        cout << "Car " << i + 1 << "의 속도를 입력하세요: ";
        cin >> speed;
        cin.ignore(); // 개행 문자 제거

        // 입력받은 값으로 해당 객체 정보 설정 (이미 생성된 기본 생성자 객체에 setter 호출)
        carSet[i].setManufacturer(manufacturer)
                 .setLicensePlate(licensePlate)
                 .setSpeed(speed);
    }
*/
    cout << "\n=== Car 객체 정보 출력 ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].show();
    }

    cout << "\n현재 전체 Car 객체 수: " << Car::getCount() << endl;

    delete[] carSet;  // 소멸자 자동 호출

    cout << "\n객체 삭제 후 수: " << Car::getCount() << endl;

    return 0;
}


1. 생성자
string s1;     
// 기본 생성자 (빈 문자열)
 string s2("Hello");    
// const char* → string
 string s3(s2);    
// 복사 생성자
string s4(5, 'A');  // "AAAAA"
 string s5 = "World";   // 암시적 생성
2. 치환문
string s1 = "Hello";
 string s2;
 s2 = s1;               
s2 = "World";          
3. 비교 연산자
string a = "apple";
 string b = "banana";
 // 다른 문자열로 대입
// const char* 대입도 가능
5.7 class를 선택하는 방법 39  <<<
if (a == b)    
if (a != b)    
if (a < b)     
if (a >= b)
 // 같음
// 다름
// 사전순 비교
4. 문자열 결합 & 추가
string s = "Hello";
 s += " World";          
// 문자열 덧붙이기
string full = s + "!";  // 문자열 연결
5. 입력/출력
string name;
 cin >> name;             
getline(cin, name);      
cout << name << endl;    
// 공백 이전까지 입력
// 한 줄 전체 입력
// 출력
6. 길이, 부분문자열, 문자 접근
string s = "Hello";
 int len = s.length();     
char c = s[0];            
// 또는 s.size()
 // 문자 접근
string sub = s.substr(1, 3);  // "ell“
 7. 찾기, 치환
string s = "banana";
 size_t pos = s.find("na");      
s.replace(pos, 2, "XX");        
// 첫 위치: 2
 // "baXXna"


 //심화 버전 9번조건
 #include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    int score[5];
    string subject[5];

public:
    // 기본 생성자: name과 age는 기본값, score는 0, subject는 빈 문자열로 초기화
    Student() : name(""), age(0) {
        for (int i = 0; i < 5; i++) {
            score[i] = 0;
            subject[i] = "";
        }
    }
    
    // 파라미터 생성자: name, age와 함께 score와 subject 배열을 초기화
    Student(const string &name, int age, const int sc[5], const string sub[5])
        : name(name), age(age) {
        for (int i = 0; i < 5; i++) {
            score[i] = sc[i];
            subject[i] = sub[i];
        }
    }
    
    // Getter 메서드들
    string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    // 특정 인덱스의 점수를 반환 (인덱스 범위를 벗어나면 -1 반환)
    int getScore(int index) const {
        if (index >= 0 && index < 5)
            return score[index];
        return -1; // 에러 처리: 예외 처리로 구현할 수도 있음.
    }
    
    // 특정 인덱스의 과목명을 반환 (인덱스 범위를 벗어나면 빈 문자열 반환)
    string getSubject(int index) const {
        if (index >= 0 && index < 5)
            return subject[index];
        return "";
    }
    
    // Setter 메서드들
    void setName(const string &n) {
        name = n;
    }
    
    void setAge(int a) {
        age = a;
    }
    
    // 특정 인덱스의 score를 설정 (유효한 인덱스인지 확인)
    void setScore(int index, int value) {
        if (index >= 0 && index < 5)
            score[index] = value;
    }
    
    // 특정 인덱스의 subject를 설정 (유효한 인덱스인지 확인)
    void setSubject(int index, const string &s) {
        if (index >= 0 && index < 5)
            subject[index] = s;
    }
    
    // 객체 정보를 출력하는 메서드
    void printInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Scores: ";
        for (int i = 0; i < 5; i++) {
            cout << score[i] << " ";
        }
        cout << "\nSubjects: ";
        for (int i = 0; i < 5; i++) {
            cout << subject[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // 파라미터 생성자에 전달할 배열들
    int scores[5] = {90, 85, 78, 92, 88};
    string subjects[5] = {"Math", "English", "Science", "History", "Art"};
    
    // Student 객체 생성
    Student s("Alice", 20, scores, subjects);
    cout << "초기 Student 정보:" << endl;
    s.printInfo();
    
    // Setter를 이용하여 값 변경
    s.setName("Alice Smith");
    s.setAge(21);
    s.setScore(2, 95);      // 3번째 점수를 95로 변경
    s.setSubject(2, "Physics");  // 3번째 과목을 "Physics"로 변경

    // 변경된 값은 Getter를 이용하여 확인 가능
    cout << "\nGetter로 값 확인:" << endl;
    cout << "Name: " << s.getName() << "\n";
    cout << "Age: " << s.getAge() << "\n";
    cout << "Score[2]: " << s.getScore(2) << "\n";
    cout << "Subject[2]: " << s.getSubject(2) << "\n";
    
    // 변경된 Student 정보 출력
    cout << "\n변경 후 Student 정보:" << endl;
    s.printInfo();
    
    return 0;
}
