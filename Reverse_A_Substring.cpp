#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int isPossible = 0;
    for(int i=0; i<n-1; i++) {
        if(str[i] > str[i+1]) {
            isPossible = 1;
            cout << "YES" << endl;
            cout << i+1 << " " << i+2 << endl;
            break;
        }
    }
    if(!isPossible) cout << "NO" << endl;
    return 0;
}