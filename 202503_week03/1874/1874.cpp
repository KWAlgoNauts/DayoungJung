#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> s;
    vector<char> operations;
    int current = 1;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        while (current <= num) {
            s.push(current++);
            operations.push_back('+');
        }
        
        if (s.top() == num) {
            s.pop();
            operations.push_back('-');
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    for (char op : operations) {
        cout << op << '\n';
    }
    
    return 0;
}
