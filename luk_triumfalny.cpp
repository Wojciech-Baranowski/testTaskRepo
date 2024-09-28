#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 300311

vector<int> graph[MAX];
bool visited[MAX];
int depth[MAX];
int depthCount[MAX];

void BFS(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        int x0 = q.front();
        q.pop();
        for (int i = 0; i < graph[x0].size(); i++) {
            if (!visited[graph[x0][i]]) {
                visited[graph[x0][i]] = true;
                depth[graph[x0][i]] = depth[x0] + 1;
                q.push(graph[x0][i]);
            }
        }
    }
}

void DFS(int x, int parent) {
    visited[x] = true;
    if (parent != -1) {
        depth[x] = depth[parent] + 1;
    }
    for (int i = 0; i < graph[x].size(); i++) {
        int n = graph[x][i];
        if (!visited[n]) {
            DFS(n, x);
        }
    }
}

bool workers(int k, int n) {
    long additional = 0;
    for (int i = 2; i <= n; i++) {
        if (k + additional < depthCount[i]) {
            return false;
        } else {
            additional = additional + k - depthCount[i];
        }
    }
    return true;
}
int solve(int a, int b, int n) {
    if (b - a <= 1) {
        if (workers(a, n)) {
            return a;
        } else {
            return b;
        }
    }
    int k = (a + b)>>1;

    if (workers(k, n)) {
        return solve(a, k, n);
    } else {
        return solve(k + 1, b, n);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n;
    //n = 300000;

    for (int i = 0; i < n - 1; i++) {
        //x = i + 1;
        //y = i + 2;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    depth[1] = 1;
    BFS(1);

    for (int i = 1; i <= n; i++) {
        depthCount[depth[i]]++;
    }
    cout << solve(0, n, n) << "\n";

    return 0;
}
