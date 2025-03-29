#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        //firstly i thought that when we encounter first duplicate character we just break
        //out from first loop and will consider other all characters in second loop but in
        //that if we are looking for very bigger n then it will flop in many cases
        //maximum answer we can expect is 26+26 = 52 and if we break first loop very early
        //but in string we are able to take 52 sum then there our code fails
        //so now the approach is of thinking about prefix and suffix sum
        //in prefix we will store forward unique characters and in suffix we will store backward
        //unique characters and we will partition string from every indices but only non empty
        //and then keep track of what maximum we can get
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        vector<int>flag1(26,0);
        prefix[0] = 1;
        flag1[str[0] - 'a'] = 1;
        for(int i=1; i<n; i++) {
            if(flag1[str[i] - 'a'] == 0) {
                prefix[i] = 1;
                flag1[str[i] - 'a'] = 1;
            }
            prefix[i] += prefix[i-1];
        }
        vector<int>flag2(26,0);
        suffix[n-1] = 1;
        flag2[str[n-1] - 'a'] = 1;
        for(int i=n-2; i>=0; i--) {
            if(flag2[str[i] - 'a'] == 0) {
                suffix[i] = 1;
                flag2[str[i] - 'a'] = 1;
            }
            suffix[i] += suffix[i+1];
        }
        //if we break from any i then we will ended up having prefix[i] + suffix[i+1] unique
        //characters in resulting split
        int maxi = 0;
        int curr = 0;
        for(int i=0; i<n-1; i++) {
            curr = prefix[i] + suffix[i+1];
            maxi = max(maxi,curr);
        }
        cout << maxi << endl;
    }
    return 0;
}