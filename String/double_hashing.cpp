#include<bits/stdc++.h>
using namespace std;

const int p1 = 31, mod1 = 1e9+7, p2 = 41, mod2 = 1e9+9;
const int N = 1e5 + 9;
int pw1[N], pw2[N];

void prec() {
  pw1[0] = 1;
  for (int i = 1; i < N; i++) {
    pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
  }
  pw2[0] = 1;
  for (int i = 1; i < N; i++) {
    pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
  }
}

pair<int, int> hash_value(string s) {
  int n = s.size();
  int hs1 = 0;
  for (int i = 0; i < n; i++) {
    hs1 += 1LL * (s[i]-'a'+1) * pw1[i] % mod1;
    hs1 %= mod1;
  }
  int hs2 = 0;
  for (int i = 0; i < n; i++) {
    hs2 += 1LL * (s[i]-'a'+1) * pw2[i] % mod2;
    hs2 %= mod2;
  }
  return {hs1, hs2};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  string a, b; cin >> a >> b;
  cout << (hash_value(a) == hash_value(b) ? "Equal" : "Not equal") << '\n';
  return 0;
}
