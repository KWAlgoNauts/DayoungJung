#include <iostream>
#include <list>
#include <string>

using namespace std;

void findPassword(const string &s) {

    list<char> password;
    auto cursor = password.begin(); // 커서 처음 위치

    for (char ch : s) {
        if (ch == '<') {
            if (cursor != password.begin()) 
			          cursor--; // 왼쪽 이동
        } else if (ch == '>') {
	            if (cursor != password.end()) 
			            cursor++; // 오른쪽 이동
        } else if (ch == '-') {
	            if (cursor != password.begin()) { 
	                cursor--; // 왼쪽 문자 삭제
                
                cursor = password.erase(cursor);
            }
        } else {
	            password.insert(cursor, ch); // 문자 넣기
        }
    }

    for (char ch : password) 
		    cout << ch;
    
		   cout << '\n';
}

int main() {

    int n;
    cin >> n;
    
    while (n--) {
        string input;
        cin >> input;
        
        findPassword(input);
    }

    return 0;
}
