#include <iostream>
#include <cmath> // std::pow

using namespace std;

int solution(int a, int b, int c) {
    int sum = a + b + c;
    int sumOfSquares = a * a + b * b + c * c;
    int sumOfCubes = a * a * a + b * b * b + c * c * c;

    if (a == b && b == c) {
        // 세 숫자가 모두 같을 때
        return sum * sumOfSquares * sumOfCubes;
    } else if (a == b || b == c || a == c) {
        // 두 숫자가 같을 때
        return sum * sumOfSquares;
    } else {
        // 세 숫자가 모두 다를 때
        return sum;
    }
}