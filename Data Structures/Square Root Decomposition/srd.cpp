#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int len = sqrtl(n)+1;
    vector<int> v(n),sq(len);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        sq[i/len] += v[i];
    }
    //cout << len << endl;
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        l--, r--;
        int sum = 0;
        for(int i=l; i<=r; ) {
            if(i%len==0 && i+len-1<=r) {
                sum += sq[i/len];
                i += len;
            }
            else {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
