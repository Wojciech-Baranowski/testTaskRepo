#include <iostream>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int n, k;
int a, b;
int spg, l, l_max;
char s[MAXN];

bool samogloska(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
		return true;
	}
	return false;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	l = 0;
	l_max = 0;
	a = 0;
	b = 0;
	spg = 0;

	while (b < n) {
		if (samogloska(s[b])) {
			spg = 0;
			l = b - a + 1;
			b++;
		} else {
			spg++;
			b++;
			if (spg < k) {
				l = b - a;
			} else {
				l = 0;
				a = b - k + 1;
			}
		}
		l_max = max(l, l_max);
	}

	cout << l_max << "\n";
	return 0;
}
