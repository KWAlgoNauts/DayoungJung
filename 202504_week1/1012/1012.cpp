#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;
int M, N, K;
int field[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 }; // 좌우
int dy[4] = { -1, 1, 0, 0 }; // 상하

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (field[ny][nx] == 1 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        memset(field, 0, sizeof(field));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int wormCount = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    bfs(y, x);
                    wormCount++;
                }
            }
        }

        cout << wormCount << '\n';
    }

    return 0;
}
