#include <iostream>
using namespace std;
int n, m, k, ax, ay, bx, by, lx, ly;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	int M[m][n], P[m+1][n+1];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){ 
		cin >> M[j][i];
	}

	P[0][0] = 0;
	for (int i = 1; i < n+1; i++) for (int j = 1; j < m+1; j++) {
		P[j][0] = 0;
		P[0][i] = 0;
		P[j][i] = P[j][i-1] + P[j-1][i] - P[j-1][i-1] + M[j-1][i-1];
	}

	for (int i = 0; i < k; i++) {
		cin >> ax >> ay >> bx >> by;
		lx = bx - ax + 1;
		ly = by - ay + 1;
		cout << P[bx][by] - P[bx - lx][by] - P[bx][by - ly] + P[bx - lx][by - ly] << "\n"; 
	}

	return 0;
}

