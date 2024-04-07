#include <bits/stdc++.h>
using namespace std;
int n, tab[1000000], king[1000], d[1000000];
string opis[1000][100], t[1000000];
int main() {
    cin>>n;
    for (int i = 0; i < 1000; i++) {
        king[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin>>tab[i];
        cin>>t[i];
        d[i] = t[i].length();
        opis[tab[i]][d[i]] = t[i];
        king[tab[i]]++;
    }
    for (int i = 999; i >= 0; i--) {
        if (king[i] >= 1) {
            for (int j = 0; j < 100; j++) {
                if (!opis[i][j].empty())
                    cout<<i<<' '<<opis[i][j]<<'\n';
            }
        }
    }
    return 0;
}