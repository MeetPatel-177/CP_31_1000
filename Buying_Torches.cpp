#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long x,y,k;
        cin >> x >> y >> k;
        //what is n ?
        //now in order to make atleast k torches we have to make k coals first and then
        //we also have to have k sticks leftout in order to make k torches
        //so now come to formula
        //1 + ((x-1) + (x-1) + ... + (n times)) = k*y + k
        //why initialally we have 1 stick then in each trade1 we gain x and loss 1 so
        //eventully gained x-1 sticks let's say we are doing trade1 for n times
        //so formula becomes n = k*(y+1) - 1/x-1
        //so now we have enough sticks to make k coals so we will do trade2 for k times
        //so final answer will be trade1 + trade2
        long long n = (k*(y+1) - 1)/(x-1);
        long long trade1 = 0;
        if((k*(y+1) - 1) % (x-1) == 0) {
            trade1 = n;
        }else {
            trade1 = n + 1;
        }
        long long trade2 = k;
        cout << trade1 + trade2 << endl;
    }
    return 0;
}