#include <iostream>
using namespace std;
int a=0, b=0, n, tab[1000000], p[1000000], mocarz=0;
int main() {
	cin>>n;
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		cin>>tab[i];
		p[i+1] = p[i] + tab[i];
	}
	while (b != n) {
		if (p[b+1] - p[a] >= mocarz)
			mocarz = p[b+1] - p[a];
		if ( p[b+1] - p[a] >= 0) {
			b++;
		}
		else if (a<b) {
			a++;
		}
		else {
			a++;
			b++;
		}
	}
	cout<<mocarz;
	return 0;
}
