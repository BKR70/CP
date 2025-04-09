#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int in[1000], out[1000], vis[1000], ct=0;

void dfs(int node) {
    in[node] = ++ct;
    vis[node] = 1;
    for(int child:v[node]) {
        if(vis[child]==0)
            dfs(child);
    }
    out[node] = ++ct;
}
int main() {
    int n, m; cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=1; i<=n; i++) {
        cout<<"For "<<i<<" In time "<<in[i]<<" & out time "<<out[i]<<endl;
    }
    return 0;
}
