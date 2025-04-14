/*
섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 
solution 함수를 작성해주세요.
[1, 2, 3, 9, 10, 12]	7	2
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue> // std::priority_queue

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());
    int mixCount = 0;
    
    while (minHeap.size() > 1 && minHeap.top() < K) {
        int leastSpicy = minHeap.top();
        minHeap.pop();
        int secondLeastSpicy = minHeap.top();
        minHeap.pop();
        
        int newScoville = leastSpicy + (secondLeastSpicy * 2);
        minHeap.push(newScoville);
        mixCount++;
    }
    
    if (minHeap.top() < K) {
        return -1;
    }
    
    return mixCount;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12, 4, 6, 25, 110}; // 예시: 스코빌 지수 배열
    int K = 50; // 원하는 스코빌 지수
    int result = solution(scoville, K); // 섞은 횟수 계산
    cout << result << endl; // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}