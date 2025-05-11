/// a <= 10^100000      b <= 10^9

#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a; int b;
    cin >> a >> b;
    int ans = 0;
    for(int i=0; i<a.size(); i++) {
        ans = (ans * 10LL % b + (a[i]-'0')) % b;
    }
    if(ans == 0) {
        cout << "a is divisible by b\n";
    }
    else {
        cout << "Not divisible by b\n";
    }

    return 0;
}
