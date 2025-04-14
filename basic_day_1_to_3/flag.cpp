#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;

    // flag가 true인 경우 a + b를 반환
    if (flag) {
        answer = a + b;
    } else { // flag가 false인 경우 a - b를 반환
        answer = a - b;
    }
    return answer;
}