#include<bits/stdc++.h>
#define MX 105
using namespace std;
struct node {
    int v;
    int w;
};
vector<node>G[MX];
bool vis[MX];
int n;
class cmp {
public:
    bool operator()(node &A,node &B){
        return A.w > B.w;
    }
};
void Prims(int s) {
    priority_queue<node,vector<node>,cmp> pq;
    pq.push({s,0});
    int cnt = 0, ans = 0;
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        int val = cur.v;
        int cost = cur.w;
        if(vis[val]==1) continue;
        vis[val] = 1;
        ans += cost;
        cout << val << " ";
        cnt++;
        if(cnt == n) break;         /// eta na dileo hoy cause n ta vertex er besi kkhnoi visit korbe na

        for(int i=0; i<G[val].size(); i++) {
            int nxt = G[val][i].v;
            int nxtCost = G[val][i].w;
            if(vis[nxt]==0){
                pq.push({nxt,nxtCost});
            }
        }
    }
    cout << endl;
    cout << "Minimum cost is : " << ans << endl;
}
int main() {
    int e; cin >> n >> e;
    for(int i=1; i<=e; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    Prims(1);

    return 0;
}
