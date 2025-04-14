#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main(){

    int i = 0;
    while(i < 5)
    {
        cout << i << endl;
        i++;
    };

    cout << "Hello World!" << endl;
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}