//C언어의 struct 이용
#include <stdio.h>

struct Point
{
    int x;
    int y;   
};

int main(){
    struct Point p;
    p.x = 5;
    p.y = 10;
    printf("점 좌표 = (%d, %d)\n", p.x, p.y);
    return 0;
}

//c++ class를 이용한 좌표 객체
#include <iostream>

class Point{
    public:
        int x;
        int y;
    
    Point(int x_val,int y_val) : x(x_val), y(y_val){}
};
using namespace std;
int main(){
    Point p(5,10);
    cout << "점 좌표= (" << p.x << ", " << p.y << ")\n";
}

//c++의 struct 이용
#include <iostream>
using namespace std;
struct Point{
    int x;
    int y;
    
    Point(int x_val,int y_val) : x(x_val), y(y_val){}

    void printCoordinates(){
        cout << "점 좌표= (" << x << ", " << y << ")\n";
    }

    void move(int dx, int dy){
        x += dx;
        y += dy;
    }
};

int main(){
    Point p(7,7);

    p.printCoordinates();
    p.move(77,77);
    p.printCoordinates();
    return 0;
}