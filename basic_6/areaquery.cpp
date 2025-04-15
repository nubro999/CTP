#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // For std::sort

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    int start, end, k;

    for(int i = 0; i < queries.size(); i++){
        start = queries[i][0];
        end = queries[i][1];
        k = queries[i][2];
        
        int found = -1; // Initialize found to -1

        for (int j = start; j <= end; j++) {
            if (arr[j] > k) {
                if (found == -1 || arr[j] < arr[found]) {
                    found = j;
                }
            }
        }

        if (found != -1) {
            answer.push_back(arr[found]);
        } else {
            answer.push_back(-1);
        }
    }

    return answer;
}
    

int main(){
    vector<int> arr = {0, 1, 2, 4, 3};
    vector<vector<int>> queries = {{0, 4, 2}, {0, 3, 2}, {0, 2, 2}};
    vector<int> result = solution(arr, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl; 
    getchar(); 
    return 0;
}

