#include <bits/stdc++.h>
using namespace std;

//remember this
int xor_upto_n(int n) {
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else return 0;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        //we have to take 0 to a-1 that is total a number of elements minimum because we want
        //minumum excluded is a so there must be all elements present less than a
        int min_needed = a;
        //now we are thinking about making xor equals to b
        int more_needed = 0;
        //if we got already b xor then no need to take any other extra element
        if(xor_upto_n(a-1) == b) more_needed = 0;
        //now in order to make xor equals to b we have to find one single element that can 
        //make whole xor equals b but if that element is b itself then we have to take
        //two extra elements that can make their xor equals b
        else if((a ^ xor_upto_n(a-1)) == b) more_needed = 2;
        else more_needed = 1;
        cout << min_needed + more_needed << endl;
    }
    return 0;
}