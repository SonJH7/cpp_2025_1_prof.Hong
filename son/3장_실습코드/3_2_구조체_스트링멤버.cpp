#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;
struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
    char* name;
};


int compareRectangles(const Rectangle* a, const Rectangle* b) {
    return (a->leftBottomX - b->leftBottomX);
}
void showRectangle(struct Rectangle r) {
    printf("[%d, %d, %d, %d, %s]\n", r.leftBottomX, r.leftBottomY, r.width, r.height, r.name);
}

void changeRectangle(Rectangle* r, char* newName) {
    std::cout << "r1 name is changed" << std::endl;
    // r.name = newName;
    // strcpy(r.name, newName);
    r->name = strdup(newName); //신기하네
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
    //void showRectangle(struct Rectangle r) 사용
    std::cout << message << std::endl;
    for(int i=0; i<numRectangles; i++){
        showRectangle(*rectangles[i]);
    }
}
void swap(Rectangle* rect[], int i, int j) {
    Rectangle* temp = rect[i];
    rect[i] = rect[j];
    rect[j] = temp;
}
void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
    // int compareRectangles(const Rectangle* a, const Rectangle* b)를 사용한 정렬
    // void swap(Rectangle * rect[], int i, int j) 사용
    for(int i=0; i<numRectangles-1; i++){
        for(int j=i+1; j<numRectangles; j++){
            if(compareRectangles(rectangles[i],rectangles[j])>0)
                swap(rectangles,i,j);
        }
    }

}
int main(void) {
    SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15,"r1" };
    struct Rectangle r2 = { 1, 2, 8, 12 ,"r2" };
    struct Rectangle r3 = { 1, 2, 8, 10,"r3" };
    struct Rectangle r4 = { 3, 5, 10, 15 ,"r4" };
    struct Rectangle r5 = { 3, 5, 10, 14,"r5" };
    struct Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("정렬전:", rectangles, numRectangles);
    changeRectangle(&r1, "square");


    showRectangle(r1);
    showRectangles("변경후:", rectangles, numRectangles);
    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("정렬후:", rectangles, numRectangles);

    system("pause");
    return 0;
}