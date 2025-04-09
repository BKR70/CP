#include<bits/stdc++.h>
using namespace std;

#define MX 110
vector<int> graph[MX];
bool vis[MX];
int dist[MX];

void bfs(vector<int> sources) {
    queue<int> Q;
    for(int i=0; i<sources.size(); i++) {
        int source = sources[i];
        vis[source] = 1;
        dist[source] = 0;
        Q.push(source);
    }
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(int i=0; i<graph[node].size(); i++) {
            int next = graph[node][i];
            if(vis[next] == 0) {
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                Q.push(next);
            }
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    for(int i=1; i<=e; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int nofsource; cin >> nofsource;
    vector<int> sources;
    for(int i=1; i<=nofsource; i++) {
        int x; cin >> x;
        sources.push_back(x);
    }
    bfs(sources);
    for(int i=1; i<=n; i++) {
        if(dist[i] != 0)
            cout << i << " dist. from booth is " << dist[i] << '\n';
    }
    return 0;

}
