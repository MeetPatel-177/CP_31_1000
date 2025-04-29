#include <bits/stdc++.h>
using namespace std;

bool isPowerof2(int n) {
    if((n & (n-1)) == 0) {
        return true;
    }else {
        return false;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        //we will get xor less than the both numbers when we have the most significant bit same
        //so here we are doing the same thing for minimizing the xor of adjascent elements
        //the minimum xor that we can get is always the power of 2 that is just behind of n
        //so we will print out that much number first then we will put zero in order to 
        //maintain the minimum xor as the previous number then we just print all the 
        //remainining numbers as they will always have xor less than we have already
        int curr = n-1;
        while(! isPowerof2(curr)) {
            cout << curr << " ";
            curr--;
        }
        cout << curr << " " << 0 << " ";
        for(int i=curr-1; i>0; i--) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}