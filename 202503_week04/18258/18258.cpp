#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;
    string command;
    
    while (N--) {
        cin >> command;
        
        if (command == "push") {
            int X;
            cin >> X;
            q.push(X);
        } else if (command == "pop") {
            if (q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "empty") {
            cout << (q.empty() ? 1 : 0) << endl;
        } else if (command == "front") {
            if (q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if (command == "back") {
            if (q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.back() << endl;
            }
        }
    }
    return 0;
}
