#include <iostream> 
#define MAXN 1000
using namespace std;

int n, m, k;
int ax, ay, bx, by; 
int lx, ly; 
int M[MAXN][MAXN], P[MAXN+1][MAXN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { 
			cin >> M[j][i];
		}
	}

	P[0][0] = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			P[j][0] = 0;
			P[0][i] = 0;
			P[j][i] = P[j][i - 1] + P[j - 1][i] - P[j - 1][i - 1] + M[j - 1][i - 1];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> ax >> ay >> bx >> by;
		lx = bx - ax + 1;
		ly = by - ay + 1;
		cout << P[bx][by] - P[bx - lx][by] - P[bx][by - ly] + P[bx - lx][by - ly] << "\n"; 
	}

	return 0;
}

