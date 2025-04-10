/** Sparse Table **/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105000, MAXLOG = 20;
int n;
int ar[MAXN];
int table[MAXLOG][MAXN];
int logs[MAXN];
void computeLogs() {                /// Precalculate log(n)
    logs[1] = 0;
    for(int i=2; i<=n; i++) {
        logs[i] = logs[i/2]+1;
    }
}
void buildSparseTable() {               /// Build sparse table
    for(int i=0; i<=logs[n]; i++) {
        int curLen = 1 << i;
        for(int j=0; j+curLen<=n; j++) {
            if(curLen == 1) {
                table[i][j] = ar[j];
            }
            else {
                /// for both of max and min number queries
                ///table[i][j] = min(table[i-1][j],table[i-1][j+(curLen/2)]);
                table[i][j] = max(table[i-1][j],table[i-1][j+(curLen/2)]);                  /// two equal part's min value stored (2^n)/2
            }
        }
    }

}
int getMin(int l,int r) {                                   /// query for minimum value in this range.
    int p = logs[r-l+1];
    int pLen = 1 << p;
    ///return min(table[p][l],table[p][r-pLen+1]);          /// for both of max and min number queries
    return max(table[p][l],table[p][r-pLen+1]);
}
int main() {
    cout << "Enter total number of values : "; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    computeLogs();
    buildSparseTable();
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        l--, r--;
        cout << getMin(l,r) << endl;
    }
    return 0;
}
