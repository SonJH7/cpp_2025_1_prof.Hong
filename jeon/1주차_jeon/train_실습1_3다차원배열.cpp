///*
//* 다차원 배열 처리 함수 구현
//*/
//
////2차원 배열을 함수 매개변수로 받을 때, 열 크기를 반드시 고정해야 됨.
////-> 각각의 행렬 사이즈에 맞게끔 함수를 여러개 정의
////-> 좋지 않은 방식임. 해결법은 템플릿 혹은 포인터..
//#include <iostream>
//#include <cstdlib>  // rand()
//#include <ctime>    // time()
//
//#define ROWS_A 2
//#define COLS_A 3
//#define ROWS_B 3
//#define COLS_B 4
//
//using namespace std;
//
//
//
//
//// 행렬 덧셈 - 이중 포인터에 대한 이해가 필요 => chap 2
//int** addMatrix2(int X[][COLS_A], int Y[][COLS_A], int rows, int cols) {
//    int** Z = new int* [rows]; //포인터에 행만큼의 사이즈
//    for (int i = 0; i < rows; i++) {
//        Z[i] = new int[cols]; //각행에 열만큼의 사이즈
//        for (int j = 0; j < cols; j++) {
//            Z[i][j] = X[i][j] + Y[i][j];
//        }
//    }
//    return Z;
//}
//
//void inputDataA(int data[][COLS_A], int rows) {
//    srand(time(0));
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < COLS_A; j++) {
//            data[i][j] = rand() % 10;
//        }
//    }
//
//}
//
//void inputDataB(int data[][COLS_B], int rows) {
//    srand(time(0));
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < COLS_B; j++) {
//            data[i][j] = rand() % 10;
//        }
//    }
//
//}
//
//void showDataA(string s, int data[][COLS_A], int rows) {
//    cout << s << "\n";
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < COLS_A; j++) {
//            cout << data[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}
//
//
//void showDataB(string s, int data[][COLS_B], int rows) {
//    cout << s << "\n";
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < COLS_B; j++) {
//            cout << data[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}
//
//
////void inputData(int data[][10], int rows, int cols) {
////    srand(time(0));
////    for (int i = 0; i < rows; i++) {
////        for (int j = 0; j < cols; j++) {
////            data[i][j] = rand() % 10;
////        }
////    }
////}
//
//void addMatrix(int data[][COLS_A], int data1[][COLS_A], int data2[][COLS_A], int rows) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < COLS_A; j++) {
//            data2[i][j] = data[i][j] + data1[i][j];
//        }
//    }
//}
//
////함수 인자가 이중 포인터니까 매개변수도 이중 포인터로.
//void showData2(string s,int** data, int rows, int cols) {
//    cout << s << "\n";
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << data[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}
//
////행렬 곱 연산은 왼쪽 행 오른쪽 열 곱하고 더하면 된다.
//void multiplyMatrix(int dataA[][COLS_A], int dataB[][COLS_B], int dataC[][COLS_B], int rows, int cols, int colsb) {
//    //int k;
//    ////더 큰걸 처음 반복문의 기준으로.
//    //if (rows > colsb) k = rows;
//    //else k = colsb;
//    //
//    //
//    //for (int i = 0; i < k; i++) {
//    //    int num = 0;
//    //    for (int j = 0; j < cols; j++) {
//    //        //행이나 열을 넘어간다면 반복 종료
//    //        //행렬 초기화
//    //        dataC[i][j] = 0;
//    //        if (i >= rows || i >= colsb) break;
//    //        else num += dataA[i][j] * dataB[j][i];
//    //        //왼쪽에서는 각행의 모든 열* 오른쪽에서는 각열의 모든 행
//    //    }
//
//    //}
//
////삼중 반복!
//    for (int i = 0; i < rows; i++) {
//       
//        for (int j = 0; j < colsb; j++) {
//            int num = 0;
//            for (int k = 0; k < cols; k++) {
//                num += dataA[i][k] * dataB[k][j];
//            }
//            dataC[i][j] = num;
//        }
//
//    }
//
//
//
//}
//
//void transposeMatrix(int dataB[][COLS_B], int dataF[][ROWS_B], int rows, int cols) {
//    for (int i = 0; i < cols; i++) {
//        for (int j = 0; j < rows; j++) {
//            dataF[i][j] = dataB[j][i];
//        }
//    }
//}
//bool equals(int dataA[][COLS_A], int dataD[][COLS_A], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (dataA[i][j] == dataD[i][j]) continue;
//            else return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    srand(time(0)); // 난수 초기화
//
//    int A[ROWS_A][COLS_A]; // 2x3 행렬
//    int B[ROWS_B][COLS_B]; // 3x4 행렬
//    int C[ROWS_A][COLS_B]; // 2x4 행렬
//    int D[ROWS_A][COLS_A]; // 2x3 복제 행렬
//    int E[ROWS_A][COLS_A]; // 덧셈 결과 행렬
//    int F[COLS_B][ROWS_B]; // 전치 행렬
//    int G[ROWS_A][COLS_B]; // 전치 행렬 활용 곱셈 결과
//
//
//    //inputData(A, ROWS_A, ROWS_A);
//    //inputData(B, ROWS_B, ROWS_B);
//    inputDataA(A, ROWS_A);
//    inputDataB(B, ROWS_B);
//
//    // 배열 복제 (수동 복사)
//    for (int i = 0; i < ROWS_A; i++)
//        for (int j = 0; j < COLS_A; j++)
//            D[i][j] = A[i][j];
//
//    cout << "A[2][3] = \n";
//    //showData("행렬 A", A, ROWS_A, COLS_A);
//    showDataA("행렬 A", A, ROWS_A);
//
//    cout << "D[2][3] = \n";
//   // showData("행렬 D", D, ROWS_A, COLS_A);
//    showDataA("행렬 D", D, ROWS_A);
//
//    cout << "B[3][4] = \n";
//    //showData("행렬 B", B, ROWS_B, COLS_B);
//    showDataB("행렬 B", B, ROWS_B);
//
//    //addMatrix(A, D, E, ROWS_A, COLS_A);
//    addMatrix(A, D, E, ROWS_A);
//    cout << "E[2][3] = \n";
//    //showData("행렬 E", E, ROWS_A, COLS_A);
//    showDataA("행렬 E", E, ROWS_A);
//
//    int** H = addMatrix2(A, D, ROWS_A, COLS_A);
//    cout << "H[2][3] = \n";
//    showData2("행렬 H", H, ROWS_A, COLS_A);
//
//    multiplyMatrix(A, B, C, ROWS_A, COLS_A, COLS_B);
//    cout << "C[2][4] = \n";
//    //showData("행렬 C", C, ROWS_A, COLS_B);
//    showDataB("행렬 C", C, ROWS_A);
//
//    transposeMatrix(B, F, ROWS_B, COLS_B);
//    cout << "F[4][3] = \n";
//    //showData("행렬 F (B의 전치)", F, COLS_B, ROWS_B);
//    showDataA("행렬 F (B의 전치)", F, COLS_B);
//
//    //2x3행렬이랑 4x3행렬의 곱은,,, 존재 불가능
//   /* multiplyMatrixTransposed(A, F, G, ROWS_A, COLS_A, COLS_B);
//    cout << "G[2][4] (전치 행렬을 활용한 곱셈 결과) = \n";
//    showData("행렬 G", G, ROWS_A, COLS_B);*/
//
//    if (equals(A, D, ROWS_A, COLS_A))
//        cout << "행렬 A와 D는 동일합니다.\n";
//    else
//        cout << "행렬 A와 D는 동일하지 않습니다.\n";
//    system("pause");
//    return 0;
//}
