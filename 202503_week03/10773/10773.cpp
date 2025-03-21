#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K, num;
    cin >> K;
    
    stack<int> s;
    
    for (int i = 0; i < K; i++) {
        cin >> num;
        if (num == 0 && !s.empty()) {
            s.pop();
        } else {
            s.push(num);
        }
    }
    
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum << endl;
    return 0;
}
