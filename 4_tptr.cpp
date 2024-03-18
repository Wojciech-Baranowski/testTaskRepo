#include<iostream>
using namespace std;

int tab[1000000];

int find(int n){
    int max = 0, a = 0, b = 0, sum = tab[0];
    while(true){
        if (sum >= 0){
            if (b < n - 1) {
                sum += tab[b];
                b++;
            }
            else{
                sum -= tab[a];
                a++;
            }
        }
        if (sum < 0) {
            if (a == b){
                a++;
                b++;
            }
            else a++;
            sum = tab[a];
        }
        if (sum > max) max = sum;
        if (a == n - 1) break;
    }
    return max;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tab[i];
    }
    cout << find(n) << "\n";
    return 0;
}
