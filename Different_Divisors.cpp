#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        int curr = d+1;
        int smallest_prime1 = 0;
        while(1) {
            if(isPrime(curr)) {
                smallest_prime1 = curr;
                break;
            }
            curr++;
        }
        curr = smallest_prime1 + d;
        int smallest_prime2 = 0;
        while(1) {
            if(isPrime(curr)) {
                smallest_prime2 = curr;
                break;
            }
            curr++;
        }
        cout << smallest_prime1*smallest_prime2 << endl;
    }
    return 0;
}