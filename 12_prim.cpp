#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int a, b;
int d = 2, d_max;
bool p[MAXN + 1];
int t[MAXN + 1];
int l = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	p[0] = false;
	p[1] = false;
	for (int i = 2; i <= b; i++) {
		p[i] = true;
	}
	for (int i = 2; i <= b; i++) {
		if (p[i] == true) {
			int j = i << 1;
			while (j <= b) {
				p[j] = false;
				j += i;
			}
		}
	}

	for (int i = a; i <= b; i++) {
		if (p[i] == true) {
			t[l] = i;
			l++;
		}
	}

	for (int i = 0; i <= l - 2; i++) {
		if (t[i + 2] - t[i + 1] == t[i + 1] - t[i]) {
			d++;
		} else {
			d = 2;
		}
		d_max = max(d, d_max);
	}

	cout << d_max << "\n";
	
	return 0;
}
