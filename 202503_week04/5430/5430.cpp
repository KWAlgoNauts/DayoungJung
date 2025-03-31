#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

void processAC(string &p, deque<int> &dq) {

    bool reverseFlag = false;
    
    for (char cmd : p) {
        if (cmd == 'R') {
            reverseFlag = !reverseFlag;
        } else if (cmd == 'D') {
            if (dq.empty()) {
                cout << "error" << endl;
                return;
            }
            if (reverseFlag) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        }
    }
    
    cout << "[";
    if (!dq.empty()) {
        if (reverseFlag) {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                if (it != dq.rbegin()) cout << ",";
                cout << *it;
            }
        } else {
            for (auto it = dq.begin(); it != dq.end(); ++it) {
                if (it != dq.begin()) cout << ",";
                cout << *it;
            }
        }
    }
    cout << "]" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string p, arr;
        int n;
        cin >> p >> n >> arr;
        
        deque<int> dq;
        stringstream ss(arr.substr(1, arr.size() - 2));
        string num;
        while (getline(ss, num, ',')) {
            if (!num.empty()) dq.push_back(stoi(num));
        }
        
        processAC(p, dq);
    }
    return 0;
}
