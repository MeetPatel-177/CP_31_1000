#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr[n];
        for(int i=0; i<n; i++) {
            int m;
            cin >> m;
            for(int j=0; j<m; j++) {
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
        //here for all the internal arrays we are finding their mini and second mini
        //here we are using selection sort for just first two elements
        //so TC will be O(n*2m)
        for(int i=0; i<n; i++) {
            int m = arr[i].size();
            for(int j=0; j<2; j++) {
                int mini_index = j;
                for(int k=j+1; k<m; k++) {
                    if(arr[i][mini_index] > arr[i][k]) {
                        mini_index = k;
                    }
                }
                swap(arr[i][mini_index], arr[i][j]);
            }
        }
        //now as we have mini at the first position and second mini at the second position
        //for all the arrays so we just have to find what we needed
        //beauty will be maximized when most off second mini comes into beauty
        //so we will just take overall mini and all other second minis
        int overall_mini = arr[0][0];
        for(int i=1; i<n; i++) {
            if(arr[i][0] < overall_mini) {
                overall_mini = arr[i][0];
            }
        }
        int overall_second_mini = arr[0][1];
        int overall_second_mini_index = 0;
        for(int i=1; i<n; i++) {
            if(arr[i][1] < overall_second_mini) {
                overall_second_mini = arr[i][1];
                overall_second_mini_index = i;
            }
        }
        long long ans = 0;
        ans += 1LL*overall_mini;
        for(int i=0; i<n; i++) {
            if(i == overall_second_mini_index) continue;
            ans += 1LL*arr[i][1];
        }
        cout << ans << endl;
    }
    return 0;
}