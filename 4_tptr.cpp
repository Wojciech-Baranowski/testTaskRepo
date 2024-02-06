#include<bits/stdc++.h>
#define MAXN 1000311

using namespace std;

int n, l, r, maxSum, currSum;
int ciag[MAXN];

int main() {
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ciag[i];
	}
	l = r = 0;
	maxSum = currSum = max(0, ciag[0]);
	while(l < n) {
		if(currSum >= 0 && r < n) {
			r++;
			currSum += ciag[r];
		} else if(r == l) {
			r++;
			l++;
			currSum = ciag[l];
		} else {
			currSum -= ciag[l];
			l++;
		}
		maxSum = max(maxSum, currSum);
	}
	cout<<maxSum<<"\n";
	return 0;
}
