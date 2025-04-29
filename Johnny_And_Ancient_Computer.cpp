#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        long long c = max(a,b);
        long long d = min(a,b);
        //here always we will make the larger element small
        //so if we have c is not a multiple of d then we can't make it both equal to each other
        //other scene is that if c/d is not a power of 2 then also it is not possible to make equal
        if(c % d != 0 || ((c/d) & (c/d - 1)) != 0) {
            cout << -1 << endl;
            continue;
        }
        int count = 0;
        //here for minimum operations we are just doing max/8 so that it can complete in 
        //minimum number of operations
        while(c > d) {
            count++;
            c /= 8;
        }
        cout << count << endl;
    }
    return 0;
}