#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5;
const int MAXLOG = 21; // at least ciel[log2MAXN]+1;

vector<int> g[MAXN]; // tree adj list
int anc[MAXN][MAXLOG]; // anc[v][i] = 2 to power i ancestor of v,  initialize by -1;
int lv[MAXN]; // lv[i] = level of node i, initialize by 0;


void buildLCA(int v,int p = -1) { // O(NlogN)
	anc[v][0] = p;
	if(p + 1)
		lv[v] = lv[p] + 1;
	for(int i = 0; i < MAXLOG-1; i++)
		if(anc[v][i] + 1)
			anc[v][i+1] = anc[anc[v][i]][i];
	for(auto u: g[v])
        if(p - u)
            buildLCA(u, v);
}

int LCA(int v,int u) { // O(LogN)
	if(lv[v] < lv[u])
		swap(v, u);
	for(int i = MAXLOG - 1;i >= 0; i--)
		if(anc[v][i] + 1 && lv[anc[v][i]] >= lv[u])
			v = anc[v][i];
	if(v == u)
		return v;
	for(int i = MAXLOG-1; i >= 0; i--)
		if(anc[v][i] - anc[u][i])
			v = anc[v][i], u = anc[u][i];
	return anc[v][0];
}

int main() {
    memset(anc, -1, sizeof anc);
    memset(lv, 0, sizeof lv);
    buildLCA(1);
}
