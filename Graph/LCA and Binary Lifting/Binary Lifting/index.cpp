/** Binary lifting For finding lca of two nodes a and b. **/
#include<bits/stdc++.h>
using namespace std;
const int MX = 105;
vector<int> g[MX];
int memo[MX][20], lev[MX];
int n, Log;

void dfs(int u, int p) {
    memo[u][0] = p;
    for(int i=1; i<=Log; i++) {
        /*
        if(memo[u][i-1] == -1)
            memo[u][i] = -1;                        /// when distance is not power of two
        else                                        /// from a vertex then it's (-1). just for matrix checking
            memo[u][i] = memo[ memo[u][i-1] ][i-1];
        */
        memo[u][i] = memo[ memo[u][i-1] ][i-1];
    }
    for(auto v: g[u]) {
        if(v != p) {
            lev[v] = lev[u]+1;
            dfs(v, u);
        }
    }
}
int lca(int u, int v) {
    if(lev[u] < lev[v]) {
        swap(u,v);
    }
    for(int i=Log; i>=0; i--) {
        if((lev[u] - pow(2,i)) >= lev[v] ) {
            u = memo[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i=Log; i>=0; i--) {
        if(memo[u][i] != memo[v][i]) {
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}
int main() {
    cin >> n;
    Log = (int)ceil(log2(n));
//    cout << Log << endl;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(memo,-1,sizeof(memo));
    dfs(1,1);
//    for(int i=1; i<=n; i++) {
//        for(int j=0; j<=Log; j++) {
//            cout << memo[i][j] << ' ';        /// show matrix output
//        }
//        cout << endl;
//    }

    int q; cin >> q;
    while(q--) {
        int u,v; cin >> u >> v;
        cout << lca(u,v) << endl;
    }
    return 0;
}
