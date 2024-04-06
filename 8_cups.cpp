#include<bits/stdc++.h>
using namespace std;

int tab[1000000];
int cup[1000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < 1000; i++) {
        cup[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        string number; 
        number = s.substr(5); 
        tab[i] = stoi(number);
        cup[tab[i] - 1000000000]++;
    }
    int max = 0, error = 0;
    for (int i = 0; i < 1000; i++) {
        if(cup[i] > max) {
            max = i; 
        }
    }
    cout << "ERROR" << max + 1000000000<< "\n";
    return 0;
}
