#include <bits/stdc++.h>
using namespace std;
int n, k, tab[200000], q[200000], moc;
int bin(int a, int b, int s) {
    if (s >= tab[(a + b)/2] && s < tab[(a + b)/2 + 1]) {
        return (a + b)/2;
    }
    else if (s < tab[(a + b)/2]) {
        return bin(a, (a + b)/2 - 1, s);
    }
    else {
        return bin((a + b)/2 + 1, b, s);
    }
}
int main() {
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        cin>>tab[i];
    }
    for (int i = 0; i < k; i++) {
        cin>>q[i];
    }
    sort(tab, tab+n);
    for (int i = 0; i < k; i++) {
        moc = 0;
        for (int j = 0; j <= bin(0, n-1, sqrt(q[i])); j++) {
            moc += tab[j];
        }
        cout<<moc<<endl;
    }
    return 0;
}