#include <iostream>
using namespace std;

const int MAX = 2187; //N의 최대값
int paper[MAX][MAX];
int countResult[3]; // index 0: -1, 1: 0, 2: 1

//주어진 범위가 모두 같은 숫자인지 확인하는 함수
bool isSame(int x, int y, int size) {
    int value = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != value)
                return false;
        }
    }
    return true;
}

//분할 정복 함수
void divide(int x, int y, int size) {
    if (isSame(x, y, size)) {
        countResult[paper[x][y] + 1]++;
        return;
    }

    int newSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            divide(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    divide(0, 0, N);

    //출력: -1, 0, 1 순서
    for (int i = 0; i < 3; ++i)
        cout << countResult[i] << '\n';

    return 0;
}
