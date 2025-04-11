#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int answer = 0; // 홀짝을 구분하기 위한 변수
    int isEven = 0; // 홀짝을 구분하기 위한 변수

    if(n % 2 == 0) { // n이 짝수인 경우
        isEven = 1; // 짝수이면 1 반환
    } else { // n이 홀수인 경우
        isEven = 0; // 홀수이면 0 반환
    }
    
    if(isEven == 0) { // 홀수인 경우
        for(int i = 1; i <= (n/2) + 1; i ++){
            answer += (2*i -1); // 홀수인 경우는 그냥 더함
        } 
    } else { // 짝수인 경우
        for(int i = 1; i < (n/2) + 1; i ++){
            answer += (2*i)*(2*i); // 짝수인 경우는 제곱을 더함
        } 
    }

    return answer;
}

int main(){
    int result = solution(1000); // 예시: n = 5
    printf("%d\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}