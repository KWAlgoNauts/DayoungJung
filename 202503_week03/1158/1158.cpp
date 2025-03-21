#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    vector<int> result;
    
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        for (int i = 1; i < K; i++) {
            q.push(q.front()); //첫 번째에 있는 원소를 뒤로 보냄.
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }
    
    cout << "<";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";
    
    return 0;
}
