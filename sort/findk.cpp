#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
2에서 나온 배열의 3번째 숫자는 5입니다.
배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    int size = commands.size();

    // commands의 각 원소에 대해 반복
    for (int index = 0; index < size; index++) {
        i = commands[index][0] - 1; // 시작 인덱스
        j = commands[index][1];     // 끝 인덱스
        k = commands[index][2];     // k번째 인덱스

        vector<int> subarray(array.begin() + i, array.begin() + j); // 부분 배열 생성
        sort(subarray.begin(), subarray.end()); // 부분 배열 정렬
        answer.push_back(subarray[k - 1]); // k번째 원소 추가
    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> result = solution(array, commands);

    for (int i : result) {
        printf("%d ", i);
    }
    getchar();
    return 0;
}
