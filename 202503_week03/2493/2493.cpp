#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> find_reception_towers(int N, vector<int>& heights) {
    stack<pair<int, int>> s;  // (높이, 인덱스) 저장
    vector<int> result(N, 0); // 결과 배열 (수신하는 탑의 위치 저장, 기본값 0)

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top().first < heights[i]) {
            s.pop(); // 현재 탑보다 낮은 탑 제거
        }

        if (!s.empty()) { 
            result[i] = s.top().second + 1; // index 저장
        }

        s.push({heights[i], i}); // 현재 탑을 스택에 추가
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<int> result = find_reception_towers(N, heights);

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
