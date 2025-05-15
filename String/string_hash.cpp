#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7, p = 31, mod = 1e9+9;
int pw[N];
void prec() {
	pw[0] = 1;
	for(int i=1; i<N; i++) {
		pw[i] = 1ll * pw[i-1] * p % mod;
	}
}
int hash_value(string s) {
	int n; n = s.size();
	int ans = 0;
	for(int i=0; i<n; i++) {
		ans += 1ll * (s[i]-'a'+1) * pw[i] % mod;
		ans %= mod;
	}
	return ans;
}
int main() {
	int n; cin >> n;
	int sv[n];
	prec();
	for(int i=0; i<n; i++) {
		string s; cin >> s;
		sv[i] = hash_value(s);
	}
	for(int i=0; i<n; i++) {
		cout << sv[i] << '\n';
	}
	return 0;
}
