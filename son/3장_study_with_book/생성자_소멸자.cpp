// 생성자와소멸자
#include <iostream>

using namespace std;
 // 여러개의 생성자를 갖는 class Date의 부분 정의
classDate{
    intmonth;
    int day;
    int year;
 public:
 /*
 // parameter가 있는 생성자
Date (intm, int d, int y):month (m), day (d), year (y){ }
 // 기본생성자 (parameter가 없는 경우에 default값으로 초기화)
 Date(){
 // compiler는 미정의된 내부 데이터 member값을 초기화 하지않는다.
 // 그래서 다음과 초기 값을 사전 설정하는 것이 필요하다.
    month=1;
    day=1;
    year =2000;
 }
 */

 voidshowDate(){
     cout << year << "년" << month << "월" << day << "일" << endl;
 }
 ~Date(){
    cout << "소멸자호출" << endl;
 }
};
void main(){
 // 주석1
 // 생성자가 없을경우
/*
 Date date;
 // 생성자가 없을 경우 compiler가 자동으로 생성해주지만,
 // 아무런 일을 하지않기 때문에 쓰레기 값이 출력됨
date.showDate();
 */
 // 주석2
 // parameter가 없는 생성자
/*
 Date date1;
 date1.showDate();
 */
 //주석3
 //parameter가 있는 생성자
/*
 Datedate2(3, 1, 2017);
 date2.showDate();
 */
 system("pause");
 }