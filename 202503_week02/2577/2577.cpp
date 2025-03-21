#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int result = A * B * C;
    string string_Result = to_string(result);
    int count[10] = {0};
    
    for (char digit : string_Result) {
        count[digit - '0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << count[i] << endl;
    }
    
    return 0;
}
