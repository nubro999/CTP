#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    for(int i = e; i >= s; i--){
        answer += my_string[i];
    }

    my_string = my_string.substr(0, s) + answer + my_string.substr(e + 1);
    return my_string;
}