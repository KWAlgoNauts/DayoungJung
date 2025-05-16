#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> video;

// (x, y) 좌표에서 영역이 모두 같은 값인지 확인
bool isSame(int x, int y, int size) {
    char val = video[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (video[i][j] != val) 
	            return false;
        }
    }
    return true;
}

//재귀적으로 압축 결과 생성
void compress(int x, int y, int size) {
    if (isSame(x, y, size)) {
        cout << video[x][y];
        return;
    }

    cout << "(";
    int newSize = size / 2;
    compress(x, y, newSize);                     //왼쪽 위
    compress(x, y + newSize, newSize);           //오른쪽 위
    compress(x + newSize, y, newSize);           //왼쪽 아래
    compress(x + newSize, y + newSize, newSize); //오른쪽 아래
    cout << ")";
}

int main() {
    cin >> N;
    video.resize(N, vector<char>(N));
    
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            video[i][j] = row[j];
        }
    }

    compress(0, 0, N);
    cout << endl;
    return 0;
}
