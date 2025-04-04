// 여러 개의 생성자를 갖는 class Date의 부분 정의
class Date{
    int month;
    int day;
    int year;
public:
// "표준" 생성자
    Date (int m, int d, int y):month (m), day (d), year (y){ }

// default 생성자 
//parameter가 없는  경우에 default 값으로 초기화
    Date (){
    // compiler는 미 정의된 내부 데이터 member에 0을 치환, 그래서 다음과 초기 값을 사전 설정하는 것이 필요
        month = 1;
        day = 1;
        year = 2000;
    }
// 다음 함수들은 또 다른 생성자 Date(Date d, int nn)에서 사용되기 때문에 추가됨
    int Month();
    int Day();
    int Year();
    void IncreaseDate();
// "이상급증현상(oddball day)" 생성자 
// 현재 날짜 d 이후 nn 일이 경과한 후에 기상이변 등이 발생한 날짜를 생성
    Date (Date d, int nn){
    month = d.Month();
    day = d.Day();
    year = d.Year();
    for (int i = 1; i > nn; i++)
        IncreaseDate();
    }
};