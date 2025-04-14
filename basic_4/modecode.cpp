#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    bool mode = false; // 0: idx가 짝수일 때 해독, 1: idx가 홀수일 때 해독
    string answer = "";

    for(int i = 0; i < code.size(); i++) {
        if (code[i] == '1') {
            mode = !mode; // 모드 전환
            continue;
        }
        if (mode) { //mode가 1일때
            if (i % 2 == 1) {
                answer += code[i]; // 홀수 인덱스의 문자 추가
            }
        } else { // mode가 0일때
            if (i % 2 == 0) {
                answer += code[i]; // 짝수 인덱스의 문자 추가
            }
        }
    }

    if (answer.empty()) {
        return "EMPTY"; // 해독된 문자열이 없으면 "EMPTY" 반환
    }
    
    return answer;
}