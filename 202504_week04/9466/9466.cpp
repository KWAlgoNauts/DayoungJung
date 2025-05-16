#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;

int n;
int student[MAX];
bool visited[MAX];
bool finished[MAX];
int result;

void dfs(int x) {
    visited[x] = true;
    int next = student[x];

    if (!visited[next]) {
        dfs(next);
    }
    else if (!finished[next]) { //사이클 발견
        for (int i = next; i != x; i = student[i]) {
            result--;
        }
        result--;
    }

    finished[x] = true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        result = n;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << result << "\n";
    }
    return 0;
}
