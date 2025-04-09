#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+3;
int rootN;
struct Q {
    int idx, l, r;
} q[N];

bool comp(Q q1, Q q2) {
    if(q1.l/rootN == q2.l/rootN) {
        return q1.r > q2.r;
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
    vector<int> ans(queries);
    int cur_l = 0, cur_r = -1, l, r;
    int cur_ans = 0;

    for(int i=0; i<queries; i++) {
        l = q[i].l;
        r = q[i].r;
        l--, r--;
        while(cur_r < r) {
            cur_r++;
            cur_ans += ar[cur_r];
        }
        while(cur_l > l) {
            cur_l--;
            cur_ans += ar[cur_l];
        }
        while(cur_l < l) {
            cur_ans -= ar[cur_l];
            cur_l++;
        }
        while(cur_r > r) {
            cur_ans -= ar[cur_r];
            cur_r--;
        }
        ans[q[i].idx] = cur_ans;
    }
    for(int i=0; i<queries; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
