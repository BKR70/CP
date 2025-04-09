/// All subtree queries
/// 1. precomputation   2. subtree sum queries    3. even odd counts in subtree and all other subtree queries

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
int sub_sum[N],ev_cnt[N];
void dfs(int v,int p=0) {
    sub_sum[v] += v;
    if(v%2==0) {            /// for even number count in a subtree
        ev_cnt[v] += 1;
    }
    for(auto c:g[v]) {
        if(c != p) {
            dfs(c,v);
            sub_sum[v] += sub_sum[c];
            ev_cnt[v] += ev_cnt[c];
        }
    }
}
int main() {
    int n; cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i=1; i<=n; i++) {
        cout << sub_sum[i] << " " << ev_cnt[i] << endl;
    }
    return 0;
}
