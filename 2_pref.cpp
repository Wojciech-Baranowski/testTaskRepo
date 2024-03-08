#include <iostream>
using namespace std;

int n, k;
int C[n];
int P[n];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> C[i];
	P[0] = C[0];
	for (int i = 1; i < n; i++) P[i] = P[i-1] + C[i];
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a == 0) cout << P[b] << "\n";
		else cout << P[b] - P[a-1] << "\n";
	}
}
