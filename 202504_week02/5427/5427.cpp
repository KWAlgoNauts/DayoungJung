#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int w, h;
vector<string> building;
int fireTime[1000][1000];
int sangTime[1000][1000];

void solve() {
    cin >> w >> h;
    building = vector<string>(h);
    for (int i = 0; i < h; ++i) {
        cin >> building[i];
    }

    queue<pair<int, int>> fireQ;
    queue<pair<int, int>> sangQ;

    // 초기화
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            fireTime[i][j] = INF;
            sangTime[i][j] = -1;
            if (building[i][j] == '*') {
                fireQ.push({i, j});
                fireTime[i][j] = 0;
            }
            if (building[i][j] == '@') {
                sangQ.push({i, j});
                sangTime[i][j] = 0;
            }
        }
    }

    // 불 BFS
    while (!fireQ.empty()) {
        int x = fireQ.front().first;
        int y = fireQ.front().second;
        fireQ.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (building[nx][ny] == '#' || fireTime[nx][ny] <= fireTime[x][y] + 1) continue;
            fireTime[nx][ny] = fireTime[x][y] + 1;
            fireQ.push({nx, ny});
        }
    }

    // 상근이 BFS
    while (!sangQ.empty()) {
        int x = sangQ.front().first;
        int y = sangQ.front().second;
        sangQ.pop();

        // 탈출 조건 : 가장자리에 도달하면
        if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
            cout << sangTime[x][y] + 1 << "\n";
            return;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (building[nx][ny] == '#' || sangTime[nx][ny] != -1) continue;
            if (sangTime[x][y] + 1 >= fireTime[nx][ny]) continue;
            sangTime[nx][ny] = sangTime[x][y] + 1;
            sangQ.push({nx, ny});
        }
    }

    // 탈출 불가능
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
