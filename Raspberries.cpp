#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int min_ope = INT_MAX;
        int curr_ope = 0;
        //we only have to take care of 4 as we can make 2*2 = 4 otherwise if k is not equal to
        //4 we just have to traverse whole array and count the number of operations to make 
        //anyone number multiple of k and we ended up getting whole product multiple of k
        if(k != 4) {
            for(int i=0; i<n; i++) {
                if(arr[i] % k == 0) curr_ope = 0;
                else curr_ope = k - arr[i]%k;
                min_ope = min(min_ope, curr_ope);
                if(min_ope == 0) break;
            }
            cout << min_ope << endl;
        }
        //if we have k == 4 then we can either have multiple of 4 or we can also have 2 
        //multiples of 2 so we can minimize the number of operations like below
        else {
            int multiple_of_2 = 0, multiple_of_4 = 0;
            for(int i=0; i<n; i++) {
                if(arr[i] % 4 == 0) {
                    multiple_of_4++;
                    break;
                }
                else if(arr[i] % 2 == 0) {
                    multiple_of_2++;
                    if(multiple_of_2 == 2) break;
                }
            }
            if(multiple_of_4 == 1 || multiple_of_2 == 2) {
                cout << 0 << endl;
            }else if(multiple_of_2 == 1) {
                cout << 1 << endl;
            }else {
                int is_3_or_7 = 0;
                for(int i=0; i<n; i++) {
                    if(arr[i] == 3 || arr[i] == 7) {
                        is_3_or_7 = 1;
                        break;
                    }
                }
                if(is_3_or_7) cout << 1 << endl;
                else cout << 2 << endl;
            }
        }
    }
    return 0;
}