#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;

    // ineq와 eq에 따라 비교 연산을 수행
    if (ineq == "<") {
        if (eq == "=") {
            answer = (n <= m) ? 1 : 0; // n이 m보다 작거나 같은 경우
        } else {
            answer = (n < m) ? 1 : 0; // n이 m보다 작은 경우
        }
    } else if (ineq == ">") {
        if (eq == "=") {
            answer = (n >= m) ? 1 : 0; // n이 m보다 크거나 같은 경우
        } else {
            answer = (n > m) ? 1 : 0; // n이 m보다 큰 경우
        }
    }
    return answer;
}