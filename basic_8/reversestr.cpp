#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";


    for (auto query : queries) {
        int start = query[0];
        int end = query[1];
        string temp = my_string.substr(start, end - start + 1);
        reverse(temp.begin(), temp.end());
        my_string.replace(start, end - start + 1, temp); //why +1? 
    }

    answer = my_string;
    return answer;
}