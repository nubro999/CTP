#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    char* answer = (char*)malloc(strlen(my_string)*k + 1);

    int stlen = strlen(my_string); // my_string의 길이

    //인덱스 my_string의 배수위치에 answer에 my_string을 붙여넣기

    for(int i = 0; i < k; i++){
        for(int j = 0; j < stlen; j++){
            answer[i*stlen + j] = my_string[j]; // 특정 위치에 문자 복사
        }
    }
    answer[strlen(my_string)*k] = '\0'; // 문자열의 끝을 표시

    return answer;
}

int main() {
    char* result = solution("abc", 3); // 예시: my_string = "abc", k = 3
    printf("%s\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    free(result); // 동적 메모리 해제
    return 0;
}