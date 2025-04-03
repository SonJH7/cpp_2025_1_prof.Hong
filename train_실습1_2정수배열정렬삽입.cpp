#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
//난수를 10 ~ 60 사이에 생성
void inputData(int data[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {

        int num = (rand() % 50) + 10;
        data[i] = num;
    }

}

void showData(string s, int data[], int size) {
    
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    
    
    cout << s << "\n";
}


//인덱스 받아와서 바꾸기
void swap(int arr[], int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

//오름차순 정렬
void sortData(int data[], int size) {
    //버블정렬
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (data[i] >= data[j]) swap(data, i, j);
        }
    }
}

//역순 재배치
void reverse(int data[], int size) {
    //맨앞과 맨뒤를 순서대로 swap
    for (int i = 0; i < (size / 2); i++) {
        swap(data, i, size - 1 - i);
    }
}

/*
 * 난이도가 매우 높은 알고리즘 구현
 * 정렬된 기존 배열에 임의 값을 추가하는 알고리즘 > 새 배열의 크기는 기존 배열보다 +1로 만들고 기존 배열을 copy할 때
 * 삽입된 값이 중간에 들어가는 알고리즘 구현하기
 * O(n) 알고리즘으로 구현
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[size + 1];// 함수 종료후에도 남아 있어 delete[] 필요
    int idx=0;
    bool find_idx = false;
    bool ist = false;
    
    
    
    //맨 앞에 집어넣기
    if (data[0] > value) {
        newData[0] = value;
        for (int i = 0; i < size; i++) {
            newData[i + 1] = data[i];
        }
    }
    //맨 끝에 집어넣기
    else if (data[size - 1] < value) {
        newData[size] = value;
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
    }

    //중간에 집어넣기
    else {
        for (int i = 0; i < size; i++) {
            //data[] 돌면서 value가 들어갈 위치 찾기
            if (data[i] <= value && !find_idx) {
                if (data[i + 1] >= value) {
                    idx = i;
                    find_idx = true;
                }

            }
            if (find_idx && !ist) {
                newData[idx + 1] = value;
                ist = true;
            }
            else {
                //넣은 위치 전까지는 똑같이 넣기
                if (i < idx + 1) newData[i] = data[i];
                //넣고 나서는 한칸뒤에 넣기
                else if (i > idx + 1)newData[i + 1] = data[i];
            }

        }
    }
    return newData;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE);
    showData("\n난수 입력", data, SIZE);

    sortData(data, SIZE);
    showData("\n정렬후", data, SIZE);

    reverse(data, SIZE);
    showData("\n역순 재배치", data, SIZE);

    //maxSort(data, SIZE);

    sortData(data, SIZE);
    showData("\n 정렬후", data, SIZE);

    int realData[] = { 5, 15, 99 };
    for (int newData : realData) {
        int* result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " : ";
        showData("\n실수 삽입후", result, SIZE + 1);
        delete[] result;
    }
    system("pause");
    return 0;
}
