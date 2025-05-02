#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
const int N = 1e6+9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
int power(ll n, ll k, int mod) {
    int ans = 1%mod;
    n %= mod;
    if(n < 0 ) {
        n += mod;
    }
    while(k) {
        if(k&1){
            ans = (ll)ans*n%mod;
        }
        n = (ll)n*n%mod;
        k = k>>1;
    }
    return ans;
}

int ip1,ip2;
pair<int,int> pw[N],ipw[N];
void prec() {
    pw[0] = {1,1};
    for(int i=1; i<N; i++) {
        pw[i].ff = 1LL*pw[i-1].ff*p1 % mod1;
        pw[i].ss = 1LL*pw[i-1].ss*p2 % mod2;
    }
    ip1 = power(p1,mod1-2,mod1);
    ip2 = power(p2,mod2-2,mod2);
    ipw[0] = {1,1};
    for(int i=1; i<N; i++) {
        ipw[i].ff = 1LL*ipw[i-1].ff*ip1 % mod1;
        ipw[i].ss = 1LL*ipw[i-1].ss*ip2 % mod2;
    }
}

pair<int,int> pref[N],pref2[N];
void build(string s) {
    int n = s.size();
    for(int i=0; i<n; i++) {
        pref[i].ff = 1LL * s[i] * pw[i].ff % mod1;
        if(i > 0) {
            pref[i].ff = (pref[i].ff + pref[i-1].ff) % mod1;
        }
        pref[i].ss = 1LL * s[i] * pw[i].ss % mod2;
        if(i > 0) {
            pref[i].ss = (pref[i].ss + pref[i-1].ss) % mod2;
        }
    }
}
void build2(string s) {
    int n = s.size();
    for(int i=0; i<n; i++) {
        pref2[i].ff = 1LL * s[i] * pw[i].ff % mod1;
        if(i > 0) {
            pref2[i].ff = (pref2[i].ff + pref2[i-1].ff) % mod1;
        }
        pref2[i].ss = 1LL * s[i] * pw[i].ss % mod2;
        if(i > 0) {
            pref2[i].ss = (pref2[i].ss + pref2[i-1].ss) % mod2;
        }
    }
}

pair<int,int> get_hash(int i,int j) {
    assert(i <= j);
    pair<int,int> hs({0,0});
    hs.ff = pref[j].ff;
    if(i > 0) {
        hs.ff = (hs.ff - pref[i-1].ff + mod1) % mod1;
    }
    hs.ff = 1LL * hs.ff * ipw[i].ff % mod1;

    hs.ss = pref[j].ss;
    if(i > 0) {
        hs.ss = (hs.ss - pref[i-1].ss + mod2) % mod2;
    }
    hs.ss = 1LL * hs.ss * ipw[i].ss % mod2;
    return hs;
}
pair<int,int> get_hash2(int i,int j) {
    assert(i <= j);
    pair<int,int> hs({0,0});
    hs.ff = pref2[j].ff;
    if(i > 0) {
        hs.ff = (hs.ff - pref2[i-1].ff + mod1) % mod1;
    }
    hs.ff = 1LL * hs.ff * ipw[i].ff % mod1;

    hs.ss = pref2[j].ss;
    if(i > 0) {
        hs.ss = (hs.ss - pref2[i-1].ss + mod2) % mod2;
    }
    hs.ss = 1LL * hs.ss * ipw[i].ss % mod2;
    return hs;
}
int32_t main() {
    prec();
    string a,b; cin >> a >> b;      /// Same size for string a and b.
    build(a);
    build2(b);
    int ans = -1, n = a.size();
    int l = 0, r = n-1;

    while(l<=r) {
        int mid = r - (r-l)/2;
        if(get_hash(0,mid) == get_hash2(0,mid)) {
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    cout << ans+1 << "\n";

    return 0;
}
