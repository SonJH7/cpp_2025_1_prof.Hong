//4-7. 타입CASTING.cpp    4.5.4 static_cast
#include <iostream>
#include <string.h>
using namespace std;

class Base{
public:
    virtual void classname(){cout << "Base" << endl;};
};
class Derived : public Base{
public:
    void classname(){cout << "Derived" << endl;};
};
void main(){
    //1번 주석
    //*
    cout<<"(1번)괄호를 이용한 타입 전환"<<endl;
    int i = 5;
    float f = 3.45;
    int j = (int)f;
    float f2 = (float)i;
    cout << "i : " << i << "   f : " << f << endl;
    cout << "j : " << j << "   f2 : " << f2 << endl;

    int x = 9, y = 2;
    float result;
    //result = (float) x / (float) y;
    result = x / (float)y;
    cout << "x : " << x << "   y : " << y << "   result : " << result << endl;
   //*/


    //2번 주석
    //*
    cout << endl << "(2번) static_cast" << endl;
    char ca = 'a';
	int k = 10;
	int number = (int)ca;
	int *p = &k;
	number = (int)p;//실행 가능하나 문제가 있음
	//number = static_cast<int>(p);//pointer를 int로 변환하는 것을 못하게 함- static_cast를 사용하는 이유
    int num = static_cast<int>(ca);
    cout << "ca : " << ca <<"   num : " << num << endl;

    int d = 15, e = 7;
    float r = static_cast<float> (d) / static_cast<float>(e);
    cout << "d : " << d << "   e : " << e << "   result : " << r << endl;
    //*/

    //3번 주석
  ///*
    cout << endl << "(3번) const_cast" << endl;
    const int n = 10;
    //int* d = &n; 
    int* m = const_cast<int*> (&n); 
	*m = 99;//n,m의 주소는 같으나 변경된 값은 다르다- 주의 필요- n은 상수값,*m은 같은 주소를 가리키는 값으로 컴파일러에 따라 결과 다르다- 해서는 안되는 코드이다  
    //n++;
    cout << "&n : " << &n << "   m : " << m << endl;
    cout << "n : " << n << "   *m : " << *m << endl; //n의 값은 const
  //*/

    //4번 주석
   //*
    Base *pb = new Derived();
    Derived *pd = NULL;
	pb = pd;
	//pb = (Base)pd;
    //pd = pb;
    pd = dynamic_cast<Derived*>(pb); 
    //*/

    //5번 주석
    //*
    //reinterpret_cast - 상이한 type을 강제로 변환

    int s = 1020;
    char *h = NULL;
    char *cp2 = NULL;
    h = (char*)s; 
    //h = static_cast<char*>(s);
    h = reinterpret_cast<char*>(s); 
    //cout <<*h<< endl; //메모리 접근 에러 발생
    //*/
	int nmb = 10;
	float *ptr = reinterpret_cast<float*>(&nmb);
	cout << *ptr << endl;
	system("pause");
}

//4장-16. DYNAMIC_CAST.cpp   4.5.2 dynamic_cast
#include <iostream>
//실행 확인만 하고 6장에서 실습 - 맛보기 코드임 
using namespace std;
class Parent{
public:
    virtual void Print(){}
};
class Child_1 : public Parent{
public:
    virtual void Print(){
    cout << "Child_1 is ok" << endl;
    }
};

class Child_2 : public Parent{
public:
    virtual void Print(){
        cout << "Child_2 is ok" << endl;
    }
};
void main(){
    Parent *p_1 = new Child_1;
    Parent *p_2 = new Parent;

    Child_1 *pchild1 = dynamic_cast<Child_1*> (p_1);
    //pchild1 = p_1;
    if (NULL == pchild1)
        cout << "Child_1 == NULL" << endl;
    else
        pchild1->Print();

	Child_2 *child2;
	child2	= dynamic_cast<Child_2*> (p_2);//null을 리턴한다 - 교재 설명
	//child2 = p_2;
    if (NULL == child2)
        cout << "Child_2 == NULL" << endl;
    else
        child2->Print();

    Child_2 *pchild2 = dynamic_cast<Child_2*> (p_1);//null을 리턴한다 - 교재 설명 
    if (NULL == pchild2)
        cout << "Child_2 == NULL" << endl;
    else
        pchild2->Print();
	system("pause");
}

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
