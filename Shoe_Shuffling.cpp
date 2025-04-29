#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int found = 1;
        int curr_count = 1;
        for(int i=0; i<n-1; i++) {
            if(arr[i] == arr[i+1]) {
                curr_count++;
            }else {
                if(curr_count == 1) {
                    found = 0;
                    break;
                }
                curr_count = 1;
            }
        }
        if(curr_count == 1) {
            found = 0;
        }
        if(!found || n == 1) cout << -1 << endl;
        else {
            int i = 0;
            while(i < n) {
                int j = i;
                while(i < n-1 && arr[i] == arr[i+1]) {
                    i++;
                }
                cout << i+1 << " ";
                for(int ind=j+1; ind<i+1; ind++) {
                    cout << ind << " ";
                }
                i++;
            }
            cout << endl;
        }
    }
    return 0;
}