#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> g[N];
bool vis[N];
bool Cycle(int node, int par) {
    vis[node] = true;
    for (int ch : g[node]) {
        if (!vis[ch]) {
            if (Cycle(ch, node)) return true;
        } 
        else if (ch != par) {
            return true;             // cycle detected
        }
    }
    return false;
}
