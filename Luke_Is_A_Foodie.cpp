#include <bits/stdc++.h>
using namespace std;

//visualization based problem
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //here we have to play with the ranges as v can be anything from the range 
        //so first range of v is [arr[0] -x, arr[0] +x]
        pair<int,int>range = {arr[0] - x, arr[0] + x};
        int i = 1;
        int count = 0;
        //now when both ranges don't have any point in common that is first condition
        //then we have to change our v and we will take range of v from that element
        //if we have something common between both ranges then we will just shrink our
        //range as per below [max(min,min), min(max,max)]
        while(i < n) {
            pair<int,int>curr_range = {arr[i] - x, arr[i] + x};
            if(range.second < curr_range.first || range.first > curr_range.second) {
                count++;
                range = {arr[i] - x, arr[i] + x};
            }else {
                range = {max(range.first, curr_range.first), min(range.second, curr_range.second)};
            }
            i++;
        }
        cout << count << endl;
    }
    return 0;
}