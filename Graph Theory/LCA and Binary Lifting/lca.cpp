#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
int par[N];

void dfs(int n,int p=-1) {
    par[n] = p;
    for(auto c:g[n]) {
        if(c == p) continue;
        dfs(c,n);
    }
}
vector<int> path(int v) {
    vector<int> ans;
    while(v != -1) {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n; cin >> n;
    for(int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int x,y; cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mns = min(path_x.size(),path_y.size());
    int lca = 0;
    for(int i=0; i<mns; i++) {
        if(path_x[i] == path_y[i]) {
            lca = path_x[i];
        }
        else {
            break;
        }
    }
    cout << lca << '\n';
    return 0;
}
