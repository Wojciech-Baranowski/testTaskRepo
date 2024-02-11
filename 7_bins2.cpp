#include<bits/stdc++.h>
#define MAXN 200311

using namespace std;

int n, k;
int tab[MAXN];
long long roo[MAXN];
int pref[MAXN];

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
		if((long long)tab[n - 1] * tab[n - 1] <= roo[i]) {
			cout<<pref[n - 1]<<" ";
			continue;
		}
		for(int j = 0; j < n - 1; j++) {
			if((long long)tab[j] * tab[j] <= roo[i] && (long long)tab[j + 1] * tab[j + 1] > roo[i]) {
				cout<<pref[j]<<" ";
			}
		}
	}
	cout<<"\n";
	return 0;
}
