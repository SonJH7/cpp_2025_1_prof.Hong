////2-11. ragged.cpp: �ǽ� ���� 2.11
//// �����Ҵ� ���� 2���� �迭�� ��� 1���� �迭�� ���� ������ �� double pointer�� free�ؾ� ��.
//// raggedTable�� ġȯ�ϴ� ������ �ǽ� �ڵ�� �߰�
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
//
//void raggedTable2();
//void initializeRaggedArray(int**T1, int rows);
//void freeRaggedArray(int** T1, int rows);
//
//int main() {
//	int* T1[4];
//	int rows = 4;
//
//	srand(time(NULL));
//	initializeRaggedArray(T1, rows);
//
//	int cnt = 1;
//	printf("T1[][]�� ���� ��\n");
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cnt; j++) {
//			printf("%d ", T1[i][j]);
//		}
//		printf("\n");
//		cnt++;
//	}
//	printf("\n");
//
//	printf("**T1 = %d\n", **T1);
//	printf("**(T1+1) = %d\n", **(T1 + 1));
//	printf("*(*(T1+1)+1) = %d\n", *(*(T1 + 1) + 1));
//
//	freeRaggedArray(T1, rows);
//
//	raggedTable2();
//	system("pause");
//	return 0;
//}
//
//void initializeRaggedArray(int**T1, int rows) {
//	//T1 = (int**)malloc(rows * sizeof(int*));
//	for (int i = 0; i < rows; i++) {
//		T1[i] = (int*)malloc((i + 1) * sizeof(int));
//		// ptr = (int*)malloc(10 * sizeof(int));
//		//�ʱ�ȭ���� ���� (������ ��)
//
//		for (int j = 0; j < i + 1; j++) {
//			T1[i][j] = rand() % 100;
//		}
//	}
//}
//
//void freeRaggedArray(int** T1, int rows) {
//	for (int i = 0; i < rows; i++) {
//		free(T1[i]);
//	}
//	//free(T1);
//}
//
//void raggedTable2() {
//	char** T3;
//	int row, col;
//	int rowIndex;
//	static char counter = 'A';
//	printf("���� ���� �Է� :");
//	scanf("%d", &row);
//	T3 = (char**)calloc(row, sizeof(char*));
//	for (rowIndex = 0; rowIndex < row; rowIndex++) {
//		printf("%d�࿡ ���� ���� �� : ", rowIndex);
//		scanf("%d", &col);
//		T3[rowIndex] = (char*)calloc(col + 1, sizeof(char));
//		//ptr = (int*)calloc(10, sizeof(int));
//		//0���� �ʱ�ȭ
//
//		for (int j = 0; j < col; j++) {
//			T3[rowIndex][j] = counter++;
//			printf("%d ", T3[rowIndex][j]);
//		}
//		printf("\n");
//	}
//	for (rowIndex = 0; rowIndex < row; rowIndex++) {
//		free(T3[rowIndex]);
//	}
//	free(T3);
//}
