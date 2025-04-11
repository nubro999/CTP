#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;

    int c = 2 * a * b;

    string strA = to_string(a); // a를 문자열로 변환
    string strB = to_string(b); // b를 문자열로 변환

    strA += strB; // 문자열을 이어붙임

    a = stoi(strA); // 문자열을 정수로 변환

    answer = max(a, c); // 두 정수 중 큰 값을 반환

    return answer;
}

int main(){
    int result = solution(2, 34); // 예시: a = 9, b = 91
    printf("%d\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}