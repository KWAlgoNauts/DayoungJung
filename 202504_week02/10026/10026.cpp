#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
char grid[100][100];
bool visited[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//BFS 함수: 주어진 좌표에서 시작하여 같은 색의 영역을 모두 방문함.
void bfs(int x, int y, bool isColorBlind) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    char current = grid[x][y];

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;

            if (isColorBlind) {
                //적록색약: R과 G를 동일하게 취급
                if ((current == 'R' || current == 'G') &&
                    (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
                else if (grid[nx][ny] == current) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
            else {
                //일반인 시각
                if (grid[nx][ny] == current) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int countRegions(bool isColorBlind) {
    int count = 0;
    fill(&visited[0][0], &visited[0][0] + 100 * 100, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!visited[i][j]) {
                bfs(i, j, isColorBlind);
                count++;
            }

    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int normal = countRegions(false);      //일반인 기준
    int colorBlind = countRegions(true);   //적록색약 기준

    cout << normal << " " << colorBlind << endl;
    return 0;
}
