#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <iostream>

using namespace std;

int solution(string my_string,string is_suffix) {
    vector<string> answer;
    int boool = 0;
    for(int i = 0; i < my_string.size(); i++){
        answer.push_back(my_string.substr(i, my_string.size()));
    }

    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == is_suffix){
            boool = 1;
            break;
        }
    }
    return boool;
}
