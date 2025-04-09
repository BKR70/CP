#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define srt(av) sort(av.begin(),av.end())
#define rsrt(av) sort(av.rbegin(),av.rend())
#define rev(av) reverse(av.begin(),av.end())
#define pii pair<int,int>
#define endl '\n'
#define NO cout<<"NO"<<nl
#define YES cout<<"YES"<<nl
#define ff first
#define ss second
#define MOD 1e9+7
using namespace std;
struct cmp {
    bool operator() (pair<int,int>a, pair<int,int>b) const {
        int lna = a.ss - a.ff + 1, lnb = b.ss - b.ff + 1;
        if(lna == lnb) return a.ff < b.ff;
        else return lna > lnb;
    }
};
void p_solved() {
     int n, cnt = 1; cin >> n;
     int ar[n+1];
     set<pair<int,int>,cmp> st;
     st.insert({1,n});
     while(st.size() > 0) {
        auto val = *st.begin();
        st.erase(st.begin());
        int l = val.ff, r = val.ss;
        int mid = (l+r)/2;
        ar[mid] = cnt++;
        if(l < mid) st.insert({l, mid-1});
        if(mid < r) st.insert({mid+1, r});
     }
     for(int i=1; i<=n; i++) {
        cout << ar[i] << " ";
     }
     cout << endl;
}
int32_t main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        p_solved();
    }
    return 0;
}
