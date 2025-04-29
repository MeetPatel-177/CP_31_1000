#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int w,h;
        cin >> w >> h;
        vector<int>horizontal[2], vertical[2];
        //horizontal[0] will have points in lower horizontal line
        //horizontal[1] will have points in upper horizontal line
        //vertical[0] will have points in left vertical line
        //vertical[1] will have points in right vertical line
        for(int i=0; i<2; i++) {
            int k;
            cin >> k;
            while(k--) {
                int a;
                cin >> a;
                horizontal[i].push_back(a);
            }
        }
        for(int i=0; i<2; i++) {
            int k;
            cin >> k;
            while(k--) {
                int a;
                cin >> a;
                vertical[i].push_back(a);
            }
        }
        //pick two from lower horizontal line and one from upper horizontal line
        long long poss1 = 1LL*(horizontal[0][horizontal[0].size() - 1] - horizontal[0][0]) * h;
        //pick two from upper horizontal line and one from lower horizontal line
        long long poss2 = 1LL*(horizontal[1][horizontal[1].size() - 1] - horizontal[1][0]) * h;
        //pick two from left vertical line and one from right vertical line
        long long poss3 = 1LL*(vertical[0][vertical[0].size() - 1] - vertical[0][0]) * w;
        //pick two from right vertical line and one from left vertical line
        long long poss4 = 1LL*(vertical[1][vertical[1].size() - 1] - vertical[1][0]) * w;
        //these 4 are the only possibilities for maximum area
        long long maxi = max(max(poss1, poss2), max(poss4, poss3));
        cout << maxi << endl;
    }
    return 0;
}