#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 4

using namespace std;

// 템플릿을 사용하여 열의 크기에 관계없이 2차원 배열에 난수를 입력하는 함수
template <size_t COLS>
void inputData(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = (rand() % 51) + 10;  // 10 ~ 60 사이의 난수
        }
    }
}

// 템플릿을 사용하여 2차원 배열의 내용을 출력하는 함수
template <size_t COLS>
void showData(const string &msg, int matrix[][COLS], int rows, int cols) {
    cout << msg << ":\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}

// 이중 포인터(int**)를 이용한 2차원 배열 출력 함수 (동적 할당된 배열에 사용)
void showData2(const string &msg, int** data, int rows, int cols) {
    cout << msg << ":\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}

// 행렬 덧셈 (정적 배열 버전): X와 Y를 더해 Z에 저장 (행과 열의 크기가 동일해야 함)
template <size_t COLS>
void addMatrix(int X[][COLS], int Y[][COLS], int Z[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
}

// 행렬 덧셈 - 이중 포인터 버전
// X와 Y (크기 rows x COLS_A)를 더한 결과를 동적 할당한 2차원 배열에 저장 후 반환
int** addMatrix2(int X[][COLS_A], int Y[][COLS_A], int rows, int cols) {
    int** Z = new int*[rows];  // 행 개수만큼 int* 배열 할당
    for (int i = 0; i < rows; i++) {
        Z[i] = new int[cols];  // 각 행에 대해 열 크기만큼 int 배열 할당
        for (int j = 0; j < cols; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
    return Z;
}

// 행렬 곱셈: A (ROWS_A x COLS_A) * B (ROWS_B x COLS_B) = C (ROWS_A x COLS_B)
// A와 B의 곱셈은 A의 열 수와 B의 행 수가 동일해야 함
void multiplyMatrix(int A[][COLS_A], int B[][COLS_B], int C[][COLS_B], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++){
        for (int j = 0; j < colsB; j++){
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 행렬 전치: B (ROWS_B x COLS_B)의 전치행렬 F (COLS_B x ROWS_B) 생성
void transposeMatrix(int B[][COLS_B], int F[][ROWS_B], int rowsB, int colsB) {
    for (int i = 0; i < rowsB; i++){
        for (int j = 0; j < colsB; j++){
            F[j][i] = B[i][j];
        }
    }
}

// 전치 행렬을 활용한 행렬 곱셈: A (ROWS_A x COLS_A) * B = G (ROWS_A x COLS_B)
// 여기서는 B의 전치 F (COLS_B x ROWS_B)를 활용하여 계산 (F[j][k] = B[k][j])
void multiplyMatrixTransposed(int A[][COLS_A], int F[][ROWS_B], int G[][COLS_B], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++){
        for (int j = 0; j < colsB; j++){
            G[i][j] = 0;
            for (int k = 0; k < colsA; k++){
                G[i][j] += A[i][k] * F[j][k];
            }
        }
    }
}

// 행렬 비교: 두 2차원 배열 A와 D가 동일하면 true, 아니면 false 반환
template <size_t COLS>
bool equals(int A[][COLS], int D[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (A[i][j] != D[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    srand(time(0)); // 난수 초기화

    int A[ROWS_A][COLS_A]; // 2x3 행렬
    int B[ROWS_B][COLS_B]; // 3x4 행렬
    int C[ROWS_A][COLS_B]; // 2x4 행렬 (곱셈 결과)
    int D[ROWS_A][COLS_A]; // 2x3 복제 행렬 (A의 복사본)
    int E[ROWS_A][COLS_A]; // 덧셈 결과 행렬
    int F[COLS_B][ROWS_B]; // 전치 행렬 (B의 전치: 4x3)
    int G[ROWS_A][COLS_B]; // 전치 행렬을 활용한 곱셈 결과

    // 행렬 A와 B에 난수 입력
    inputData(A, ROWS_A, COLS_A);
    inputData(B, ROWS_B, COLS_B);

    // 배열 복제: A를 D에 복사
    for (int i = 0; i < ROWS_A; i++)
        for (int j = 0; j < COLS_A; j++)
            D[i][j] = A[i][j];

    cout << "A[2][3] =\n";
    showData("행렬 A", A, ROWS_A, COLS_A);

    cout << "D[2][3] =\n";
    showData("행렬 D", D, ROWS_A, COLS_A);

    cout << "B[3][4] =\n";
    showData("행렬 B", B, ROWS_B, COLS_B);

    // 행렬 덧셈 (정적 배열 버전)
    addMatrix(A, D, E, ROWS_A, COLS_A);
    cout << "E[2][3] =\n";
    showData("행렬 E", E, ROWS_A, COLS_A);

    // 행렬 덧셈 (이중 포인터 버전)
    int** H = addMatrix2(A, D, ROWS_A, COLS_A);
    cout << "H[2][3] =\n";
    showData2("행렬 H", H, ROWS_A, COLS_A);

    // 동적 할당된 2차원 배열 H 해제
    for (int i = 0; i < ROWS_A; i++) {
        delete[] H[i];
    }
    delete[] H;

    // 행렬 곱셈: A(2x3) * B(3x4) = C(2x4)
    multiplyMatrix(A, B, C, ROWS_A, COLS_A, COLS_B);
    cout << "C[2][4] =\n";
    showData("행렬 C", C, ROWS_A, COLS_B);

    // 행렬 B의 전치 계산: B(3x4) -> F(4x3)
    transposeMatrix(B, F, ROWS_B, COLS_B);
    cout << "F[4][3] =\n";
    showData("행렬 F (B의 전치)", F, COLS_B, ROWS_B);

    // 전치 행렬을 활용한 행렬 곱셈: A(2x3) * B = G(2x4)
    multiplyMatrixTransposed(A, F, G, ROWS_A, COLS_A, COLS_B);
    cout << "G[2][4] (전치 행렬을 활용한 곱셈 결과) =\n";
    showData("행렬 G", G, ROWS_A, COLS_B);

    // 행렬 A와 D 비교
    if (equals(A, D, ROWS_A, COLS_A))
        cout << "행렬 A와 D는 동일합니다.\n";
    else
        cout << "행렬 A와 D는 동일하지 않습니다.\n";

    system("pause");
    return 0;
}
