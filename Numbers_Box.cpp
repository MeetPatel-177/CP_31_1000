#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<int>>arr(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        int sum = 0;
        int tot_negative = 0;
        int min_absolute = INT_MAX;
        bool have_zero = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j] == 0) {
                    have_zero = 1;
                }else if(arr[i][j] < 0) {
                    tot_negative++;
                }
                min_absolute = min(min_absolute, abs(arr[i][j]));
                sum += abs(arr[i][j]);
            }
        }
        int max_sum = 0;
        if(!have_zero && tot_negative%2 != 0) {
            max_sum = sum - 2*min_absolute;
        }else {
            max_sum = sum;
        }
        cout << max_sum << endl;
    }
    return 0;
}