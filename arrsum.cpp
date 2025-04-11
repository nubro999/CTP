#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(arr_len * 2 + 1);
    char* character = (char*)malloc(1);

    for(int i = 0; i < arr_len; i++){
        answer[i] = arr[i][0];
    }
    answer[arr_len] = '\0'; // 문자열의 끝을 표시
    return answer;
}

int main(){
    const char* arr[] = {"abc", "def", "ghi"};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    // 예시: arr = {"abc", "def", "ghi"}
    char* result = solution(arr, arr_len);
    printf("%s\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    free(result); // 동적 할당한 메모리 해제

    return 0;
}