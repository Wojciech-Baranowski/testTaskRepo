#include <iostream>
using namespace std;
int *a, *b, n, tab[1000000], p[1000000], mocarz;
int main() {
	cin>>n;
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		cin>>tab[i];
		p[i+1] = p[i] + tab[i];
	}
	a = &tab[0];
	b = &tab[0];
	mocarz = 0;
	while (a != n) {
		if (p[*b+1] - p[*a] >= mocarz)
			mocarz = p[*b+1] - p[*a];
		if ( p[*b+1] - p[*a] >= 0) {
			b++;
		}
		else {
			a++;
			b++;
		}
	}
	cout<<mocarz;
	return 0;
}
