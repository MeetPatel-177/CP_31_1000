#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        //we have to merge two arrays like that in the resulting merged array we will ended up
        //having maximum consecutive same values so the logic is we will have maximum 
        //consecutive same values of any number only when we will find max_continuous in a and b
        //then we will add both into each other and then we will find maximum of all
        vector<int>max_continuous_in_a(2*n+1,0), max_continuous_in_b(2*n+1,0);
        int i = 0;
        while(i < n) {
            int value = a[i];
            int curr_continuous = 1;
            while(i < n-1 && a[i] == a[i+1]) {
                curr_continuous++;
                i++;
            }
            max_continuous_in_a[value] = max(curr_continuous,max_continuous_in_a[value]);
            i++;
        }
        i = 0;
        while(i < n) {
            int value = b[i];
            int curr_continuous = 1;
            while(i < n-1 && b[i] == b[i+1]) {
                curr_continuous++;
                i++;
            }
            max_continuous_in_b[value] = max(curr_continuous, max_continuous_in_b[value]);
            i++;
        }
        //this array is not necessary as we can just add values of b in a but for better
        //clarity we declare an additional array here
        vector<int>tot_max_continuous(2*n+1,1);
        for(int i=0; i<2*n+1; i++) {
            tot_max_continuous[i] = max_continuous_in_a[i] + max_continuous_in_b[i];
        }
        int maxi = *max_element(tot_max_continuous.begin(), tot_max_continuous.end());
        cout << maxi << endl;
    }
    return 0;
}