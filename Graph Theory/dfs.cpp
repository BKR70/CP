#include<bits/stdc++.h>
using namespace std;
vector<int> v[1002];
int vis[1003];

void DFS(int node) {
    vis[node] = 1;
    cout << node << " ";
    for(int i=0; i<v[node].size(); i++) {
        int child = v[node][i];
        if(vis[child] == 0)
            DFS(child);
    }
}
int main() {
    int n, e, x, y;
    cin >> n >> e;
    while(e--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    return 0;
}
