#include<bits/stdc++.h>
using namespace std;
void div(string s,int mod) {
    int ans=0;
    for(int i=0; i<s.size(); i++) {
        ans = ans*10 + (s[i]-'0');
        ans = ans % mod;
    }
    if(ans%mod == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int mod;
        cin >> s >> mod;
        div(s,mod);
    }
    return 0;
}
