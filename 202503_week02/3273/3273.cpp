#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> x;
    unordered_set<int> check;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int complement = x - arr[i];
        if (check.find(complement) != check.end()) {
            count++;
        }
        check.insert(arr[i]);
    }
    
    cout << count << "\n";
    return 0;
}
