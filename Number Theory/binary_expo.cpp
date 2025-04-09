#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int m = 1e9+7;
ll power(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll b, p;
        cin >> b >> p;
        cout << power(b,p) << endl;
    }
    return 0;
}
