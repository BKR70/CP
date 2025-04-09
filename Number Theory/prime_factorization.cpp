#include<bits/stdc++.h>
using namespace std;

void prime_factorization(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            int ct=0;
            while(n%i==0) {
                ct++;
                n/=i;
            }
            cout<<i<<"^"<<ct<<", ";
        }
    }
    if(n>1) cout<<n<<"^"<<1<<endl;
    else cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        prime_factorization(n);
    }
    return 0;
}
