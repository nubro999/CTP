#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <iostream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    for(int i = 0; i < my_string.size(); i++){
        answer.push_back(my_string.substr(i, my_string.size()));
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {

    string my_string = "banana";
    vector<string> result = solution(my_string);

    for (const string& str : result) {
        cout << str << endl;
    }

    getchar();
    return 0;
}