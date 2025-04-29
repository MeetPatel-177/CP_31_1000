#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,p;
        cin >> n >> p;
        vector<int>a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<pair<int,int>>pairs(n, {0,0});
        for(int i=0; i<n; i++) {
            pairs[i] = {b[i], a[i]};
        }
        sort(pairs.begin(), pairs.end());
        long long cost = p;
        int remaining = n-1;
        int i = 0;
        while(pairs[i].first < p) {
            cost += (1LL * pairs[i].first * min(pairs[i].second, remaining));
            remaining -= min(pairs[i].second, remaining);
            if(remaining == 0) break;
            i++;
        }
        cost += (1LL * remaining * p);
        cout << cost << endl;
    }
    return 0;
}