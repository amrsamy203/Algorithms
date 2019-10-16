#include <bits/stdc++.h>

using namespace std;
const int MAX1 = 2e5 + 5;
int maxcount1 = INT_MIN;
vector<int> adj1[MAX1];
bool vis1[MAX1];
int N, M, u, v, L1, L2, x;
void dfs(int ch, int coun)
{
    if(vis1[ch])
        return;
    vis1[ch] = true;
    coun++;
    for(int i = 0; i < (int)adj1[ch].size(); i++)
    {
        if(!vis1[adj1[ch][i]]) {
            if(coun >= maxcount1) {
                maxcount1 = coun;
                x = adj1[ch][i];
            }
            dfs(adj1[ch][i], coun);
        }
    }
}
void init()
{

}
int main()
{
    int coun = 0;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++)
    {
        scanf("%d%d", &u, &v);
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    dfs(1, coun+1);
    coun = 0;
    memset(vis1, 0, sizeof vis1);
    dfs(x, coun+1);
    int ans1 = maxcount1;
    //cout << maxcount1 << endl;

    for(int i = 0; i < MAX1; i++)
        adj1[i].clear();


    scanf("%d", &M);
    for(int i = 0; i < M - 1; i++)
    {
        scanf("%d%d", &u, &v);
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    x = 0;
    memset(vis1, 0, sizeof vis1);
    maxcount1 = INT_MIN;
    coun = 0;
    dfs(1, coun+1);
    coun = 0;
    memset(vis1, 0, sizeof vis1);
    dfs(x, coun+1);
    int ans2 = ceil(maxcount1*1.0/2.0);
    //cout << ans2 << endl;
    if(ans1 > ans2)
    {
        cout << "GGEZ";
    }
    else
        cout << "FF";
}
