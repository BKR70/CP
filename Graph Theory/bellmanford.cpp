#include <bits/stdc++.h>
using namespace std;
vector<int> g[1005];
vector<int> bellmanFord(int V, int E, int src) {
	vector<int> dist(V, 1e9);
	dist[src] = 0;
	for (int i = 1; i <= V; i++) {
		for (int j=0; j<E; j++) {
			int u = g[j][0];
			int v = g[j][1];
			int wt = g[j][2];
			if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                if(i == V)
                    return {-1};
                dist[v] = dist[u] + wt;
            }
		}
	}
    return dist;
}

int main() {
    int V, E; cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[i].push_back(u);
        g[i].push_back(v);
        g[i].push_back(w);
    }
    vector<int> ans = bellmanFord(V, E, 0);
    for (int dist : ans)
        cout << dist << " ";

    return 0;
}
