#include<bits/stdc++.h>
#define mx 100
using namespace std;
int par[mx];
int siz[mx];
void init() {
    for(int i=1; i<=10; i++) {
        siz[i] = 1;
        par[i] = i;
    }
}
bool ck = false;
int Find(int n) {
    if(ck)
        cout << "Called with " << n << endl;
    if(n == par[n]) return n;
    return par[n] = Find(par[n]);
}
void Union(int n1, int n2) {
    int p = Find(n1);
    int q = Find(n2);

    if(p != q) {
        if(p > q) swap(p, q);
        if(siz[p] < siz[q])
            swap(p, q);
        par[q] = p;
        siz[p] += siz[q];

    }
}
bool IsF(int n1, int n2) {
    int p = Find(n1);
    int q = Find(n2);
    return (p == q);
}
int main() {
    init();
    Union(2,1); Union(4,2); Union(3,2); Union(3,5); Union(5,7); Union(3,6);
    Union(6,8);
    cout << par[1] << " " << par[6] << " " << par[7] << " " << par[4] << endl;
    ck = true;
    Find(8);
    for(int i=1; i<=8; i++) cout << siz[i] << endl;
    return 0;
}
