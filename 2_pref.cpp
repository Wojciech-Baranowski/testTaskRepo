#include<bits/stdc++.h>
#define MAXN 1000311

using namespace std;

int n, k, a, b, s;
int tab[MAXN];
int pref[MAXN];

int main() {

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> tab[i];
	}
	for(int i = 0; i < k; i++) {
		cin >> a >> b;
		a--;
		b--;
		s = 0;
		for(int j = a; j <= b; j++) {
			s += tab[j];
		}
		cout<<s<<"\n";
	}
	return 0;
}
