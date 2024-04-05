#include <iostream>
using namespace std;
int n, k = 0;
string tab[1000000], sigma[1000];
string num(string wyraz) {
    string numb;
    int pozycja = 0;
	while (isdigit(wyraz[pozycja])) {
		numb += wyraz[pozycja];
		pozycja++;
    }
     return numb;
   }
int main {
	cin>>n;
	for (int i = 0; i < 1001; i++) {
		sigma[i] = 0;
	}
	for (int i = 0; i<n; i++) {
		cin>>tab[i];
		sigma[1000000000 - num(tab[i])] += 1;
	}
	for (int i = 0; i < 1001; i++) {
		if sigma[i] > k
			k = sigma[i];
	}
	cout<<"ERROR"<<1000000000 + k<<'\n' 
	return 0;
}
