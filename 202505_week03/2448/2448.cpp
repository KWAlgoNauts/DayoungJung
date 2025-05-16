#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> star;

void draw(int n, int x, int y) {
    if (n == 3) {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; i++)
            star[x + 2][y + i] = '*';
        return;
    }

    int half = n / 2;
    //위쪽 삼각형
    draw(half, x, y);
    //왼쪽 아래 삼각형
    draw(half, x + half, y - half);
    //오른쪽 아래 삼각형
    draw(half, x + half, y + half);
}

int main() {
    cin >> N;

    //전체 별 배열 공백으로 초기화
    star = vector<string>(N, string(2 * N - 1, ' '));

    draw(N, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << star[i] << '\n';

    return 0;
}
