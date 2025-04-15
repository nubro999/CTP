#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i = 0; i < queries.size(); i++){
        int start = queries[i][0];
        int end = queries[i][1];
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    for(int i = 0; i < arr.size(); i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}