#include<bits/stdc++.h>
using namespace std;
long long dp[500][500];
long long res(int n,int r) {
    if( r > n) return 0;
    if(r==0 || r==n) return 1;
    if(dp[n][r] != -1) return dp[n][r];

    long long ans = res(n-1,r-1) + res(n-1,r);
    return dp[n][r] = ans;
}
int main() {
    int n,r; cin >> n >> r;
    memset(dp,-1,sizeof(dp));
    cout << res(n,r) << endl;
    return 0;
}
