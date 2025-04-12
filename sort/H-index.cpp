#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // std::sort

using namespace std;

/*
어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 
나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

이말은 즉, H-Index는 (논문 인용 횟수 = 논문의 갯수) 의 최댓값

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 
이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

제한사항
과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
논문별 인용 횟수는 0회 이상 10,000회 이하입니다.
입출력 예
citations	return
[3, 0, 6, 1, 5]	3 인용횟수
입출력 예 설명
이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 
그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.*/

//가장 

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size(); // 논문 개수
    int h = 0; // H-Index 초기화

    sort(citations.begin(), citations.end(), greater<int>()); // 인용 횟수를 내림차순으로 정렬

    for (int i = 0; i < size; i++) {
        if (citations[i] >= i + 1) { // 인용 횟수가 현재 인덱스 + 1 이상인 경우
            h = i + 1; // H-Index 업데이트
        } else {
            break; // 더 이상 H-Index를 증가시킬 수 없는 경우 종료
        }
    }

    answer = h; // 최종 H-Index 저장
    
    return answer;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5}; // 예시: 인용 횟수 배열
    int result = solution(citations); // H-Index 계산
    cout << result << endl; // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}