///*
// * PCCP �ڵ� ���迡�� ��Ʈ���� ���� �⺻ �Լ� ��� ������ �ʿ��ϴ�
// *
// */
// /*
//  char*�� cstring �Լ��� ����Ͽ� ���ڿ� ó��
// �κ� ���ڿ� �˻� strstr() ���
// ���ڿ� ���� �� strncmp() ���
// ���ڿ� �� �� strcmp() ���
// ���� ���� �� isdigit()�� �̿��� ���� ����
// */
//#include <iostream>
//#include <cstring> // strcmp, strstr, strncmp
//#include <cctype>  // isdigit
//
//using namespace std;
//
//// Ư�� ���ǿ� �´� ���ڿ��� ã�� ����ϴ� �Լ�
//void findStrings(char array[][50], int size, const char* keyword, const char* condition) {
//    for (int i = 0; i < size; i++) {
//        char* element = array[i];
//
//
//        if (strcmp(condition, "contains") == 0) {
//            //strstr�� ã������ ���ڿ��� ������ ó�� �����ϴ� ��ġ�� ������ ��ȯ, ���ٸ� null
//            char* pos = strstr(array[i], keyword);
//            if (pos) {
//                cout << array[i] << "\n";
//            }
//            else continue;
//        }
//        else if (strcmp(condition, "number") == 0) {
//            char result[50]="";
//            int idx = 0;
//            bool di = false;
//            for (int k = 0; array[i][k] != '\0'; k++) {
//                //isdigit() �Լ��� �ش� ���ڰ� ���������� ��ȯ
//                
//                //isdigit�� unsignd char�� �������� �ϴµ�, �̰� ������ ����ȯ �ʿ�!
//                if (isdigit(static_cast<unsigned char>(array[i][k]))) {
//                    result[idx++] += array[i][k];
//                    di = true;
//                   
//                }
//            }
//            if(di) cout << result << "\n";
//            //string�� ����Լ��� compare�� �ش� ���ڿ��̶� ���ٸ� 0�� ��ȯ
//            //c���ڿ��̱⿡ �η� ��������
//            result[idx] = '\0';
//            if (strcmp(result,keyword)==0) cout << array[i] << "\n";
//        }
//        else if (strcmp(condition, "startsWith") == 0) {
//            int size = strlen(keyword);
//            if (strncmp(array[i], keyword, size) == 0) cout << array[i] << "\n";
//        }
//        else if (strcmp(condition, "endsWith") == 0) {
//            size_t l1 = strlen(array[i]);
//            size_t l2 = strlen(keyword);
//
//            if (l1 < l2) continue;
//            if (strcmp(array[i] + (l1 - l2), keyword) == 0) cout << array[i] << "\n";
//        }
//        else {
//            cout << "Invalid condition." << endl;
//        }
//    }
//}
//
//int main() {
//    char address[][50] = {
//        "��⵵ ������ ������",
//        "����� �������� ��굿",
//        "�λ�� ������ ��õ��144",
//        "�泲 õ�Ƚ� ���ϱ�",
//        "�λ�� ������ ���굿",
//        "����� ���ı� ���̵�",
//        "���� �ξȱ� �ξ���",
//        "�λ�� ������ ������63"
//    };
//    int size = 8; // �迭 ũ��
//
//    // 1. "�λ��"�� �����ϴ� ���ڿ� ã��
//    cout << "1. Contains '�λ��':\n";
//    findStrings(address, size, "�λ��", "contains");
//
//    // 2. ���ڸ� �����Ͽ� ���
//    cout << "\n2. ���ڿ����� ���� ����:\n";
//    findStrings(address, size, "99", "number");
//
//    // 3. "�����"�� �����ϴ� ���ڿ� ã��
//    cout << "\n3. Starts with '�����':\n";
//    findStrings(address, size, "�����", "startsWith");
//
//    // 4. "���굿"���� ������ ���ڿ� ã��
//    cout << "\n4. Ends with '���굿':\n";
//    findStrings(address, size, "���굿", "endsWith");
//    system("pause");
//    return 0;
//}
