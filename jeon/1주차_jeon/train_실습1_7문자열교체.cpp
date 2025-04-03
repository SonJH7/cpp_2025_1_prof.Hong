/*
strstr()�� "string search" �Ǵ� **"string string"**�� ����
*/

#include <iostream>
#include <cstring>  // strcat, strcpy, strncpy, strstr

using namespace std;



// ���ڿ� ��ü �Լ� 
void replaceString(char* baseString, const char* target, const char* replacement, char* result) {
    char* pos = baseString;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    result[0] = '\0';  // ��� ���ڿ� �ʱ�ȭ

    //���� ��ġ ã��
    char* start = strstr(baseString, target);
    int sl = strlen(baseString);
    while (start) {
        /*if (replacementLen <= targetLen) {
            memmove(start + replacementLen, start + targetLen, sl - (start - baseString) - targetLen + 1);
        }
        else {
            memmove(start + replacementLen, start + targetLen, sl - (start - baseString) - targetLen + 1);
        }

        memcpy(start, replacement, replacementLen);

        start = strstr(start + replacementLen, target);*/

        strncat(result, baseString, baseString - start);
        strcat(result, replacement);
        baseString = start + targetLen;
        start = strstr(baseString,target);



    }
    

}

void addSubstring(char* c, string s){
    if(strlen(c)+strlen(s.data())+1<sizeof(c))
    strcat(c, s.data());
    
}

int main() {
    char s[100] = "�ڹ� �ڵ�, ���̽� �ڵ�, C �ڵ�, C# �ڵ�"; // ���� ���ڿ�
    char newString[150];  // ���ڿ� �߰� �� ������ ����
    char finalString[200];  // ���ڿ� ��ü �� ������ ����

    // ���꽺Ʈ�� �߰�
    strcpy(newString, s);  // ���� ����
    addSubstring(newString, " PCCP ����: 11�� 23��");

    // ���ڿ� ��ü
    replaceString(newString, "�ڵ�", "���α׷���", finalString);

    // ��� ���
    cout << finalString << endl;
    system("pause");
    return 0;
}
