#include <iostream>
#include <cstring> // strcat, strcpy, strncpy, strstr

using namespace std;

// 서브스트링을 문자열 끝에 추가하는 함수
void addSubstring(char* base, const char* substring) {
    // base 문자열 끝에 substring을 이어 붙임
    strcat(base, substring);
}

// 문자열 교체 함수
// baseString에서 target 문자열을 찾아 replacement로 교체한 결과를 result에 저장
void replaceString(char* baseString, const char* target, const char* replacement, char* result) {
    char* pos = baseString;           // baseString 내에서 탐색할 시작 위치
    int targetLen = strlen(target);   // 교체할 대상 문자열의 길이
    result[0] = '\0';                 // 결과 문자열 초기화

    char* found = nullptr;
    // baseString에서 target이 발견될 때까지 반복
    while ((found = strstr(pos, target)) != nullptr) {
        // pos부터 target이 시작되기 전까지의 부분을 result에 추가
        strncat(result, pos, found - pos);
        // replacement 문자열을 result에 추가
        strcat(result, replacement);
        // pos를 target 문자열 끝으로 이동시킴
        pos = found + targetLen;
    }
    // 마지막으로 남은 부분을 result에 추가
    strcat(result, pos);
}

int main() {
    // 원본 문자열
    char s[100] = "자바 코딩, 파이썬 코딩, C 코딩, C# 코딩";
    char newString[150];   // 서브스트링 추가 후 저장할 공간
    char finalString[200]; // 문자열 교체 후 저장할 공간

    // 원본 문자열을 newString에 복사 후 서브스트링 추가
    strcpy(newString, s);
    addSubstring(newString, " PCCP 시험: 11월 23일");

    // newString에서 "코딩"을 "프로그래밍"으로 교체
    replaceString(newString, "코딩", "프로그래밍", finalString);

    // 결과 출력
    cout << finalString << endl;
    system("pause");
    return 0;
}
