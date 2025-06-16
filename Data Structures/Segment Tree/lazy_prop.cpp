#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];

struct info {
    long long prop, sum;
} tree[mx*4];

void func(int node, int b, int e){
    if(b==e){
        tree[node].sum = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    func(left,b,mid);
    func(right,mid+1,e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
int range_sum(int node, int b, int e,int i,int j,int carry = 0){
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j){
        return tree[node].sum + carry * (e-b+1);
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int val1= range_sum(left,b,mid,i,j,carry+tree[node].prop);
    int val2= range_sum(right,mid+1,e,i,j,carry+tree[node].prop);
    return val1 + val2;
}
void update_query(int node,int b,int e,int i,int j,int new_val){
    if(i>e || j<b)
        return;
    if(b >= i && e <= j){
        tree[node].sum += ((e-b+1)*new_val);
        tree[node].prop += new_val;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update_query(left,b,mid,i,j,new_val);
    update_query(right,mid+1,e,i,j,new_val);
    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (e-b+1);
}
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    func(1,1,n);
    cout<<range_sum(1,1,n,3,5)<<endl;
    update_query(1,1,n,1,4,3);
    cout<<range_sum(1,1,n,1,2)<<endl;
    update_query(1,1,n,1,2,2);
    cout<<range_sum(1,1,n,1,2)<<endl;
    return 0;
}
