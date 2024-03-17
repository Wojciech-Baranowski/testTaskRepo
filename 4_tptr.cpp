#include <iostream>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int n;
int a, b;
int suma, maks_suma;

int c[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	a = 0;
	b = 0;
	suma = max(0, c[0]);
	maks_suma = max(0, c[0]);

	while (a < n) {
		if (suma >= 0) {
			if (b < n) {
				b++;
				suma += c[b];
			} else {
				suma -= c[a];
				a++;
			}
		} else {
			if (a == b) {
				a++;
				b++;
				suma = c[a];
			} else {
				suma -= c[a];
				a++;
			}
		}
		maks_suma = max(maks_suma, suma);
	}

	cout << maks_suma << "\n";
	return 0;
}
