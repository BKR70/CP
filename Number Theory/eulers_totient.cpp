#include<bits/stdc++.h>
using namespace std;

void num_coprime(int n) {
    int ans = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            while(n%i==0) {
                n/=i;
            }
            ans*=(i-1);
            ans/=i;
        }
    }
    if(n>1) {
        ans*=(n-1);
        ans/=n;
    }
    cout<<ans<<endl;
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        num_coprime(n);
    }
    return 0;
}
