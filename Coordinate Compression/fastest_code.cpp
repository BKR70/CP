#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    vector<int> a = {100,9,10,10,9};
    vector<int> v = a;

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for(int i=0; i<a.size(); i++) {
        cout << upper_bound(v.begin(),v.end(),a[i])-v.begin() << " ";
    }

    return 0;
}
