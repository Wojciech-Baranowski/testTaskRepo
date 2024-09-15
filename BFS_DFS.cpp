#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define VAL 100000

vector<int> graph[VAL];
bool visited[VAL] = {false};

bool DFS(int x, int k) {
	bool found = false;
    visited[x] = true;

    if (x == k) {
        found = true;
    }
    for (int i = 0; i < graph[x].size(); i++) {
        int n = graph[x][i];
        if (!visited[n]) {
            DFS(n, k);
        }
    }
    return found;
}
bool BFS(int x, int k) {
    bool found = false;
    queue<int> q;

    q.push(x);
    visited[x] = true;

    while (!q.empty()) {

        int X = q.front();
        q.pop();

        for (int i = 0; i < graph[X].size(); i++) {
            int n = graph[X][i];
            if (n == k) {
                found = true;
                visited[n] = true;
            }
            if (!visited[n]) {
                q.push(n);
                visited[n] = true;
            }
        }
    }
    return found;
}
int main() {
    int n, m;
    int Vx, Vy;

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> Vx >> Vy;
        graph[Vx - 1].push_back(Vy - 1);
        graph[Vy - 1].push_back(Vx - 1);
    }
    
    if(BFS(0, 6)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    //DFS(0,6);
    
    return 0;
}
