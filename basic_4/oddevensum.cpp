#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;

    string even = "";
    string odd = "";
    for(int i = 0; i < num_list.size(); i++) {
        if (num_list[i] % 2 == 0) {
            even += to_string(num_list[i]);
        } else {
            odd += to_string(num_list[i]);
        }
    }

    answer = stoi(even) + stoi(odd);


    return answer;
}

int main() {
    vector<int> num_list = {1, 2, 3, 4, 5};
    cout << solution(num_list) << endl; // Output: 15
    getchar(); // Wait for user input before closing the console window
    return 0;
}