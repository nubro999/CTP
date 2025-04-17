#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;

    for (const string&str : intStrs){
        int temp = 0;
        for(int i = s; i < s + l; i++){
            if (i > str.size()) break; // Check if index is out of bounds
            temp = temp * 10 + (str[i] - '0'); // Convert char to int and build the number
        }

        if (temp > k) {
            answer.push_back(temp); // Add to answer if greater than k
        }
    };

    return answer;
}

int main(){
    vector<string> intStrs = {"12323425", "4561231", "78953214"};
    int k = 100;
    int s = 1;
    int l = 3;

    vector<int> result = solution(intStrs, k, s, l);

    for (int num : result) {
        cout << num << " ";
    }

    getchar(); // Wait for user input before closing the console window

    return 0;
}