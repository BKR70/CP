#include<bits/stdc++.h>
using namespace std;

void getZarr(string str, int Z[]);

void search(string text, string pattern) {
    string concat = pattern + "$" + text;
//    string concat = text;
    int l = concat.length();
    int Z[l];
    getZarr(concat, Z);
    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length()) cout << "Pattern found at index " << i - pattern.length() -1 << endl;
//        cout << Z[i] << " ";
    }
    cout << endl;
}
void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int32_t main() {
    string text = "GEEKS FOR GEEKS";
    //string text = "aabxaabxcaabxaabxay";
    string pattern = "GEEK";
    search(text, pattern);
    return 0;
}
