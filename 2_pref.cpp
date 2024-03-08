#include<iostream>

using namespace std;
int tab[1000000];
int P[1000000];
int main(){
	int n, k, x, y;
	cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> tab[i];
	P[0] = tab[0];
	for(int i = 1; i < n; i++)P[i] = P[i-1] + tab[i];
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		if(x == 1)cout << P[y-1] << "\n";
		else cout << P[y-1] - P[x-2] << "\n";
	}
	return 0;
}
	
	
