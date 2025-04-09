#include<bits/stdc++.h>
using namespace std;

void SieveofEratosthenes(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=n; p++){
        if(prime[p]==true){
            for(int i=p*p; i<=n; i=i+p)
                prime[i] = false;

        }
    }
    for(int p=2; p<=n; p++){
        if(prime[p])
            cout<<p<<" ";
    }
    cout<<endl;
}
int main()
{
    int t=1;
    while(t--){
        int n;
        cin>>n;
        SieveofEratosthenes(n);
    }
    return 0;
}
