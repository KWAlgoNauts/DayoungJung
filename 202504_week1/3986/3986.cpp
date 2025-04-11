#include <iostream>
#include <stack>
#include <string>

using namespace std;

//좋은 단어인지 확인하는 함수
bool isGoodWord(const string& word) {
    stack<char> s;
    
    for (char c : word) {
        if (!s.empty() && s.top() == c) {
            s.pop(); //짝이 맞으면 제거
        } else {
            s.push(c); //새로운 문자
        }
    }
    
    return s.empty(); //모든 문자가 짝을 이루면 좋은 단어임.
}

int main() {
    int N, count = 0;
    cin >> N;
    
    while (N--) {
        string word;
        cin >> word;
        if (isGoodWord(word)) {
            count++;
        }
    }
    
    cout << count << "\n";
    return 0;
}
