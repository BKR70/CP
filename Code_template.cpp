#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define endl '\n'
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define ff first
#define ss second
#define MOD 1e9+7
#define all(v) v.begin(),v.end()
#define srt(av) sort(av.begin(),av.end())
#define rsrt(av) sort(av.rbegin(),av.rend())
#define rev(av) reverse(av.begin(),av.end())
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void p_solved() {
  
}
int32_t main() {   
    ios_base::sync_with_stdio(false);  cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        p_solved();
    }
    return 0;
}


//cout << "Case " << ++cnt << ": ";

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("cfinput.txt", "r", stdin);  freopen("cfoutput.txt", "w", stdout);
    #endif
}

ll power(ll base,ll n) {
    ll ans = 1;
    while(n) {
        if(n&1){ ans *=base; }
        base*=base;
        n = n>>1;
    }
    return ans;
}






#include<bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;
void solve() {


}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin>>t;
    //int cnt = 0;
    while(t--){
	//cout << "Case " << ++cnt << ": ";
        solve();
    }
    return 0;
}


				/// DFS Tree code 

#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> g[N];
int col[N];
void dfs(int v,int p=0) {
    for(auto c:g[v]) {
        if(c == p) continue;
        dfs(c,v);
    }
}
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> col[i];
    }
    for(int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    return 0;
}

				/// Matrix movement

int di[] = {0,0,-1,+1};
int dj[] = {-1,+1,0,0};

bool isvalid(int n,int m){
    return n>=0 && m>=0 && n<x && m<y;
}
