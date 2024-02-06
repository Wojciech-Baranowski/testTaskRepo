#include<bits/stdc++.h>
#define MAXN 1000311

using namespace std;

int n, currSum, maxSum;
int ciag[MAXN];

int main () {
	
	cin >> n;
	maxSum = 0;
	for(int i = 0; i < n; i++) {
		cin >> ciag[i];
	}
	for(int i = 0; i < n; i++) {
		currSum = 0;	
		for(int j = i; j < n; j++) {
			currSum += ciag[j];	
			maxSum = max(maxSum, currSum);
		}
	}
	cout<<maxSum<<"\n";
	return 0;
}
