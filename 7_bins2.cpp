#include<bits/stdc++.h>
#define MAXN 200311

using namespace std;

int n, k;

int tab[MAXN];
long long roo[MAXN];
int pref[MAXN]; 

int binSearch(int a, int b, long long k0) {
	if(b - a <= 1) {
		if((long long)tab[b] * tab[b] > k0) {
			while(a < n - 1 && tab[a] == tab[a + 1]) a++;
			return pref[a];
		} else {
			while(b < n - 1 && tab[b] == tab[b + 1]) b++;
			return pref[b];
		}
	}
	int p = (a + b) >> 1;
	if((long long) tab[p] * tab[p] > k0) {
		return binSearch(a, p - 1, k0);
	} else {
		return binSearch(p, b, k0);
	}
}

int main() {

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> tab[i];
	}
	for(int i = 0; i < k; i++) {
		cin >> roo[i];
	}
	sort(tab, tab + n);
	pref[0] = tab[0];
	for(int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + tab[i];
	}
	for(int i = 0; i < k; i++) {
		if((long long)tab[0] * tab[0] > roo[i]) {
			cout<<0<<" ";
		} else {
			cout<<binSearch(0, n - 1, roo[i])<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
