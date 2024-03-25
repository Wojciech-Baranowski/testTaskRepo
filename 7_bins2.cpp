#include<bits/stdc++.h>
using namespace std;
int tab[200000];
int pref[200000]; 

int binSearch(int a, int b, int t) {
    if (a == b) {
        return a;
    }
    int mid = (a + b)>>1;
    if (tab[mid] <= t && (mid == b || tab[mid + 1] > t)) {
        return mid;
    }
    if (tab[mid] > t) {
        return binSearch(a, mid - 1, t);
    }
    else {
        return binSearch(mid, b, t);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    sort (tab, tab+n);
    
    pref[0] = tab[0];    
    for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + tab[i]; 
	}
    for (int i = 0; i < k; i++) {
        int t; 
        cin >> t;
        cout << pref[binSearch(0, n - 1, sqrt(t)) - 1] << "\n";
    }
    cout << "\n";
    return 0; 
}
