#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    // my_string의 길이 + 1(널 종료 문자) 만큼 동적할당
    char* answer = (char*)malloc(sizeof(char) * (strlen(my_string) + 1));
    strcpy(answer, my_string); // my_string을 answer에 복사

    int overLength = strlen(overwrite_string); // overwrite_string의 길이
    // s부터 overwrite_length만큼 answer에 overwrite_string으로 덮어쓰기
    for (int i = 0; i < overLength; i++) {
        answer[s + i] = overwrite_string[i]; // 특정 위치에 문자 복사
    }
    return answer; // answer 반환
}

int main() {
    char* result = solution("He11oWor1d", "lloWorl", 2);
    printf("%s\n", result); // 결과 출력
    free(result); // 동적 메모리 해제
    return 0;
}