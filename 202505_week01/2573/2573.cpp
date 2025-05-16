#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[300][300];
int temp[300][300];
bool visited[300][300];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void melt() {
    memcpy(temp, map, sizeof(map));
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (map[i][j] > 0) {
                int sea = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (map[nx][ny] == 0)
                        sea++;
                }
                temp[i][j] = max(0, map[i][j] - sea);
            }
        }
    }
    memcpy(map, temp, sizeof(map));
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] > 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int count_components() {
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (map[i][j] > 0 && !visited[i][j]) {
                bfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int year = 0;
    while (true) {
        int components = count_components();
        if (components == 0) {
            cout << 0 << '\n';
            break;
        }
        if (components >= 2) {
            cout << year << '\n';
            break;
        }
        melt();
        year++;
    }
    return 0;
}
