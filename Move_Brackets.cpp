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
        stack<char>stk;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(str[i] == '(') {
                stk.push(str[i]);
            }
            else if(!stk.empty()) {
                stk.pop();
            }else {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}