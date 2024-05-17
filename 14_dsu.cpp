#include <iostream>
using namespace std;
int n, m, rep[1000000], s[1000000], a, b;
string q;
int f(a) {
	if (rep[a] != a)
		rep[a] = f(rep[a]);
	return rep[a];
}
void o(a, b) {
	a = f(a);
	b = f(b);
	if (s[a] > s[b]) {
		rep[b] = a;
	}
	else 
		rep[a] = b;
}
int main() {
	cin>>n>>m;
	for (int i = 0; i < n; i++) {
		rep[i] = i;
		s[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin>>q;
		if (q == "JOIN") {
			cin>>a>>b;
			o(a, b);
		}
		if (q == "CHECK") {
			cin>>a>>b;
			if (f(a) == f(b))
				cout<<"TAK"<<'/n';
			else
				cout<<"NIE"<<'/n';
		}
	}
	return 0;
}
