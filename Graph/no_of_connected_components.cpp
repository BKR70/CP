#include<bits/stdc++.h>
using namespace std;
vector<int> v[1002];
int vis[1003];

void DFS(int node) {
    vis[node] = 1;
    for(auto child:v[node]) {
        if(vis[child] == 0)
            DFS(child);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,e,x,y;
    cin >> n >> e;
    while(e--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ct = 0;
    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            ct++;
            DFS(i);
        }
    }
    cout << ct << endl;

    return 0;
}
