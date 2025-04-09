#include<bits/stdc++.h>
using namespace std;
vector<int> vect[1000];
int dis[1000], vis[1000];

void dfs(int node, int d) {
    vis[node] = 1;
    dis[node] = d;
    for(auto child:vect[node]) {
        if(vis[child] == 0) {
            dfs(child, d+1);
        }
    }
}
int main() {
    int a,b,n,e;
    cin >> n >> e;
    while(e--) {
        cin >> a >> b;
        vect[a].push_back(b);
        vect[b].push_back(a);
    }
    int x;
    cin >> x;
    dfs(x,0);
    for(int i=1; i<=n; i++) {
        cout << x << " -> " << i << " = " << dis[i] << endl;
    }
    return 0;
}
