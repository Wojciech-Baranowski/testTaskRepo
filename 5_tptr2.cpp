#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;

char word[N];

bool vowel(char l) {
	return (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'y');
}
int solve(int n, int k) {
	int a = 0, b = 0;
	int max = 0, current = 0, vow = 0;
	
	while(b < n) {
		if(vowel(word[b])) {
			vow = 0; 
			current = b - a + 1;
			b++;
		}
		else {	
			vow++;
			b++;
			if(vow < k) {
				current++; 
			}
			else {
				current = 0; 
				a = b - k + 1;
			}
		}
		if(current > max) max = current;
	}
	return max;
}
int main() {
	int n, k;
	cin >> n >> k;
	 
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	cout << solve(n, k) << "\n";
	return 0;
}
