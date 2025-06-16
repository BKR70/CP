/** SQRT decom. with MO's algo for finding unique number **/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
int rootN;
struct Q {
    int idx, l, r;
} q[N];

bool comp(Q q1, Q q2) {
    if(q1.l/rootN == q2.l/rootN) {
        return q1.r < q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}
int32_t main() {
    int n; cin >> n;
    vector<int> ar(n);

    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    rootN = sqrtl(n);
    int queries;  cin >> queries;

    for(int i=0; i<queries; i++) {
        int l, r; cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q+queries, comp);
    vector<int> vec(queries);
    int cur_l = 0, cur_r = -1, l, r;
    vector<int> mp(1000004,0);
    int ans = 0;
    for(int i=0; i<queries; i++) {
        l = q[i].l;
        r = q[i].r;
        l--, r--;
        while(cur_r < r) {
            cur_r++;
            mp[ar[cur_r]]++;
            if(mp[ar[cur_r]] == 1) {
                ans++;
            }
        }
        while(cur_l > l) {
            cur_l--;
            mp[ar[cur_l]]++;
            if(mp[ar[cur_l]] == 1) {
                ans++;
            }
        }
        while(cur_l < l) {
            mp[ar[cur_l]]--;
            if(mp[ar[cur_l]] == 0) {
                ans--;
            }
            cur_l++;
        }
        while(cur_r > r) {
            mp[ar[cur_r]]--;
            if(mp[ar[cur_r]] == 0) ans--;
            cur_r--;
        }
        vec[q[i].idx] = ans;
    }
    for(int i=0; i<queries; i++) {
        cout << vec[i] << endl;
    }
    return 0;
}
