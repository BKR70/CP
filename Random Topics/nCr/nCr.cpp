#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,r; cin >> n >> r;
    double ans = 1;
    for(int i=1; i<=r; i++) {
        ans = ans*(n-r+i)/i;
    }
    cout << (int)ans << endl;

    return 0;
}
