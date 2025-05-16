#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int l, int startX, int startY, int endX, int endY) {
    vector<vector<int>> visited(l, vector<int>(l, 0));
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    visited[startX][startY] = 1; //방문 여부 체크 (1부터 시작해 나중에 -1)

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == endX && y == endY) {
            return visited[x][y] - 1;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < l && ny >= 0 && ny < l && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l;
        cin >> l;

        int startX, startY;
        cin >> startX >> startY;

        int endX, endY;
        cin >> endX >> endY;

        cout << bfs(l, startX, startY, endX, endY) << '\n';
    }

    return 0;
}
