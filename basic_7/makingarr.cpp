#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;

    for(int i = l; i <= r; i++){
        int num = i;
        bool isValid = true;

        while(num > 0) {
            int digit = num % 10;
            if(digit != 0 && digit != 5) {
                isValid = false;
                break;
            }
            num /= 10;
        }

        if(isValid) {
            answer.push_back(i);
        }
    }

    if(answer.empty()) {
        answer.push_back(-1);
    }
    
    return answer;
}