#include<bits/stdc++.h>
#define ll long long
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
        pw[i].first = 1LL*pw[i-1].first*p1 % mod1;
        pw[i].second = 1LL*pw[i-1].second*p2 % mod2;
    }
    ip1 = power(p1,mod1-2,mod1);
    ip2 = power(p2,mod2-2,mod2);
    ipw[0] = {1,1};
    for(int i=1; i<N; i++) {
        ipw[i].first = 1LL*ipw[i-1].first*ip1 % mod1;
        ipw[i].second = 1LL*ipw[i-1].second*ip2 % mod2;
    }
}

pair<int,int> string_hash(string s) {
    int n = s.size();
    pair<int,int> hs({0,0});
    for(int i=0; i<n; i++) {
        hs.first += 1LL*s[i]*pw[i].first%mod1;
        hs.first %= mod1;
        hs.second += 1LL*s[i]*pw[i].second%mod2;
        hs.second %= mod2;
    }
    return hs;
}

pair<int,int> pref[N];
void build(string s) {
    int n = s.size();
    for(int i=0; i<n; i++) {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i > 0) {
            pref[i].first = (pref[i].first + pref[i-1].first) % mod1;
        }
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i > 0) {
            pref[i].second = (pref[i].second + pref[i-1].second) % mod2;
        }
    }
}
pair<int,int> get_hash(int i,int j) {
    assert(i <= j);
    pair<int,int> hs({0,0});
    hs.first = pref[j].first;
    if(i > 0) hs.first = (hs.first - pref[i-1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;

    hs.second = pref[j].second;
    if(i > 0) hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}
int32_t main() {
    prec();
    string s;
    getline(cin, s);
    build(s);
    int n = s.size();
    string pattern; cin >> pattern;
    int m = pattern.size();
    auto m_hash = string_hash(pattern);
    for(int i=0; i+m-1<n; i++) {
        auto n_hash = get_hash(i,i+m-1);
        if(m_hash == n_hash) {
            cout << "Index from " << i << endl;
        }
    }
    return 0;
}
