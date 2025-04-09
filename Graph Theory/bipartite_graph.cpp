#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int vis[1000], col[1000];

bool dfs(int node, int c) {
    vis[node] = 1;
    col[node] = c;
    for(auto child : v[node]) {
        if(vis[child] == 0){
            dfs(child,1^c);
        }
        else if(col[node] == col[child]) {
            return false;
        }
    }
    //cout << node << " ";
    return true;
}
int main() {
    int n,e,x,y;
    cin >> n >> e;
    while(e--){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool ck = dfs(1,1);
    cout << endl;
    if(ck == true)
        cout << "Yes, The graph is Bipartite" << endl;
    else
        cout << "The graph isn't Bipartite" << endl;

    return 0;
}
