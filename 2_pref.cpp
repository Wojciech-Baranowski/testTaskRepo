#include<bits/stdc++.h>
#define MAXN 1000311

using namespace std;

int n, k, a, b;
int tab[MAXN];
int pref[MAXN];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> tab[i];
	}
	pref[0] = tab[0];
	for(int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + tab[i];
	}
	for(int i = 0; i < k; i++) {
		cin >> a >> b;
		a--;
		b--;
		if(a == 0) {
			cout<<pref[b]<<"\n";
		} else {
			cout<<pref[b] - pref[a - 1]<<"\n";
		}
	}
}
