#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> g[N];
int dep[N];
int mx, node, node2, ans;
void dfs1(int u, int p) {
    dep[u] = dep[p] + 1;
    if(dep[u] > mx) {
        mx = dep[u];
        node = u;
    }
    for(auto v:g[u]) {
        if(v != p) {
            dfs1(v,u);
        }
    }
}
void dfs2(int u, int p) {
   dep[u] = dep[p] + 1;
//    ans = max(ans, dep[u] - 1);
    if(dep[u] > ans) {
        ans = dep[u];
        node2 = u;
    }
    for(auto v: g[u]) {
        if(v != p) {
            dfs2(v,u);
        }
    }
}
int main() {
    int n; cin >> n;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    cout << node << " ";
    dfs2(node,0);
    cout << node2 << '\n';
    cout << ans << '\n';

    return 0;
}
