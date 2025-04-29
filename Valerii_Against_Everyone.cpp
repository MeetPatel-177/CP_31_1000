#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int found = 0;
        for(int i=1; i<n; i++) {
            if(arr[i] == arr[i-1]) {
                found = 1;
                break;
            }
        }
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}