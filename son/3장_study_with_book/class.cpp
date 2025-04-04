//class Date의 객체 표현까지 기술
#include <iostream>

using namespace std;
class Date{
    //encapsulation
    int month;
    int day;
    int year;
public:
    Date(int m, int d, int y) : month(m), day(d), year(y){
        if (month == 2 && day>= 29) cout << "incorrect date" << endl;
    }

    int Month(){
        return month;
    }
    int Day(){
        return day;
    }
    int Year(){
        return year;
    }
    int LeapYear(){
        if ( year % 4 != 0 )
            return 0;
        else{
            if ( year % 100 != 0 ) return 1;
            else if ( year % 400 != 0 ) return 0;
                else return 1;
        }
    }

    int DayInMonth(){
        switch (month)
        {
        case 2:
            if( LeapYear()) return 29;
            else return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
        }
    }

    void IncreaseDate (){
        if( day < DayInMonth()) day++;
        else{
            day=1;
            if (month != 12) month++;
            else{
                month=1;
                year++;
            }
        }
    }
    void PrintDate(){
        cout << endl << "Date : " << month << "/" << day << "/" << year << endl;
    }
    void PrintLeap(){
        cout << endl << "The year" << year;
        if(LeapYear()) cout << " is a leap-year";
        else cout << " is not a leap-year";
    }
};

int main(){
    Date newYearsDay (1,1,2017);
    newYearsDay.PrintDate();
    newYearsDay.IncreaseDate();
    newYearsDay.PrintDate();
    newYearsDay.PrintLeap();
    Date d (7,17,2016);
    d.IncreaseDate();
    d.PrintDate();
    d.PrintLeap();

    for(Date dd(2,25,2017); dd.Day()<3||dd.Day()>10; dd.IncreaseDate())
        dd.PrintDate();
    return 0;
    
}