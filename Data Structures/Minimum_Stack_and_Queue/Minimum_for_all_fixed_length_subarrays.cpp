// We are given an array ar of length n and a given m <= n. We have to find the minimum of each subarray of length m in this array.

#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);  cin.tie(0);
    int n,m; cin >> n >> m;
    int ar[n];
    stack<pair<int,int>> st1, st2;

    for(int i=0; i<n; i++) {
        cin >> ar[i];
        if(i < m) {
            int Min = st1.empty() ? ar[i] : min(ar[i], st1.top().second);
            st1.push({ar[i], Min});
        }
    }
    cout << st1.top().second << " ";

    for(int i=m; i<n; i++) {
        if(st2.empty()) {
            while(!st1.empty()) {
                int val = st1.top().first;
                st1.pop();
                int Min = st2.empty() ? val : min(val, st2.top().second);
                st2.push({val, Min});
            }
        }
        st2.pop();
        int mn = st1.empty() ? ar[i] : min(ar[i], st1.top().second);
        st1.push({ar[i], mn});

        if(st1.empty() or st2.empty()) {
            cout << (st2.empty() ? st1.top().second : st2.top().second) << " ";
        }
        else {
            cout << min(st1.top().second, st2.top().second )<< " ";
        }
    }
    return 0;
}
