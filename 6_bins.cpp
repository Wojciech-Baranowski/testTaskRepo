#include<bits/stdc++.h>

using namespace std;

long long t, n, m, k;

int main() {
	cin >> t >> n >> m >> k;
	if(t * m < k) {
		cout<<"POMOC"<<"\n";
		return 0;
	}
	if(t * n >= k) {
		cout<<0<<"\n";
		return 0;
	}
	for(int i = 0; i < t; i++) {
		if(((t - i) * n + i * m < k) && ((t - i - 1) * n + (i + 1) * m >= k)) {
			cout<<i + i<<"\n";
			return 0;
		}
	}
	return 0;
}
