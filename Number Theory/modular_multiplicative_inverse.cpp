/// Source : LUV Course
/// There are N children and K toffees. K < N
/// Count the number of ways to distribute toffee
/// among N students such that each students get 1 toffee only.
/// N < 10^6, K < N < 10^6 , M = 10^9+7
/// Q = 10^5
/// Calculation of nCr = n! / (r!*(n-r)!)

#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int N = 1e6+10;
int fact[N];
int binexp(int a,int b,int M) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = (1LL * res * a) % M;
        }
        a = (1ll * a * a) % M;
        b >>= 1;
    }
    return res;
}
int main() {
    fact[0] = 1;
    for(int i=1; i<N; i++) {
        fact[i] = (fact[i-1]*1LL*i) % M;
    }
    int q; cin >> q;
    while(q--) {
        int n, r; cin >> n >> r;
        int ans = fact[n];
        int den = (fact[n-r]*1LL*fact[r]) % M;
        ans = (ans * 1LL * binexp(den,M-2,M)) % M;
        cout << ans << endl;
    }
    return 0;
}
