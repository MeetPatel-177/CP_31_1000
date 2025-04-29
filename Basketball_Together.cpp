#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = n-1, j = 0;
    int teams = 0;
    while(j <= i) {
        int needed_people = d/arr[i] + 1;
        i--;
        j += (needed_people - 1);
        //why we wrote j <= i+1 here because if we are currently j == i then also it is
        //possible to have a pair of current two numbers 
        //eg. 2 3 {1,2} now needed will be 3/2 + 1 = 2 so i-- will be 0 and j += (needed - 1)
        //will be 1 so it is j <= i+1 so we have to consider this edge case
        if(j <= i+1) teams++;
    }
    cout << teams << endl;
    return 0;
}