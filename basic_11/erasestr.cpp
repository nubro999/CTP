#include <string>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    int n = 0;
    sort(indices.begin(), indices.end(), greater<int>());
    for(int i = 0; i < indices.size(); i++){
        my_string.erase(indices[i], 1);
    }
    answer = my_string;
    return answer;
}