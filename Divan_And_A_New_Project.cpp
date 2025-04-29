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
        //here we want to recover previous indices of every value after sort it so we use pairs
        vector<pair<int,int>>pairs(n);
        for(int i=0; i<n; i++) {
            pairs[i] = {arr[i], i};
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        int i = 0;
        int curr = 1;
        vector<int>coor(n+1,0);
        coor[0] = n;
        while(i < n) {
            coor[pairs[i].second + 1] = n + curr;
            if(i+1 < n) coor[pairs[i+1].second + 1] = n - curr;
            i += 2;
            curr++;
        }
        long long minutes = 0;
        for(int i=1; i<n+1; i++) {
            minutes += (1LL*abs(coor[i] - coor[0])*arr[i-1]);
        }
        cout << 2*minutes << endl;
        for(int i=0; i<n+1; i++) {
            cout << coor[i] << " ";
        }
        cout << endl;
    }
    return 0;
}