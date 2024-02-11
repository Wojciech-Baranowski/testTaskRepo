#include<bits/stdc++.h>

using namespace std;

long long t, n, m, k;

int binSearch(int a, int b) {
	if(b - a <= 1) {
		if((t - a) * n + a * m >= k) {
			return a;
		} else {
			return b;
		}
	}
	int p = (a + b) >> 1;
	if((t - p) * n + p * m >= k) {
		return binSearch(a, p);
	} else {
		return binSearch(p + 1, b);
	}
}

int main() {
	cin >> t >> n >> m >> k;
	if(t * m < k) {
		cout<<"POMOC"<<"\n";
		return 0;
	}
	cout<<binSearch(0, t + 1)<<"\n";
	return 0;
}
