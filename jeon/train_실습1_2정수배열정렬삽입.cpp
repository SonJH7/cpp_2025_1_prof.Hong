#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
//������ 10 ~ 60 ���̿� ����
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


//�ε��� �޾ƿͼ� �ٲٱ�
void swap(int arr[], int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

//�������� ����
void sortData(int data[], int size) {
    //��������
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (data[i] >= data[j]) swap(data, i, j);
        }
    }
}

//���� ���ġ
void reverse(int data[], int size) {
    //�Ǿհ� �ǵڸ� ������� swap
    for (int i = 0; i < (size / 2); i++) {
        swap(data, i, size - 1 - i);
    }
}

/*
 * ���̵��� �ſ� ���� �˰��� ����
 * ���ĵ� ���� �迭�� ���� ���� �߰��ϴ� �˰��� > �� �迭�� ũ��� ���� �迭���� +1�� ����� ���� �迭�� copy�� ��
 * ���Ե� ���� �߰��� ���� �˰��� �����ϱ�
 * O(n) �˰������� ����
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[size + 1];// �Լ� �����Ŀ��� ���� �־� delete[] �ʿ�
    int idx=0;
    bool find_idx = false;
    bool ist = false;
    
    
    
    //�� �տ� ����ֱ�
    if (data[0] > value) {
        newData[0] = value;
        for (int i = 0; i < size; i++) {
            newData[i + 1] = data[i];
        }
    }
    //�� ���� ����ֱ�
    else if (data[size - 1] < value) {
        newData[size] = value;
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
    }

    //�߰��� ����ֱ�
    else {
        for (int i = 0; i < size; i++) {
            //data[] ���鼭 value�� �� ��ġ ã��
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
                //���� ��ġ �������� �Ȱ��� �ֱ�
                if (i < idx + 1) newData[i] = data[i];
                //�ְ� ������ ��ĭ�ڿ� �ֱ�
                else if (i > idx + 1)newData[i + 1] = data[i];
            }

        }
    }
    return newData;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE);
    showData("\n���� �Է�", data, SIZE);

    sortData(data, SIZE);
    showData("\n������", data, SIZE);

    reverse(data, SIZE);
    showData("\n���� ���ġ", data, SIZE);

    //maxSort(data, SIZE);

    sortData(data, SIZE);
    showData("\n ������", data, SIZE);

    int realData[] = { 5, 15, 99 };
    for (int newData : realData) {
        int* result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " : ";
        showData("\n�Ǽ� ������", result, SIZE + 1);
        delete[] result;
    }
    system("pause");
    return 0;
}
