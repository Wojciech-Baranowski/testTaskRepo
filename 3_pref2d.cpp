#include <iostream>
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	int M[n][m];
	int P[n][m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> M[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		P[i][0] = M[i][0];
		P[0][j] = M[0][j];
	}	
	for (int i = 1; i <= k; i++) {
		int ax, ay, bx, by;	
	}	
}
