#include <string>
#include <vector>
#include <queue> // std::priority_queue
#include <iostream>


using namespace std;



vector<int> solution(vector<string> operations) {
    vector<int> answer;
    // maxHeap, minHeap을 사용하여 최대값과 최소값을 관리한다.
    // maxHeap은 우선순위 큐를 사용하여 최대값을 관리하고, minHeap은 최소값을 관리한다.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'I'){
            int num = stoi(operations[i].substr(2));
            minHeap.push(num);
        } else if(operations[i][0] == 'D'){
            if(operations[i][2] == '1'){
                if(!minHeap.empty()){
                    // 최대값을 삭제하기 위해 maxHeap에서 pop한다.
                    // minHeap에서 최대값을 찾기 위해 모든 값을 maxHeap에 넣는다.
                    priority_queue<int> maxHeap; // 최대값을 관리하는 우선순위 큐
                    while(!minHeap.empty()){
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                    };

                    maxHeap.pop(); // 최대값 삭제

                    while(!maxHeap.empty()){
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                    }
                }
            } else if(operations[i][2] == '-'){               
                if(!minHeap.empty()){
                    minHeap.pop(); // 최소값 삭제
                }
            }
        }
    };;

    if(!minHeap.empty()){
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        while(!minHeap.empty()){
            maxNum = max(maxNum, minHeap.top());
            minNum = min(minNum, minHeap.top());
            minHeap.pop();
        }
        answer.push_back(maxNum);
        answer.push_back(minNum);
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }


    return answer;
}

int main() {
    vector<string> operations = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    vector<int> result = solution(operations);
    for (int i : result) {
        cout << i << " ";
    }

    getchar(); // Wait for user input before closing the console window
    return 0;
}