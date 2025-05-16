#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100;
int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int island_id = 2; //섬 번호 (1은 원래 육지였음)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void mark_island(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = id;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); 
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] == 1) {
                map[nx][ny] = id;
                q.push({nx, ny});
            }
        }
    }
}

int bfs(int id) {
    queue<pair<int, int>> q;
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == id) {
                q.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (map[nx][ny] > 0 && map[nx][ny] != id) {
                    return visited[x][y];
                }
                if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return 1e9; //도달하지 못한 경우
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    //섬 구분하기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] == 1)
                mark_island(i, j, island_id++);

    //각 섬에 대해 BFS 실행해 최단 다리 길이 찾기
    int answer = 1e9;
    for (int i = 2; i < island_id; i++) {
        answer = min(answer, bfs(i));
    }

    cout << answer << endl;
    return 0;
}
