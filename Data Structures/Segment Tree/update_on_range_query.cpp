#include<bits/stdc++.h>
#define mx 100001
using namespace std;

int arr[mx];
int tree[mx*4];
void func(int node, int b, int e) {
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
int range_sum(int node, int b, int e,int i,int j) {
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j){
        return tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int val1= range_sum(left,b,mid,i,j);
    int val2= range_sum(right,mid+1,e,i,j);
    return val1+val2;
}
void update_query(int node,int b,int e,int pos,int new_val) {
    if(pos>e || pos<b)
        return;
    if(b==e){
        tree[node] = new_val;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update_query(left,b,mid,pos,new_val);
    update_query(right,mid+1,e,pos,new_val);
    tree[node] = tree[left]+tree[right];
}
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    func(1,1,n);
    cout<<range_sum(1,1,n,3,5)<<endl;
    update_query(1,1,n,5,25);
    cout<<range_sum(1,1,n,3,5)<<endl;

    return 0;
}
