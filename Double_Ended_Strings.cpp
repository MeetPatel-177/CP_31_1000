#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a,b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        int max_len = 0;
        //we can just delete from front and back so we cannot delete anything from between
        //of any substring that we pick so we just have to find the longest length substring
        //that is totally matched in both and that will remain at last so the number of 
        //characters we have to delete will be (total - 2*remaining)
        //as remaining number of characters will be present in both a and b
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < m) {
                if(b[j] == a[i]) {
                    int k = i;
                    int h = j;
                    int curr_len = 0;
                    while(h < m && k < n && b[h] == a[k]) {
                        h++;
                        k++;
                        curr_len++;
                    }
                    max_len = max(max_len, curr_len);
                }
                j++;
            }
            i++;
        }
        int need_to_delete = (n+m) - 2*max_len;
        cout << need_to_delete << endl;
    }
    return 0;
}