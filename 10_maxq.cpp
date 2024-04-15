#include <bits/stdc++.h>
#define MAXN 1000000
#define x first
#define y second
using namespace std;

int n;
char p[MAXN];
int k, l;
string S;
deque<pair<pair<string, int>, int>> kolejka;

void pushuj(string s, int X) {
	int cnt = 0;
	while (!kolejka.empty() && kolejka.back().x.y <= X) {
		cnt += kolejka.back().y + 1;
		kolejka.pop_back();
	}
	kolejka.push_back({{s, X}, cnt});
}

void popuj() {
	if (kolejka.front().y == 0) {
		kolejka.pop_front();
	} else {
		kolejka.front().y--;
	}
}

string front1() {
	return kolejka.front().x.x;
}

int front2() {
	return kolejka.front().x.y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		switch (p[i]) {
			case 'A':
				cin >> k >> S;
				pushuj(S, k);
				break;
			case 'D':
				popuj();
				break;
			case 'R':
				cout << front1() << " " << front2() << "\n";
				break;
		}
	}

	return 0;
}
