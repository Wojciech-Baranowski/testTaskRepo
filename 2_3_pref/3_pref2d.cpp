#include <iostream>
using namespace std;
int tab[1000][1000];
int K[1000];
int W[1000];
int n, k, m;
int solve(int ax, int ay, int bx, int by){
    int wynik = 0;
    if((ax == ay) && (bx == by))return tab[ay - 1][by - 1];
    if(bx == m && ax == 1){
        for(int j = ay - 1; j < by; j++) {
            wynik += W[j];
        }
        return wynik;
    }

    if(by == n && ay == 1){
        for(int j = ax - 1; j < bx; j++) {
            wynik += K[j];
        }
        return wynik;
    }
    if((bx - ax) >= (by - ay)){
        for(int i = ay - 1; i < by; i++)wynik += W[i];
        for(int i = ay - 1; i < by; i++){
            for(int j = bx; j < m; j++)wynik -= tab[i][j];
        }
        return wynik;
    }else{
        for(int j = ax - 1; j < bx; j++)wynik += K[j];
        for(int i = ax - 1; i < bx; i++){
            for(int j = by; j < n; j++)wynik -= tab[j][i];
        }
    }
}
int main() {
    int ax, ay, bx, by;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> tab[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)W[i] += tab[i][j];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)K[i] += tab[j][i];
    }
    for(int i = 0; i < k; i++){
        cin >> ax >> ay >> bx >> by;
        cout << solve(ax, ay, bx, by) << "\n";
    }
    return 0;
}
