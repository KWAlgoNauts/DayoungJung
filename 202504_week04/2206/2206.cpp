#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 1001;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // visited[x][y][0]: 벽을 부수지 않고 방문, visited[x][y][1]: 벽을 부수고 방문

// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs() {
    queue<tuple<int, int, int>> q; //(x, y, 벽을 부쉈는지 여부)
    q.push({1, 1, 0});
    visited[1][1][0] = true;

    int depth = 1; //시작하는 칸도 포함하니까 1부터 시작

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x, y, broken;
            tie(x, y, broken) = q.front();
            q.pop();

            if (x == n && y == m) {
                return depth;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

                if (map[nx][ny] == 0 && !visited[nx][ny][broken]) {
                    //이동할 수 있는 곳이고 아직 방문하지 않았다면
                    visited[nx][ny][broken] = true;
                    q.push({nx, ny, broken});
                }
                else if (map[nx][ny] == 1 && broken == 0 && !visited[nx][ny][1]) {
                    //벽을 만났고, 아직 벽을 부수지 않은 상태라면
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, 1});
                }
            }
        }
        depth++;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j-1] - '0';
        }
    }

    cout << bfs() << "\n";

    return 0;
}
