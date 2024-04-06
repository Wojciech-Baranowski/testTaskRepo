#include <bits/stdc++.h>
using namespace std;
int n, k = 0, sigma[1000], s[1000000];
string tab[1000000], p[1000000];
int main() {
	cin>>n;
	for (int i = 0; i < 1000; i++) {
		sigma[i] = 0;
	}
	for (int i = 0; i<n; i++) {
		cin>>tab[i];
		p[i] = tab[i].substr(12,14);
		s[i] = stoi(p[i]);
		sigma[s[i]]++;
	}
	for (int i = 0; i < 1000; i++) {
		if (sigma[i] > sigma[k])
			k = i;
		else if (sigma[i] == sigma[k] && i < k)
			k = i;
	}
	cout<<"ERROR"<<1000000000 + k<<'\n'; 
	return 0;
}
