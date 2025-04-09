#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a({100, 9, 10, 9});
    set<int> se;
    for (auto x: a) se.insert(x);
    map<int, int> mp;
    int id = 0;
    for (auto x: se) {
        mp[x] = ++id;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
        cout << a[i] << ' ';
    }
    return 0;
}
