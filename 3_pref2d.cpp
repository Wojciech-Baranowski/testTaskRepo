#include<bits/stdc++.h>
#define MAXN 1001

using namespace std;

int n, m, k, ax, ay, bx, by;
int tab[MAXN][MAXN];
int pref[MAXN][MAXN];

int main() {

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> tab[i][j];
		}
	}
	pref[0][0] = tab[0][0];
	for(int i = 1; i < n; i++) {
		pref[i][0] = pref[i - 1][0] + tab[i][0];
	}
	for(int j = 1; j < m; j++) {
		pref[0][j] = pref[0][j - 1] + tab[0][j];
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + tab[i][j];
		}
	}
	for(int i = 0; i < k; i++) {
		cin >> ax >> ay >> bx >> by;
		ax--;
		ay--;
		bx--;
		by--;
		if(ax == 0 && ay == 0) {
			cout<<pref[by][bx]<<"\n";
		} else if(ax == 0) {
			cout<<pref[by][bx] - pref[ay - 1][bx]<<"\n";
		} else if(ay == 0) {
			cout<<pref[by][bx] - pref[by][ax - 1]<<"\n";
		} else {
			cout<<pref[by][bx] - pref[ay - 1][bx] - pref[by][ax - 1] + pref[ay - 1][ax - 1]<<"\n";
		}
	}
	return 0;
}
