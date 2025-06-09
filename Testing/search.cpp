#include <iostream>
#include <vector>
#include <stdexcept>

// Search 함수: Key를 T에서 찾는다.
// Found: 찾았으면 true, 아니면 false
// L: 찾은 인덱스(0-based), 못 찾으면 -1
void Search(int Key, const std::vector<int>& T, bool& Found, int& L) {
    // Pre-condition: 최소 하나의 원소가 있어야 함
    if (T.empty()) {
        throw std::invalid_argument("배열에 최소 하나의 원소가 있어야 합니다.");
    }

    Found = false;
    L = -1;

    for (size_t i = 0; i < T.size(); ++i) {
        if (T[i] == Key) {
            Found = true;
            L = static_cast<int>(i);
            break;
        }
    }

    // Post-condition 검증 (디버깅용, 실제 서비스에서는 제외 가능)
    if (Found) {
        if (T[L] != Key) {
            throw std::logic_error("Post-condition 위반: Found는 true인데 T[L] != Key");
        }
    } else {
        for (size_t i = 0; i < T.size(); ++i) {
            if (T[i] == Key) {
                throw std::logic_error("Post-condition 위반: Found는 false인데 배열에 Key가 있음");
            }
        }
    }
}

// 테스트용 main 함수
int main() {
    std::vector<int> arr = {3, 5, 7, 9, 11};
    int key = 7;
    bool found;
    int index;

    try {
        Search(key, arr, found, index);
        if (found) {
            std::cout << "Key " << key << " found at index " << index << std::endl;
        } else {
            std::cout << "Key " << key << " not found in the array." << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "오류: " << ex.what() << std::endl;
    }

    getchar(); // Wait for user input before exiting

    return 0;
}
