#include<bits/stdc++.h>
using namespace std;

/// Given an integer n and a prime number p, find the largest x such that p^x divides n! (factorial) in O(logn).

int legendre(long long n, long long p) {
  int ans = 0;
  while (n) {
    ans += n / p;
    n /= p;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}
