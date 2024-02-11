#include<bits/stdc++.h>

using namespace std;

int n, k;
string s;
int currSum, maxSum;
int d;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	cin >> n >> k >> s;
	currSum = maxSum = d = 0;
	for(int i = 0; i < n; i++) {
		if(isVowel(s[i])) {
			d = k - 1;
			currSum = min(k, i + 1);
			for(int j = i + 1; j < n; j++) {
				if(isVowel(s[j])) {
					d = k;
				}
				if(d == 0) {
					maxSum = max(maxSum, currSum);
					break;
				}
				currSum++;
				d--;
			}
			maxSum = max(maxSum, currSum);
		}
	}
	cout<<maxSum<<"\n";
}
