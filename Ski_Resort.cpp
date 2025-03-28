#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k,q;
        cin >> n >> k >> q;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //we have to calculate consecutive pairs so we will iterate over whole array
        //and keep track of currently how many consecutive days we have that we can use
        //every time we encounter greater than k consecutive days then we will having 
        //+= curr_pairs where curr_pairs is the pairs we can make with current value
        //for example if we have [-5 10 -4] and k = 1 and q = 10 then
        //by iterating for first we can make one pair then for second we can make 2 new pairs
        //and for third again we can make three new pairs so ans will be (1+2+3 = 6)
        int curr_days = 0;
        int curr_pairs = 1;
        long long tot_pairs = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] <= q) {
                curr_days++;
                if(curr_days >= k) {
                    tot_pairs += 1LL*curr_pairs;
                    curr_pairs++;
                }
            }else {
                curr_days = 0;
                curr_pairs = 1;
            }
        }
        cout << tot_pairs << endl;
    }
    return 0;
}