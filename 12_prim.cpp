#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int a, b;
int d = 0, d_max;
bool p[MAXN + 1];

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
			int j = i * 2;
			while (j <= b) {
				p[j] = false;
				j += i;
			}
		}
	}

	for (int i = 2; i <= b; i++) {
		if (p[i] == true) {
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}
