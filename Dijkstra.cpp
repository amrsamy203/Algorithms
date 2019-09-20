typedef long long ll;

const int MAXN = 1e5+5;
const ll INF = 1e16+16; //greater than (max node wight) * number of nodes;

ll dist[MAXN];
int parent[MAXN];

vector<pair<int, ll> > adj[MAXN];

struct cmp {
    bool operator () (pair<int, ll> a, pair<int, ll> b) {
        return (a.second > b.second);
    }
};

//find the shortest path from the source to every node reachable from it
void dijkstra(int src) {
    for(int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }
    priority_queue<pair<int, ll>, vector<pair<int, ll> >, cmp> q;
    parent[src] = -1;
    q.push({src, dist[src] = 0});
    pair<int, ll> p;
    while(!q.empty()) {
        p = q.top();
        q.pop();
        int node = p.first;
        ll cost = p.second;
        if(dist[node] == cost) {
            for(auto it: adj[node]) {
                int tnode = it.first;
                ll edgeCost = it.second;
                if(cost + edgeCost < dist[tnode]) {
                    parent[tnode] = node;
                    q.push({tnode, dist[tnode] = cost + edgeCost});
                }
            }
        }
    }
}

//get the path from node n to the source;
vector<int> getPath(int v) {
    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    return path;
}
