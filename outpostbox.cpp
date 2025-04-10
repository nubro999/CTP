#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int total, int row, int boxnum) { //n은 택배의 수, w는 한줄의 택배의 수, num은 택배의 번호
    // 택배의 번호는 1부터 시작하므로 num-1을 해줍니다.

    int indexboxnum = boxnum - 1; //boxnum은 0부터 시작하는 인덱스
    int cloumn = total / row; //column은 n을 w로 나눈 몫 = 행의 수
    int topboxcount = total % row; //toprow는 n을 w로 나눈 나머지 = 마지막 행의 택배 수
    int boxrow = (boxnum / row) + 1; //boxrow는 boxnum을 w로 나눈 몫 = 지정박스의 행번호
    int boxcloumn = boxnum % row; //boxcloumn은 boxnum을 w로 나눈 나머지 = 지정박스의 열번호
    int answer = 0; //answer는 num의 택배를 꺼내기위한 박스의 수

    //열이 홀수일때 오른쪽으로 가고 짝수일때 왼쪽으로 가는 경우
    //boxrow가 홀수일때
    if((total / row) % 2 == 0) { 
        if(topboxcount > boxcloumn){
            answer = row - boxcloumn + 1; //박스의 수는 열번호 + 1
        }
        else{
            answer = row - boxcloumn; //박스의 수는 열번호 - 1
        };
    } else { //boxrow가 짝수일때
        if((row - topboxcount) > boxcloumn) { //박스의 수는 열번호 - 1
            answer = row - boxcloumn; //박스의 수는 열번호
        } else {
            answer = row - boxcloumn + 1; //박스의 수는 열번호 + 1
        };       
    };

    answer = answer + 1;
    return answer;
}

int main() {
    int result = solution(22, 6, 8); // 예시: 총 10개, 한 줄에 3개, 박스 번호 2
    printf("%d\n", result); // 결과 출력
    getchar(); // 콘솔 창이 바로 닫히지 않도록 대기
    return 0;
}