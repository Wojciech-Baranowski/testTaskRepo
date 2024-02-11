#include<bits/stdc++.h>

using namespace std;

int n, k, l, r;
string s;
int maxSum;
int currSum;
int d;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	cin >> n >> k >> s;
	maxSum = currSum = d = 0;
	for(int i = 0; i < n; i++) {
		if(isVowel(s[i])) {
			d = k;
			if(currSum == 0) {
				currSum += min(k - 1, i);
			}
		}
		if(d <= 0) {
			maxSum = max(maxSum, currSum);
			currSum = 0;
		} else {
			currSum++;
		}
		d--;
	}
	maxSum = max(maxSum, currSum);
	cout<<maxSum<<"\n";
}
