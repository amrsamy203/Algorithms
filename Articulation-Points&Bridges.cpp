#include <bits/stdc++.h>
using namespace std;

//Articulation Points and Bridges in Undirected Graphs - Tarjan's Algorithm (DFS Variant)
struct ArticulationPointsAndBridges {
    static const int V = 10; // number of vertexes
    vector<int> adjList[V];
    int dfs_low[V], dfs_num[V], parent[V];
    int counter = 0, root = 0, rootChildren = 0;
    bool artPoints[V];
    set<pair<int,int> > bridges;

    void findArtPointsAndBridges(){
        //initialization
        memset(dfs_low, 0, sizeof dfs_low);
        memset(dfs_num, 0, sizeof dfs_num);
        memset(parent, 0, sizeof parent);
        memset(artPoints, 0, sizeof artPoints);

		for(int i = 0; i < V; ++i){
			if(dfs_num[i] == 0){
				root = i;
				rootChildren = 0;
				dfs(i);
				if(rootChildren <= 1) //special case
					artPoints[i] = false;
			}
		}
	}

    void dfs(int u){

		dfs_num[u] = dfs_low[u] = ++counter;

		for(int v: adjList[u]){
			if(dfs_num[v] == 0){
				parent[v] = u;
				if(u == root)
					++rootChildren;
				dfs(v);
				if(dfs_low[v] >= dfs_num[u])
					artPoints[u] = true;
				if(dfs_low[v] > dfs_num[u])
                    bridges.insert(make_pair(min(u,v),max(u,v))); // use u , v instead of min & max;
				dfs_low[u] = min(dfs_low[v], dfs_low[u]);
			}else{
				if(parent[u] != v)
					dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			}
		}
	}

	bool isBridge(int u, int v){ return bridges.count(make_pair(min(u,v),max(u,v))); }

	bool isArticulation(int v){ return artPoints[v]; }
};

int main(){
    int n, m, x, y;
    cin >> n >> m;
    ArticulationPointsAndBridges AB;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        AB.adjList[x].push_back(y);
        AB.adjList[y].push_back(x);
    }
    AB.findArtPointsAndBridges();
    int p = 0;
    for(int i = 0; i < n; i++){
        p+= AB.isArticulation(i);
    }
    cout << p << endl;
    for(int i = 0; i < n; i++){
        if(AB.isArticulation(i))
            cout << i << " ";
    }
    cout << endl;
    cout << (int)AB.bridges.size() << endl;
    for(auto i : AB.bridges){
        cout << i.first << " " << i.second << endl;
    }
}
