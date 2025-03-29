#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        //if we have even number then answer will be always n/2 and n/2
        //as LCM of both will be itself n/2
        //any other permutation of a and b will eventully leads to a greater LCM than n/2
        if(n % 2 == 0) cout << n/2 << " " << n/2 << endl;
        else {
            //now we have to find the maximum factor that the number n holds in it
            //if the number is prime we will ended up having found = 0 so max factor is 1
            //but for composite numbers we will have any smallest i for which it is a multiple of n
            //and the maximum factor is always (n / smallest factor) this is a simple concept
            //at the end we will break into 2 parts of max_factor and n - max_factor
            int max_factor = 0;
            int found = 0;
            for(int i=2; i*i<=n; i++) {
                if(n % i == 0) {
                    found = 1;
                    max_factor = n/i;
                    break;
                }
            }
            if(!found) max_factor = 1;
            cout << max_factor << " " << n - max_factor << endl;
        }
    }
    return 0;
}