#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> adj[N];
bool vis[N], cur[N];
bool Cycle(int node) {
    vis[node] = true;
    cur[node] = true;
  
    for (int ch : adj[node]) {
        if (!vis[ch]) {
            if (Cycle(ch)) return true;
        } 
        else if (cur[ch]) {
            return true;                       // cycle detected
        }
    }
    cur[node] = false;
    return false;
}
