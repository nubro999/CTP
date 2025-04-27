#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = -1;
    int n = arr.size();
    for(int i = idx; i < n; i++){
        if(arr[i] == 1){
            answer = i;
            break;
        }
    }

    return answer;
}