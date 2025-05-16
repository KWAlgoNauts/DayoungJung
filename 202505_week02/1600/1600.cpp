#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int K, W, H;
int board[201][201];
bool visited[201][201][31];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int hx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs() {
    queue<tuple<int, int, int, int>> q; //x, y, 말처럼 이동 횟수, 총 이동 수
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [x, y, k, cnt] = q.front();
        q.pop();

        if (x == W - 1 && y == H - 1) return cnt;

        //일반 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
                if (!visited[ny][nx][k] && board[ny][nx] == 0) {
                    visited[ny][nx][k] = true;
                    q.push({nx, ny, k, cnt + 1});
                }
            }
        }

        //말처럼 이동
        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
                    if (!visited[ny][nx][k + 1] && board[ny][nx] == 0) {
                        visited[ny][nx][k + 1] = true;
                        q.push({nx, ny, k + 1, cnt + 1});
                    }
                }
            }
        }
    }
    return -1;  //도달 불가능
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    cout << bfs() << '\n';

    return 0;
}
