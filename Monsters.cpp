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
        //we will keep a map not an unordered map as we want to answer in sorted order
        //we have to think about which one will gets empty first so as per given conditions
        //we will ended up having all values with remainder of k after applying some operations
        //so we just have to think about it
        map<int,vector<int>>remainder;
        for(int i=0; i<n; i++) {
            remainder[arr[i]%k].push_back(i+1);
        }
        //now first if we have anything that has zero remainder that means it is the highest 
        //value that exist currently so it will just ended up by killing monster first
        //so we will first print all the indices that has zero remainder
        if(remainder.find(0) != remainder.end()) {
            for(int i=0; i<remainder[0].size(); i++) {
                cout << remainder[0][i] << " ";
            }
        }
        //then we will iterate in map from last as we have to print the largest remainder first
        //and then second largest and so on but we will not print zero remainder again
        //so we have to take care of it
        //for reverse traverse we have to use rbegin and rend
        for(auto it = remainder.rbegin(); it != remainder.rend(); it++) {
            if(it->first != 0) {
                for(int j=0; j<it->second.size(); j++) {
                    cout << it->second[j] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}