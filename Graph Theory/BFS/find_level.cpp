#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define srt(av) sort(av.begin(),av.end())
#define rsrt(av) sort(av.rbegin(),av.rend())
#define nl "\n"

using namespace std;
vector<ll> v[500];
ll dis[500], vis[500];
void BFS(ll node) {
    dis[node] = 0;
    vis[node] = 1;
    queue<ll> q;
    q.push(node);
    while(q.size()>0) {
        ll cur = q.front();
        q.pop();
        for(ll child:v[cur]) {
            if(vis[child]==0) {
                dis[child] = dis[cur]+1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n,m,x,y;
    cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    BFS(1);
    for(ll i=1; i<=n; i++) {
        cout << dis[i] << nl;
    }
    return 0;
}
