#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solution(int a, int b, int c, int d){
    int answer = 0;
    vector <int> dice = {a, b, c, d};
    vector <int> num(6, 0);

    for(int i = 0; i < 4; i++){
        num[dice[i] - 1]++;
    }

    for(int i = 0; i < 6; i++){
        if(num[i] == 4){
            answer = 1111 * (i + 1);
        } else if(num[i] == 3){
            int q = 0;
            for(int j = 0; j < 6; j++){
                if(num[j] == 1){
                    q = j + 1;
                }
            }
            answer = (10 * (i + 1) + q);
        }
        else if(num[i] == 2){
            int q = 0, w = 0;
            for(int j = 0; j < 6; j++){
                if(num[j] == 1){
                    q = j + 1;
                } else if(num[j] == 2){
                    w = j + 1;
                }
            }
            answer = (q + w) * abs(q - w);
        } else if(num[i] == 1){
            answer = i + 1;
        }
    }
}