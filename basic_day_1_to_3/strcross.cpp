#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.



    int length = strlen(str1);

    char* answer = (char*)malloc(length * 2 + 1);
    char* fisrtStr = (char*)malloc(length);
    char* secondStr = (char*)malloc(length);

    strcpy(fisrtStr, str1);
    strcpy(secondStr, str2);


    //문제풀이
    for(int i = 0; i < length; i++){
        answer[2*i] = str1[i];
        answer[2*i + 1] = str2[i];
    }

    answer[length * 2] = '\0'; // 문자열의 끝을 표시

    return answer;
}

int main(){
    const char* str1 = "abcde";
    const char* str2 = "12345";
    // 예시: str1 = "abcde", str2 = "12345"
    char* result = solution(str1, str2);
    printf("%s\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    free(result); // 동적 할당한 메모리 해제
    return 0;
}