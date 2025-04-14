#include <string>

using namespace std;

int solution(int a, int b) {

    int answer = 0;
    string strA = to_string(a); // a를 문자열로 변환
    string strB = to_string(b); // b를 문자열로 변환

    string temp = ""; // 임시 문자열
    temp += strA; // 문자열을 이어붙임
    strA += strB; // 문자열을 이어붙임
    strB += temp; // 문자열을 이어붙임

    a = stoi(strA); // 문자열을 정수로 변환
    b = stoi(strB); // 문자열을 정수로 변환

    return max(a, b); // 두 정수 중 큰 값을 반환
}

int main() {
    int result = solution(9, 91); // 예시: a = 9, b = 91
    printf("%d\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}