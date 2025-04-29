#include <bits/stdc++.h>
using namespace std;

int divide(int a, int b) {
    int count = 0;
    while(a != 0) {
        a /= b;
        count++;
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        int min_ope = INT_MAX;
        int curr_ope = INT_MAX;
        int curr_b = b;
        //we are going from b to that b where we found out that min ope is less than the 
        //difference between curr_b and b because from there we will find more operations
        //always so we can never find min ope from that b onwards
        //here the catch is first i try to use log function as it directly gives the number 
        //of operations to make any number zero but as it use float values so it lacks
        //at precision it stores 3 but still shows us 2 because internally it stores 2.999992
        //so we have to implement a function for count div_ope rather than doing log calculations
        //once again always try to ignore doing calculations in float and double
        //they are really fucking horrible 
        while(1) {
            if((curr_b - b) > min_ope) {
                break;
            }
            if(curr_b != 1) {
                int add_ope = (curr_b - b);
                int div_ope = divide(a, curr_b);
                curr_ope = add_ope + div_ope;
                min_ope = min(min_ope, curr_ope);
            }
            curr_b = curr_b + 1;
        }
        cout << min_ope << endl;
    }
    return 0;
}