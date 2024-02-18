#include<bits/stdc++.h>
#define MAXN 1000311
#define MAXS 1001

using namespace std;

int n;
int tab[MAXN];
int cups[MAXS];
string code;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> code;
		int ptr = 0;
		while(code[ptr] != '1') {
			ptr++;
		}
		ptr += 6;
		tab[i] = 0;
		tab[i] += (code[ptr] - '0') * 1000;
		tab[i] += (code[ptr + 1] - '0') * 100;
		tab[i] += (code[ptr + 2] - '0') * 10;
		tab[i] += (code[ptr + 3] - '0');
	}
	for(int i = 0; i < MAXS; i++) {
		cups[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		cups[tab[i]]++;
	}
	int maxCup = 0;
	int maxCupIdx = 0;
	for(int i = 0; i < MAXS; i++) {
		if(maxCup < cups[i]) {
			maxCup = cups[i];
			maxCupIdx = i;
		}
	}
	if(maxCup == 1000) {
		cout<<"ERROR1000001000"<<"\n";
	} else {
		cout<<"ERROR"<<1000000000 + maxCupIdx<<"\n";
	}
	return 0;
}
