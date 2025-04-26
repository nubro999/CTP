#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 1;
    int n = is_prefix.size();
    for(int i = 0; i < n; i++){
        if(my_string[i] != is_prefix[i]){
            return 0;
        }
    }
    return answer;
}