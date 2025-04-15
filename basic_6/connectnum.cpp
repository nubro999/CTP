#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.insert(answer.end(), num_list.begin(), num_list.end());
    int last = num_list[num_list.size() - 1];
    int second_last = num_list[num_list.size() - 2];
    if(last > second_last){
        answer.push_back(last - second_last);
    } else {
        answer.push_back(last * 2);
    };

    return answer;
}

int main() {
    vector<int> num_list = {1, 2, 3, 4, 5};
    vector<int> result = solution(num_list);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl; // Output: 1 2 3 4 5 10
    getchar(); // Wait for user input before closing the console window
    return 0;
}