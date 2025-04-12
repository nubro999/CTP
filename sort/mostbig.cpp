using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 사용자 정의 비교 함수
bool compare(const string& a, const string& b) {
    return a + b > b + a; 
} 

string solution(vector<int> numbers) {
    vector<string> numStrs;
    
    // 숫자를 문자열로 변환
    for (int num : numbers) {
        numStrs.push_back(to_string(num));
    }
    
    // 사용자 정의 정렬
    sort(numStrs.begin(), numStrs.end(), compare);
    
    // 결과 문자열 생성
    string answer;
    for (const string& numStr : numStrs) {
        answer += numStr;
    }
    
    // "0000..." 같은 경우 "0"으로 변환
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}

int main() {
    vector<int> numbers = {6,1,40,200546, 990000};
    string result = solution(numbers);
    cout << result << endl; // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}