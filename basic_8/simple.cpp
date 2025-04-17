#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;

    if(!(x1 || x2)){answer = false;}
    if(!(x3 || x4)){answer = false;}

    return answer;
}