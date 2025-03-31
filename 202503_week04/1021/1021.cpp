#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    deque<int> dq;
    vector<int> targets(M);
    
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> targets[i];
    }
    
    int operationCount = 0;
    
    for (int target : targets) {
        int leftShift = 0;
        int rightShift = 0;
        
        // target의 현재 위치
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                leftShift = i;
                rightShift = dq.size() - i;
                break;
            }
        }
        
        
        if (leftShift <= rightShift) {
            // 왼쪽으로 이동
            while (dq.front() != target) {
                dq.push_back(dq.front());
                dq.pop_front();
                operationCount++;
            }
        } else {
            // 오른쪽으로 이동
            while (dq.front() != target) {
                dq.push_front(dq.back());
                dq.pop_back();
                operationCount++;
            }
        }
        
        // 첫 번째 원소 제거
        dq.pop_front();
    }
    
    cout << operationCount << endl;
    return 0;
}
