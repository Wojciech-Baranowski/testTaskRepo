#include<iostream>

using namespace std;

int tab[1000001], s[1000001];

int find(int a) {
    if (a == tab[a]) {
        return a;
    }
    return tab[a] = find(tab[a]);
}

void onion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (s[a] < s[b]) {
            swap(a, b);
        }
        tab[b] = a;
        s[a] += s[b];
    }
}
void checking(int a, int b) {
    if (find(a) == find(b)) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }
}
int main() {
    int n, m, a, b;
    string w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        tab[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> w >> a >> b;
        if (w == "CHECK") {
            checking(a, b);
        } else {
            onion(a, b);
        }
    }
    return 0;
}
