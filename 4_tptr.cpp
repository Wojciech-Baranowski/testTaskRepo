#include <iostream>
#define MAXN 1000000
using namespace std;

int n;
int a, b;
int c[MAXN], c_maks, c_suma;

int maks(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	a = 0;
	b = 0;
	c_maks = maks(0, c[0]);
	c_suma = maks(0, c[0]);

	while (a < n) {
		if (c_suma >= 0) {
			if (b < n) {
				b++;
				c_suma += c[b];
			} else {
				c_suma -= c[a];
				a++;
			}
		} else {
			if (a == b) {
				a++;
				b++;
				c_suma = c[a];
			} else {
				c_suma -= c[a];
				a++;
			}
		}
		c_maks = maks(c_maks, c_suma);
	}

	cout << c_maks << "\n";
}
