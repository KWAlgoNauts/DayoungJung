#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    vector<int> count(10, 0);
    
    for (char digit : N) {
        count[digit - '0']++;
    }
    
    int sixnine = (count[6] + count[9] + 1) / 2;
    count[6] = count[9] = sixnine;
    
    cout << *max_element(count.begin(), count.end()) << endl;
    
    return 0;
}
