#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int C[n];
	for (int i = 0; i < n; i++) cin >> C[i];
	int P[n];
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
