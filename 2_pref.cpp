#include<bits/stdc++.h>
using namespace std; 
int tab[1000000]; 
int P[1000000]; 

int main(){
	int n, k; 
	cin >> n >> k; 
	
	cin >> tab[0]; 
	P[0] = tab[0];
	for (int i = 1; i < n; i++){
		cin >> tab[i];
		P[i] = tab[i] + P[i--]; 
	}
	for (int i = 0; i < k; i++){
		int a, b; 
		cin >> a >> b; 
		cout << P[b-1] - P[a-1] << "\n"; 
	}
	return 0; 
}
