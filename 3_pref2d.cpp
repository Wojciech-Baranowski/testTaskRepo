#include<bits/stdc++.h>
#define MAXN 1001

using namespace std;

int n, m, k, ax, ay, bx, by, s;
int tab[MAXN][MAXN];
int pref[MAXN][MAXN];

int main() {

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> tab[i][j];
		}
	}
	
	for(int i = 0; i < k; i++) {
		cin >> ax >> ay >> bx >> by;
		ax--;
		ay--;
		bx--;
		by--;
		s = 0;
		for(int j = ax; j <= bx; j++) {
			for(int jj = ay; jj <= by; jj++) {
				s += tab[jj][j];
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
