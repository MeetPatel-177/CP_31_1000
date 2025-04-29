#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,r,b;
        cin >> n >> r >> b;
        int parts = b+1;
        int max_continuous = r/parts + 1;
        int no_of_times_max = r % parts;
        int ind = 0;
        while(no_of_times_max--) {
            for(int i=0; i<max_continuous; i++) {
                cout << "R";
                ind++;
            }
            if(ind < n) {
                cout << "B";
                ind++;
            }
        }
        while(ind < n) {
            for(int i=0; i<max_continuous - 1; i++) {
                cout << "R";
                ind++;
            }
            if(ind < n) {
                cout << "B";
                ind++;
            }
        }
        cout << endl;
    }
    return 0;
}