#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;

bool prime[N + 1];
vector<int> tab;

void sieve() {
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i < N; i++) {
        prime[i] = true;
    }
    for(int i = 2; i*i < N; i++) {
        if(prime[i]) {
            int j = i<<1;
            tab.push_back(i);
            while(j <= N) {
				prime[j] = false;
				j += i;
			}
        }
    }
}
int solve(int a, int b) {
	int Max = 0;
	int tmp = 2;
	int dif; 
	for(int i = 0; i < tab.size(); i++) {
		if(tab[i] > b) {
			break; 
		}
		if(tab[i] >= a) {
			dif = tab[i + 1] - tab[i];
			
			if(tab[i + 2] - tab[i + 1] != dif) {
				tmp = 2;
			}
			else {
				tmp++;
			}
			if(tmp > Max) {
				Max = tmp;
			}
		}
	}
	return Max; 
}
int main() {
    int a, b;
    cin >> a >> b;
    sieve();
    cout << solve(a, b) << "\n";
    return 0;
}
