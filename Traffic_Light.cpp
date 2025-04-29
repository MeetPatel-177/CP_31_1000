#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; char c;
        cin >> n >> c;
        string str;
        cin >> str;
        if(c == 'g') cout << 0 << endl;
        else {
            int max_distance = 0;
            int first_g = 0;
            for(int i=0; i<n; i++) {
                if(str[i] == 'g') {
                    first_g = i;
                    break;
                }
            }
            int i =0;
            int curr_distance = 0;
            while(i < n) {
                int j = i;
                char ch = str[i];
                if(ch == c) {
                    while(i < n && str[i] != 'g') {
                        i++;
                    }
                    if(i < n) curr_distance = i - j;
                    else {
                        curr_distance = n - (j - first_g);
                    }
                    max_distance = max(max_distance, curr_distance);
                }
                i++;
            }
            cout << max_distance << endl;
        }
    }
    return 0;
}