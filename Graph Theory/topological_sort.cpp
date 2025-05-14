/*
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define srt(av) sort(av.begin(),av.end())
#define rsrt(av) sort(av.rbegin(),av.rend())
#define nl "\n"
#define NO cout<<"NO"<<nl
#define YES cout<<"YES"<<nl
#define MOD 1e9+7
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll vis[1000];
vector<ll> v[1000];
list<ll> li;
void dfs(ll node){
    vis[node] = 1;
    for(ll j=0; j<(ll)v[node].size(); j++){
        if(vis[v[node][j]]==0){
            dfs(v[node][j]);
        }
    }
    li.pf(node);
}
int main()
{
    init_code();
    ios::sync_with_stdio(false); cin.tie(0);
    ll n,m; cin>>n>>m;
    while(m--){
        ll x,y; cin>>x>>y;
        v[x].pb(y);
    }
    for(ll i=n; i>=1; i--){
        rsrt(v[i]);
    }
    for(ll i=n; i>=1; i--){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(auto val:li){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define srt(av) sort(av.begin(),av.end())
#define rsrt(av) sort(av.rbegin(),av.rend())
#define nl "\n"
#define NO cout<<"NO"<<nl
#define YES cout<<"YES"<<nl
#define MOD 1e9+7
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll vis[1000];
vector<ll> v[1000];
list<ll> li;
void dfs(ll node){
    vis[node] = 1;
    for(auto child : v[node]) {
        if(vis[child]==0){
            dfs(child);
        }
    }
    li.pf(node);
}
int main()
{
    init_code();
    ios::sync_with_stdio(false); cin.tie(0);
    ll n,m; cin>>n>>m;
    while(m--){
        ll x,y; cin>>x>>y;
        v[x].pb(y);
    }

    for(ll i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(auto val:li){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
