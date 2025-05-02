#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

gp_hash_table<int,int> mp;

int32_t main() {
    mp[2]++;
    mp[2]++;
    mp[2]++;
    mp[1]++;
    mp[1]++;
    mp[1]++;
    mp[1]++;
    cout << mp[1] << endl;
    for(auto x:mp) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
