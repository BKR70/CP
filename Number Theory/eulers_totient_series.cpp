#include<bits/stdc++.h>
using namespace std;
void computeTotient(int n) {
	int phi[n+1];
	for (int i=1; i<=n; i++) {
		phi[i] = i;
	}
	for (int p=2; p<=n; p++) {
		if (phi[p] == p)
		{
			phi[p] = p-1;
			for (int i = 2*p; i<=n; i += p)
			{
                phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}
	for (int i=1; i<=n; i++) {
        cout << "Totient of " << i << " is " << phi[i] << endl;
	}
}
int main() {
	int n = 12;
	computeTotient(n);
	return 0;
}
