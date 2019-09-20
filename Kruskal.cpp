#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const int MAXN = 1e6+6; // max number of nodes.

struct edge{
    int from, to;
    ll cost;
    bool operator < (const edge &e) const {
        return  cost < e.cost;
    }
};

struct DSU {

    int id[MAXN], sz[MAXN];

    DSU() {
        for(int i = 0; i < MAXN; i++) {
            id[i] = i, sz[i] = 1;
        }
    }

    int root(int i) {
        while(i != id[i]) {
            i = id[i] = id[id[i]];
        }
        return i;
    }

    bool unite(int a , int b) {
        a = root(a), b = root(b);
        if(a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        if (sz[a] == sz[b]) ++sz[a];
        id[b] = a;
        return 1;
    }
};


ll kruskal(vector<edge> edgeList) { // edges and number of nodes
    DSU D;
    ll mstCost = 0;
    sort(edgeList.begin(), edgeList.end());
    for(int i = 0; i < (int)edgeList.size(); i++) {
        if(D.unite(edgeList[i].from, edgeList[i].to)) {
            mstCost += edgeList[i].cost;
        }
    }
    /*
        if(number of edges != number of nodes - 1
            then there is no mst
    */
    return mstCost;
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<edge> ve(m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %lld", &ve[i].from, &ve[i].to, &ve[i].cost);
    }
    printf("%lld\n", kruskal(ve));

}
