#include<bits/stdc++.h>
using namespace std;
const int MX = 105;
int par[MX], Rank[MX];
int n;
vector<pair<int,pair<int,int>>> G;
void init() {
    for(int i=1; i<=n; i++) {
        par[i] = i;
        Rank[i] = 1;
    }
}
int Find(int i) {
    if(par[i] == i)
        return i;
    else
        return par[i] = Find(par[i]);
}
void Union(int x, int y) {
    int s1 = Find(x);
    int s2 = Find(y);
    if(s1 != s2) {
        if(Rank[s1] > Rank[s2]) {
            par[s2] = s1;
        }
        else if(Rank[s2] > Rank[s1]) {
            par[s1] = s2;
        }
        else {
            par[s2] = s1;
            Rank[s1] += 1;
        }
    }
}

void Kruskals_mst() {
    int ans = 0, cnt = 0;
    for(auto edge:G) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(Find(u) != Find(v)) {
            Union(u,v);
            ans += w;
            cout << "Connect vertex " << u << " and " << v << " and weight is " << w << endl;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout << "Minimum cost is : " << ans << endl;
}


int32_t main() {
    int m; cin >> n >> m;
    init();
    for(int i=1; i<=m; i++) {
        int u, v, w; cin >> w >> u >> v;
        G.push_back({w,{u, v}});
    }
    sort(G.begin(),G.end());
    Kruskals_mst();

    return 0;
}
