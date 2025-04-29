#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,k,b,s;
        cin >> n >> k >> b >> s;
        long long max_beauty = s/k;
        if(max_beauty < b) cout << -1 << endl;
        else {
            long long max_in_one_place = k*b + (k-1);
            long long min_needed_more = 0;
            if(k != 1 && max_in_one_place < s) {
                if((s-max_in_one_place) % (k-1) == 0) min_needed_more = (s - max_in_one_place)/(k-1);
                else min_needed_more = (s - max_in_one_place)/(k-1) + 1;
            }
            if(min_needed_more+1 > n) cout << -1 << endl;
            else {
                long long remaining = s - min(max_in_one_place, s);
                if(k == 1 && remaining != 0) {
                    cout << -1 << endl;
                }else {
                    cout << min(max_in_one_place, s) << " ";
                    for(int i=0; i<n-1; i++) {
                        cout << min(remaining, k-1) << " ";
                        remaining -= min(remaining, k-1);
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}