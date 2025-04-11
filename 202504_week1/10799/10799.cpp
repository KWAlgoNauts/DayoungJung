#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    stack<char> stk;
    int result = 0;

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '(') {
            stk.push('('); //여는 괄호는 무조건 스택에 push
        } else {
            stk.pop(); //닫는 괄호이므로 일단 하나 pop

            if (input[i - 1] == '(') {
                //레이저인 경우: 바로 앞이 '(' 이면 레이저
                result += stk.size(); //현재 열린 막대기 수 만큼 잘림
            } else {
                //막대기 끝나는 부분
                result += 1;
            }
        }
    }

    cout << result << endl;
    return 0;
}
