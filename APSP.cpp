#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct APSP{

    static const int MAXN = 205; //larger than number of nodes
    static const int inf = 1e9; //larger than any possible path between any two nodes
    //be careful that 2*inf must fit in the data type

    int adj[MAXN][MAXN]; //distance array
    int path[MAXN][MAXN]; //path array

    void getPath(int src, int dest) { //source , destination
        if(path[src][dest] == -1) {
            cout << src << " "; // beytalla3 kolo ma 3ada a5er node
            return;
        }
        getPath(src, path[src][dest]);
        getPath(path[src][dest], dest);
    }

    void initialize(){
        memset(path,-1, sizeof path);
            for(int i = 0; i < MAXN; i++)
                for(int j = 0; j < MAXN; j++)
                    adj[i][j] = inf;
    }

    void floyd(int n){ //O(n^3)
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                        path[i][j] = k;
                    }
    }


    void floyd2(int n){
        // 0 - Infinity MUST be larger than any path. Say we have n = 1000, and cost of edge max 5000, then min OO to = (1000-1) * 5000 + 1
        // 1- Set whole array to infinity:
        // 2- read input edges
        // 3- set diagonal to zeros: sometimes, if negative input you would like to leave them: e.g. adj[3][3] = -7 -> a self cycle
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(adj[i][k] < inf && adj[k][j] < inf)  // you could remove this line IFF 2*OO fit in the data type.
                        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
    }


    void TransitiveClosure(int n){
        // assume matrix is 0 for disconnect, 1 is connect
        // we only care if a path exist or not, not a shortest path value
        // adj[][] here is boolean array;
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    adj[i][j] |= (adj[i][k] & adj[k][j]);
    }


    void minimax(int n){
        // find path such that max value on road is minimum
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]) );
    }


    void maximin(int n){
        // find path such that min value on road is maximum
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]) );
    }


    void longestPathDAG(int n){

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    adj[i][j] = max(adj[i][j], adj[i][k]+adj[k][j] );
    }


    void countPaths(int n){ // Floyd warshal for counting #of paths

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    adj[i][j] += adj[i][k] * adj[k][j];
    }


    /*
    If you had a cycle in a graph, the longest path wouldn't be
    well defined, because you could keep going round and round the cycle
    making the path longer.
    */

    bool isNegativeCycle(int n) { //checks if there is a negative cycle
        for(int i = 0; i < n; ++i)
            if(adj[i][i] < 0)
                return true;    // then node i got to i with overall cost < 0.
        return false;
    }


    bool anyEffectiveCycle(int src, int dest, int n=MAXN){
        for(int i = 0; i < n; ++i)
            if(adj[i][i] < 0 && adj[src][i] < inf && adj[i][dest] < inf)
                return true;
        return false;   // there is a finite path although cycles if any
    }


    int graphDiameter(int n=MAXN){ // Longest path among all shortest ones

        floyd2(n);
        int mx = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(adj[i][j] < inf)
                    mx = max(mx, adj[i][j]);
        return mx;
    }


    vector< vector<int> > SCC(int n=MAXN){
        vector<int> comp(n, -1);

        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(comp[i]==-1) {
                comp[i] = cnt++;
                for(int j = 0; j < n; ++j)
                    if(adj[i][j] < inf && adj[j][i] < inf) // transitive clusre is enough
                        comp[j] = comp[i];
            }

        vector< vector<int> > compGraph(cnt, vector<int>(cnt));

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(adj[i][j] < inf)
                    compGraph[comp[i]][comp[j]] = 1;    // DAG

        return compGraph;
    }

};

int main(){
        APSP ap;
        ap.initialize(); //initialize adj and path arrays;
        //read the graph adj[i][j] for all available i and j;
        ap.floyd(n); //run Floyd Warshal on the graph in adj
}
