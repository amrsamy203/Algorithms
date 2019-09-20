#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2005];
int side[2005]; // the side of each node in the bipartite graph

//Theorem:
//a graph is bipartite if and only if all its cycles have even length.
//Also: a graph is bipartite if and only if it is two-colorable.
bool isBipartite(int n) { // O(V+E).
    bool is = 1;
    queue<int> q;
    for(int st = 1; st <= n; st++) { // one based
        if(side[st] == -1) {
            side[st] = 0;
            q.push(st);
            while(!q.empty()) {
                int nd = q.front();
                q.pop();
                for(int u : adj[nd]) {
                    if(side[u] == -1) {
                        side[u] = side[nd] ^ 1; // child is not colored: must have different color than parent
                        q.push(u);
                    } else {
                        is &= side[u] ^ side[nd]; // child is already colored: check if its color is different than parent
                    }
                }
            }
        }
    }
    return is;
}

int main() {
    int  n, m, u, v;
    scanf("%d %d", &n, &m);
    memset(side, -1, sizeof side);
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    puts(isBipartite(n)? "Bipartite!" :"Not Bipartite!" );
}
