#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        string str;
        cin >> str;
        vector<int>pf(n-k+1,0);
        for(int i=0; i<k; i++) {
            if(str[i] == 'B') {
                pf[0]++;
            }
        }
        for(int i=1; i<=n-k; i++) {
            pf[i] = pf[i-1];
            if(str[i-1] == 'B') pf[i]--;
            if(str[i+k-1] == 'B') pf[i]++;
        }
        int min_ope = INT_MAX;
        int curr_ope = 0;
        for(int i=0; i<=n-k; i++) {
            curr_ope = k - pf[i];
            min_ope = min(min_ope, curr_ope);
        }
        cout << min_ope << endl;
    }
    return 0;
}