#include <iostream>
#include <vector>

using namespace std;

void fillPattern(vector<vector<char>>& board, int x, int y, int size) {
    if (size == 1) { //크기가 1일 때 별 찍기
        board[x][y] = '*';
        return;
    }

    int div = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue; //가운데는 공백
            fillPattern(board, x + i * div, y + j * div, div); //재귀호출
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N, ' '));
    fillPattern(board, 0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j];
        }
        cout <<'\n';
    }

    return 0;
}
