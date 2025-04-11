#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    stack<int> val;

    for (char ch : s) {
        if (ch == '(' || ch == '[') {
            st.push(ch);
            val.push(0); //값 계산의 기준점
        } else {
            if (st.empty()) {
                cout << 0 << endl;
                return 0;
            }

            int temp = 0;
            while (!val.empty() && val.top() != 0) {
                temp += val.top();
                val.pop();
            }

            if (val.empty()) {
                cout << 0 << endl;
                return 0;
            }
            val.pop(); //0 제거

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
                cout << 0 << endl;
                return 0;
            }

            if (temp == 0) temp = 1;
            int result = (ch == ')') ? temp * 2 : temp * 3;
            val.push(result);
        }
    }

    if (!st.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int answer = 0;
    while (!val.empty()) {
        answer += val.top();
        val.pop();
    }

    cout << answer << endl;
    return 0;
}
