///*
//* ������ �迭 ó�� �Լ� ����
//*/
//
////2���� �迭�� �Լ� �Ű������� ���� ��, �� ũ�⸦ �ݵ�� �����ؾ� ��.
////-> ������ ��� ����� �°Բ� �Լ��� ������ ����
////-> ���� ���� �����. �ذ���� ���ø� Ȥ�� ������..
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
//// ��� ���� - ���� �����Ϳ� ���� ���ذ� �ʿ� => chap 2
//int** addMatrix2(int X[][COLS_A], int Y[][COLS_A], int rows, int cols) {
//    int** Z = new int* [rows]; //�����Ϳ� �ุŭ�� ������
//    for (int i = 0; i < rows; i++) {
//        Z[i] = new int[cols]; //���࿡ ����ŭ�� ������
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
////�Լ� ���ڰ� ���� �����ʹϱ� �Ű������� ���� �����ͷ�.
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
////��� �� ������ ���� �� ������ �� ���ϰ� ���ϸ� �ȴ�.
//void multiplyMatrix(int dataA[][COLS_A], int dataB[][COLS_B], int dataC[][COLS_B], int rows, int cols, int colsb) {
//    //int k;
//    ////�� ū�� ó�� �ݺ����� ��������.
//    //if (rows > colsb) k = rows;
//    //else k = colsb;
//    //
//    //
//    //for (int i = 0; i < k; i++) {
//    //    int num = 0;
//    //    for (int j = 0; j < cols; j++) {
//    //        //���̳� ���� �Ѿ�ٸ� �ݺ� ����
//    //        //��� �ʱ�ȭ
//    //        dataC[i][j] = 0;
//    //        if (i >= rows || i >= colsb) break;
//    //        else num += dataA[i][j] * dataB[j][i];
//    //        //���ʿ����� ������ ��� ��* �����ʿ����� ������ ��� ��
//    //    }
//
//    //}
//
////���� �ݺ�!
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
//    srand(time(0)); // ���� �ʱ�ȭ
//
//    int A[ROWS_A][COLS_A]; // 2x3 ���
//    int B[ROWS_B][COLS_B]; // 3x4 ���
//    int C[ROWS_A][COLS_B]; // 2x4 ���
//    int D[ROWS_A][COLS_A]; // 2x3 ���� ���
//    int E[ROWS_A][COLS_A]; // ���� ��� ���
//    int F[COLS_B][ROWS_B]; // ��ġ ���
//    int G[ROWS_A][COLS_B]; // ��ġ ��� Ȱ�� ���� ���
//
//
//    //inputData(A, ROWS_A, ROWS_A);
//    //inputData(B, ROWS_B, ROWS_B);
//    inputDataA(A, ROWS_A);
//    inputDataB(B, ROWS_B);
//
//    // �迭 ���� (���� ����)
//    for (int i = 0; i < ROWS_A; i++)
//        for (int j = 0; j < COLS_A; j++)
//            D[i][j] = A[i][j];
//
//    cout << "A[2][3] = \n";
//    //showData("��� A", A, ROWS_A, COLS_A);
//    showDataA("��� A", A, ROWS_A);
//
//    cout << "D[2][3] = \n";
//   // showData("��� D", D, ROWS_A, COLS_A);
//    showDataA("��� D", D, ROWS_A);
//
//    cout << "B[3][4] = \n";
//    //showData("��� B", B, ROWS_B, COLS_B);
//    showDataB("��� B", B, ROWS_B);
//
//    //addMatrix(A, D, E, ROWS_A, COLS_A);
//    addMatrix(A, D, E, ROWS_A);
//    cout << "E[2][3] = \n";
//    //showData("��� E", E, ROWS_A, COLS_A);
//    showDataA("��� E", E, ROWS_A);
//
//    int** H = addMatrix2(A, D, ROWS_A, COLS_A);
//    cout << "H[2][3] = \n";
//    showData2("��� H", H, ROWS_A, COLS_A);
//
//    multiplyMatrix(A, B, C, ROWS_A, COLS_A, COLS_B);
//    cout << "C[2][4] = \n";
//    //showData("��� C", C, ROWS_A, COLS_B);
//    showDataB("��� C", C, ROWS_A);
//
//    transposeMatrix(B, F, ROWS_B, COLS_B);
//    cout << "F[4][3] = \n";
//    //showData("��� F (B�� ��ġ)", F, COLS_B, ROWS_B);
//    showDataA("��� F (B�� ��ġ)", F, COLS_B);
//
//    //2x3����̶� 4x3����� ����,,, ���� �Ұ���
//   /* multiplyMatrixTransposed(A, F, G, ROWS_A, COLS_A, COLS_B);
//    cout << "G[2][4] (��ġ ����� Ȱ���� ���� ���) = \n";
//    showData("��� G", G, ROWS_A, COLS_B);*/
//
//    if (equals(A, D, ROWS_A, COLS_A))
//        cout << "��� A�� D�� �����մϴ�.\n";
//    else
//        cout << "��� A�� D�� �������� �ʽ��ϴ�.\n";
//    system("pause");
//    return 0;
//}
