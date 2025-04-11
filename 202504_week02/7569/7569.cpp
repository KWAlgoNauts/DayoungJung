#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int box[100][100][100];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Tomato {
    int x, y, z;
};

queue<Tomato> q;

void bfs() {
    while (!q.empty()) {
        Tomato t = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            int nz = t.z + dz[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = box[t.z][t.y][t.x] + 1;
                    q.push({nx, ny, nz});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> H;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    q.push({m, n, h}); // 익은 토마토 좌표 값
                }
            }
        }
    }

    bfs();

    int days = 0;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (box[h][n][m] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                days = max(days, box[h][n][m]);
            }
        }
    }

    cout << days - 1 << '\n'; // 처음 익은 토마토가 1이므로 하루 수는 -1 해줌
    return 0;
}
