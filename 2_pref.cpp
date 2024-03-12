#include <iostream>
#define MAXN 1000000
using namespace std;

int n, k;
int a, b;
int C[MAXN], P[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}

	P[0] = 0;
	P[1] = C[0];
	for (int i = 2; i < n + 1; i++) {
		P[i] = P[i-1] + C[i-1];
	}

	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		cout << P[b] - P[a - 1] << "\n";
	}

	return 0;
}
