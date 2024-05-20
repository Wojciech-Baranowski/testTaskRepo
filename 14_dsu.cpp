#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int rep[N];

int find(int a) {
	if (rep[a] != a) {
		rep[a] = find(rep[a]);
	}
	return rep[a];
}
void onion(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a > b) {
        rep[b] = a;
	} else {
		rep[a] = b;
	}
}
void check(int a, int b) {
    if (find(a) == find(b)) {
		cout << "TAK\n";
	} else {
		cout << "NIE\n";
	}
}
int main() {
    int a, b, n, m;
    string s;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
		rep[i] = i;
	}
    for (int i = 0; i < m; i++) {
        cin >> s >> a >> b;
        if (s == "JOIN") {
            onion(a, b);
        }
        if (s == "CHECK") {
            check(a, b);
        }
    }
    return 0;
}
