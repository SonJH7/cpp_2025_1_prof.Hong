//4장-4. POINTER_ARRAY2.cpp    4.3 pointer 변수와 reference 변수
#include <iostream>
//times()을 2배 곱하기로 변경
using namespace std;
#define ROWS 2
#define COLS 3
int times(int (&)[ROWS][COLS], int row);
int times2(int (*t)[COLS], int row);//pointer-to-array
int show(int(&)[ROWS][COLS], int row);
int show2(int(*t)[COLS], int row);//pointer-to-array
void main(void){
	int num[2][3] ={{1, 2, 3}, {4, 5, 6}};
	cout<<"times()::"<<endl;
	int total = times(num, 2);
	show(num, 2);
	cout << "toal = " << total << endl;
	cout<<"times2()::"<<endl;
	times2(num, 2);
	show2(num, 2);
	system("pause");
}
int times(int (&t)[ROWS][COLS], int row)//how to pass 2D array as reference
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			total += t[i][j];//t를 pointer로 사용
			t[i][j] *= 2;
		}
	}
	return total;
}
int times2(int (*t)[COLS], int row)//how to pass 2D array as pointer
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
			(*t)[j] *= 2;
				//(*t)[j] += t[i][j];//t는 배열로 사용 가능
			t++;
	}
	return total;

}
int show(int(&t)[ROWS][COLS], int row)//how to pass 2D array as reference
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << " " << t[i][j];
		}
		cout << endl;
	}
	return total;
}
int show2(int(*t)[COLS], int row)//how to pass 2D array as pointer
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << " " << (*t)[j];//t는 배열로 사용 가능
		t++;
		cout << endl;
	}
	return total;
}

//4장-6. ReferenceExample.cpp   4.4.3 reference에 의한 함수 parameter 전달
#include <iostream>
using namespace std;
void swap(int value_a, int value_b); //call by value
void swap(int *pointer_a, int *pointer_b); //call by pointer
void swap_ref(int &reference_a, int &reference_b); //call by reference
//void swap(int& reference_a, int& reference_b); // 오류 발생함
void main(){
    int num_1 = 10, num_2 = 20;
    cout << "call by value" << endl;
    swap (num_1, num_2);
    cout << "after swap (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

    cout << endl << "call by pointer" << endl;
	swap (&num_1, &num_2); 
	cout << "after swap (&num_1, &num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;
	num_1 = 10; num_2 = 20;

    cout << endl << "call by reference" << endl;
    swap_ref (num_1, num_2); 
	cout << "after swap_ref (num_1, num_2)::num_1 = " << num_1 
		<< ", num_2 = "<< num_2<<endl;

	system("pause");
}


void swap(int value_a, int value_b){
    cout << "swap(int,int) ";
    int temp;
    temp = value_a;
    value_a = value_b;
    value_b = temp;
}

void swap(int *pointer_a, int *pointer_b){
    cout << "swap(int*, int*) ";
    int temp;
    temp = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temp;
}

void swap_ref(int &reference_a, int &reference_b){
    cout << "swap_ref(int&, int&) ";
    int temp;
    temp = reference_a;
    reference_a = reference_b;
    reference_b = temp;
}