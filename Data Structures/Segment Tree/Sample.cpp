#include<bits/stdc++.h>
#define mx 100001
using namespace std;

int arr[mx];
int tree[mx*4];
void func(int node, int b, int e){
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    func(left,b,mid);
    func(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
}
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    func(1,1,n);
    for(int i=0; i<=n*4; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    return 0;
}
