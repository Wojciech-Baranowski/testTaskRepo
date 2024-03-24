#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, k;
int a, b, p, W;
int C[MAXN], P[MAXN + 1];
long long Z[MAXN];

int bin_search (int K) {
	a = 0;
	b = n - 1;
	W = -1;
	while (a <= b) {
		p = (a + b) / 2;
		if (C[p] <= K) {
			a = p + 1;
			W = p;
		} else {
			b = p - 1;
		}
	}
	return W;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> Z[i];
	}

	sort(C, C + n);

	P[0] = 0;
	P[1] = C[0];
	for (int i = 2; i < n + 1; i++) {
		P[i] = P[i - 1] + C[i - 1];
	}

	for (int i = 0; i < k; i++) {
		cout << P[bin_search(sqrt(Z[i])) + 1] << " ";
	}
	cout << "\n";

	return 0;
}
