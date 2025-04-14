#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;

    int n = included.size(); // 포함된 원소의 개수
    int current = a - d;
    for (int i = 0; i < n; i ++){
        current += d;
        if (included[i]){
            answer += current; // 포함된 원소의 합을 계산
        }
    }
    return answer;
}