#include<bits/stdc++.h>
#define MX 105
using namespace std;
struct node {
    int v;
    int w;
};
vector<node> G[MX];
bool vis[MX];
int dist[MX];
class cmp {
public:
    bool operator()(node &A, node &B) {
        return A.w > B.w;
    }
};
void dijkstra(int s) {
    priority_queue<node,vector<node>,cmp> pq;
    pq.push({s,0});
    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        int val = cur.v;
        int cost = cur.w;
        if(vis[val]==1) continue;
        dist[val] = cost;
        vis[val] = 1;

        for(int i=0; i<G[val].size(); i++) {
            int nxt = G[val][i].v;
            int nxtCost = G[val][i].w;
            if(vis[nxt]==0) {
                pq.push({nxt,cost+nxtCost});
            }
        }
    }
}
int main() {
    int n,e; cin >> n >> e;
    for(int i=1; i<=e; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    cout << "Enter source : ";
    int s; cin >> s;
    dijkstra(s);
    for(int i=1; i<=n; i++) {
        cout << "Node " << i << " Distance = " << dist[i] << endl;
    }
    return 0;
}
