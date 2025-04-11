#include <string>
#include <vector>
using namespace std;

int solution(int num, int n, int m) {
    int answer = 0;

    if (num % n == 0 && num % m == 0){
            answer = 1; // num이 n과 m의 공배수인 경우
        } else {
            answer = 0;
        }
    
    
    return answer;
}

int main(){
    int result = solution(10, 2, 5); // 예시: num = 10, n = 2, m = 5
    printf("%d\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}


