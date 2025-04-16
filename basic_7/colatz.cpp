#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(n); // Add the initial number to the answer

    while(n != 1){
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1);
        };
        answer.push_back(n);
    }

    return answer;
}

int main(){
    int n = 6;
    vector<int> result = solution(n);
    for(int i : result) {
        cout << i << " ";
    }

    getchar(); // Wait for user input before closing the console window
    return 0;
}