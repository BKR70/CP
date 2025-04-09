#include<bits/stdc++.h>
using namespace std;
const int MX = 105;
vector<int> g[MX];
int memo[MX][20], lev[MX];
int n, Log;

void dfs(int u, int p) {
    memo[u][0] = p;
    for(int i=1; i<=Log; i++) {
        if(memo[u][i-1] == -1)
            memo[u][i] = -1;                        /// when distance is not power of two
        else                                        /// from a vertex then it's (-1). just for matrix checking
            memo[u][i] = memo[ memo[u][i-1] ][i-1];

    }
    for(auto v: g[u]) {
        if(v != p) {
            lev[v] = lev[u]+1;
            dfs(v, u);
        }
    }
}
int Kth_ancestor(int u, int k) {
    if(k > lev[u]) return -1;
    for(int i=Log; i>=0; i--) {
        if(k >= pow(2,i)) {
            u = memo[u][i];
            k -= pow(2,i);
        }
    }
    return u;
}
int main() {
    cin >> n;
    Log = (int)ceil(log2(n));
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(memo,-1,sizeof(memo));
    dfs(1,-1);
    cout << "Enter the number of queries : ";
    int q; cin >> q;
    while(q--) {
        int u,k; cin >> u >> k;         /** Kth ancestor of u */
        cout << Kth_ancestor(u,k) << endl;
    }
    return 0;
}
