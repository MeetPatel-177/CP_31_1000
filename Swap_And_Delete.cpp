#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int n = str.size();
        //here we have to compare the given string with the length of the string
        //which we will obtain after performing some operations
        int n0 = 0, n1 = 0;
        for(int i=0; i<n; i++) {
            if(str[i] == '0') n0++;
            else n1++;
        }
        //if n0 and n1 are same that means we can just interchange the positions internally
        //according to conditions and we will ended up getting required string without cost
        if(n0 == n1) cout << 0 << endl;
        //now if we have more 1's that means in order to get a balanced string we have to 
        //remove some or all 1's
        //now as we know maximum ones that will be allowed in resultant string will be 
        //number of zeroes we have as we can't have more than that zeroes
        //so we will ended up having maximum of i length string t that can be desired string
        //so we have to delete n - i elements for making it so it costs n - i
        else if(n1 > n0) {
            int current_ones = 0;
            int ones_allowed = n0;
            int i=0;
            while(i < n && current_ones < ones_allowed) {
                if(str[i] == '1') current_ones++;
                i++;
            }
            while(i < n && str[i] == '0') i++;
            int we_have_to_delete = n - i;
            cout << we_have_to_delete << endl;
        }
        //similarly can be explained using above theory
        else {
            int current_zeroes = 0;
            int zeroes_allowed = n1;
            int i=0;
            while(i < n && current_zeroes < zeroes_allowed) {
                if(str[i] == '0') current_zeroes++;
                i++;
            }
            while(i < n && str[i] == '1') i++;
            int we_have_to_delete = n - i;
            cout << we_have_to_delete << endl;
        }
    }
    return 0;
}