#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, p, q, odp[100311];
bool  vis[100311];
vector<int> g[100311];
void dfs(int x, int y) {
    vis[x] = 1;
    for (int i = 1; i <= g[x].size(); i++) {
        if (g[x][i] != y) {
            if (vis[g[x][i]] == 1) {
                p = x;
                q = g[x][i];
                for (int j = 1; j <= g[p].size(); j++) {
                    if (g[p][j] == q)
                        swap(g[p][j], g[p].back());
                }
                for (int j = 1; j <= g[q].size(); j++) {
                    if (g[q][j] == p)
                        swap(g[q][j], g[q].back());
                }
                g[p].pop_back();
                g[q].pop_back();
                odp[p] = q;
            }
            else {
                odp[g[x][i]] = x;
                dfs(g[x][i], x);
            }
        }
    }
}
int main() {
    cin>>n>>m;
    if (m < n) {
        cout<<"NIE"<<'\n';
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    dfs(p, q);
    cout<<"TAK"<<'\n';
    for (int i = 0; i < n; i++) {
        cout<<odp[i]<<'\n';
    }
    return 0;
}