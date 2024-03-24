#include<bits/stdc++.h>
using namespace std; 
long t, n, m, k; 

int binSearch(long a, long b) { 
	if (a == b) { 
		return a; 
	} 
	long mid = (a + b)>>1;  
	if ((mid*m)+(t-mid)*n >= k) {
		return binSearch(a, mid); 
	} else {
		return binSearch(mid + 1, b); 
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t >> n >> m >> k;	
	if (m*t < k) {
		cout << "POMOC" << "\n";
	} else if (n*t >= k){
		cout << 0 << "\n"; 
	} else {
		cout << binSearch(1, t*m) << "\n"; 
	}
	
	return 0; 
}
