//4_11_return By value
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct complex {
    float real;
    float imaginary;
};

// 난수를 사용하여 복소수를 생성하는 함수 (Call by Value 반환)
complex getComplex() {
    complex c;
    c.real = (rand() % 100) / 10.0;      // 0.0 ~ 9.9
    c.imaginary = (rand() % 100) / 10.0; // 0.0 ~ 9.9
    return c;
}

// 두 개의 복소수를 더하는 함수 (Call by Value)
complex addComplex(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// 복소수를 출력하는 함수
void showComplex(complex c) {
    cout << c.real;
    if (c.imaginary >= 0) cout << " + " << c.imaginary << "i" << endl;
    else cout << " - " << -c.imaginary << "i" << endl;
}

int main() {
    srand(time(0)); // 난수 시드 초기화

    // 두 개의 복소수를 난수로 생성
    complex num1 = getComplex();
    complex num2 = getComplex();

    // 두 복소수를 출력
    cout << "Complex Number 1: ";
    showComplex(num1);

    cout << "Complex Number 2: ";
    showComplex(num2);

    // 두 복소수를 더함
    complex sum = addComplex(num1, num2);

    // 합산 결과 출력
    cout << "Sum: ";
    showComplex(sum);

    return 0;
}

//4_12_return By reference
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct complex {
    float real;
    float imaginary;
};

// 난수를 사용하여 복소수를 생성하는 함수 (Pass by Reference로 반환 값을 저장)
void getComplex(complex& c) {
    c.real = (rand() % 100) / 10.0;      // 0.0 ~ 9.9
    c.imaginary = (rand() % 100) / 10.0; // 0.0 ~ 9.9
}

// 두 개의 복소수를 더하는 함수 (Pass by Reference & Return by Reference)
complex& addComplex(const complex& c1, const complex& c2, complex& result) {
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;  // result는 main 함수에서 선언된 변수이므로 안전한 참조 반환 가능
}

// 복소수를 출력하는 함수 (Pass by Reference)
void showComplex(const complex& c) {
    cout << c.real;
    if (c.imaginary >= 0) cout << " + " << c.imaginary << "i" << endl;
    else cout << " - " << -c.imaginary << "i" << endl;
}

int main() {
    srand(time(0)); // 난수 시드 초기화

    complex num1, num2, sum; // 복소수 구조체 선언

    // 난수를 생성하여 복소수에 저장 (Pass by Reference 사용)
    getComplex(num1);
    getComplex(num2);

    // 두 복소수를 출력
    cout << "Complex Number 1: ";
    showComplex(num1);

    cout << "Complex Number 2: ";
    showComplex(num2);

    // 두 복소수를 더함 (Pass by Reference & Return by Reference)
    addComplex(num1, num2, sum);

    // 합산 결과 출력
    cout << "Sum: ";
    showComplex(sum);

    return 0;
}
//4_13_return by reference3.cpp   4.4.4 reference에 의한 함수 return 값
#include <iostream>
using namespace std;
int& sub(int a, int b);

void main(){
    int c = 1, d = 2;
    int &result = sub(c,d);
    result = result + c;

    printf("main()::sub() = %d\n", sub(c, d));//올바른 값을 출력
    cout << "main():: result = " << result << endl; //오류 값을 출력
	system("pause");
}
int& sub(int a, int b){
    int temp;
    temp = a+b;

	printf("int& sub(int,int)::&temp = %p   ", &temp);
    cout << " a = " << a << " b = " << b << " temp = " << temp << endl;
    return temp;//local variable의 주소가 return되는 것을 확인 - 나중에 stack에서 사라질수 있어 위험
}


//4장-12. Cascade.cpp   4.4.4 reference에 의한 함수 return 값
// return by reference의 전형적인 사례로서 6장 이후 학습할 주요 대상
//4장에서는 단순 실행하여 보는 것으로 실습함 - 4장의 실습 구현 대상이 아님 /맛보기 코드임 
#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imaginary;
public:
    Complex() { real = 0.0; imaginary = 0.0; }
    Complex(float r, float i) : real(r), imaginary(i) { }

    void showComplex() const {
        cout << real << " + " << imaginary << "i" << endl;
    }

    // add() 함수 (Return by Reference)
    Complex& add(const Complex& T);
};

// add() 함수 정의 (Return by Reference)
Complex& Complex::add(const Complex& T) {
    //Complex result;
    this->imaginary = this->imaginary + T.imaginary;
    this->real = this->real + T.real;
    cout << "add(const Complex&):: ";
    this->showComplex();
    return *this;
    //return result;//오류 발생
}

int main(void) {
    Complex C1(1.1, 2.2);
    cout << "C1 = "; C1.showComplex();

    Complex C2(3.3, 4.4);
    cout << "C2 = "; C2.showComplex();

    Complex C3(7.7, 9.9);
    cout << "C3 = "; C3.showComplex();

    Complex C4;

    // 연산자 오버로딩 대신 add() 함수 사용
    C4 = C1.add(C2).add(C3);

    cout << "C4 = "; C4.showComplex();

    system("pause");
    return 0;
}

