/*
입출력 예시 [[0, 3], [1, 9], [3, 5]]	8
작업번호, 요청시간, 작업종료시각, 반환시간

요청이 들어오면 큐에 넣고,
큐에 있는 작업을 작업시간으로 정렬하여
반환시간을 계산하여
큐에서 꺼낸다.
반환시간의 평균을 계산하기 위한 변수는 작업갯수n, 반환시간의 합 sum을 사용한다.
작업이 끝나면 sum에 반환시간을 더하고 n을 증가시킨다.
*/
#include <string>
#include <vector>
#include <queue> // std::priority_queue
#include <iostream>
#include <algorithm> // std::sort

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // 작업시간이 같으면 요청시간이 빠른 순서로 정렬
        }
        return a.first > b.first; // 작업시간으로 정렬
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size(); // 작업의 개수

    vector<pair<int, int>> jobList; // 작업 큐 (요청시간, 작업시간)
    for (int i = 0; i < n; i++) {
        jobList.push_back({ jobs[i][0], jobs[i][1] });
    }
    sort(jobList.begin(), jobList.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // 작업 큐 (작업시간, 요청시간)
    int currentTime = 0; // 현재시간 (요청시간)
    int totalTurnaroundTime = 0;
    int index = 0;
    int completedJobs = 0;
    int sum = 0; // 반환시간의 합

    while (completedJobs < jobList.size()) { // 모든 작업이 끝날 때까지 반복
        
        

        while (index < n && jobList[index].first <= currentTime) {
            pq.push({ jobList[index].second, jobList[index].first }); // 작업시간, 요청시간 순으로 큐에 넣는다.
            index++;
        };

        if (!pq.empty()) {
            pair<int, int> job = pq.top(); // 작업을 꺼낸다.
            pq.pop(); // 큐에서 제거한다.
            currentTime += job.first; // 현재시간에 작업시간을 더한다.
            sum += (currentTime - job.second); // 반환시간을 더한다.
            completedJobs++; // 작업이 끝났으므로 증가시킨다.
        } 
        else if (index < n) { // 큐가 비어있고, 아직 작업이 남아있다면
            currentTime = jobList[index].first ; // 현재시간을 요청시간으로 설정한다.
        };

    };

    return sum / n; // 반환시간의 평균을 계산하기 위한 변수는 작업갯수n, 반환시간의 합 sum을 사용한다.
}

int main() {
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2,6} };
    int result = solution(jobs);
    cout << "Average Turnaround Time: " << result << endl; // 평균 반환시간을 출력한다.
    getchar();
    return 0;
}


