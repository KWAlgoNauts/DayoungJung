#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 100001;

int bfs(int N, int K) {
    vector<int> dist(MAX, -1);
    deque<int> dq;

    dist[N] = 0;
    dq.push_back(N);

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        if (current == K) return dist[current];

        //순간이동(0초)
        if (current * 2 < MAX && dist[current * 2] == -1) {
            dist[current * 2] = dist[current];
            dq.push_front(current * 2);
        }

        //걷기(1초)
        if (current - 1 >= 0 && dist[current - 1] == -1) {
            dist[current - 1] = dist[current] + 1;
            dq.push_back(current - 1);
        }

        if (current + 1 < MAX && dist[current + 1] == -1) {
            dist[current + 1] = dist[current] + 1;
            dq.push_back(current + 1);
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
    return 0;
}
