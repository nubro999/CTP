#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int n = arr.size();
    int i = 0;

    for(i = 0; i < n; i++){
        if(stk.empty())
        {
            stk.push_back(arr[i]);
        } else if(stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
        }
        else if(stk.back() >= arr[i])
        {
            stk.pop_back();
            i --;
        }
    }



    return stk;
}