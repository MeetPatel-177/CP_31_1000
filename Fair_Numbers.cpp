#include <bits/stdc++.h>
using namespace std;

bool isFair(long long n) {
    long long dup = n;
    while(n) {
        int digit = n%10;
        if(digit != 0 && (dup % digit) != 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long curr = n;
        while(1) {
            if(isFair(curr)) {
                cout << curr << endl;
                break;
            }
            curr++;
        }
    }
    return 0;
}