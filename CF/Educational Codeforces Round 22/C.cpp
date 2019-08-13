#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;
vector<int> edge[maxn];
int vis[maxn];
bool flag = true;
int deep[maxn];
int va[maxn], vb[maxn];

void dfs(int u, int v)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++)
    {
        int x = edge[u][i];
        if(x == v) continue;
        if(!vis[x])
        {
            deep[x] = deep[u]+1;
            dfs(x, u);
        }
    }
}

void bfs(int x, int v[])
{
    memset(vis, 0, sizeof(vis));
    queue<int> qe;
    qe.push(x);
    vis[x] = 1;
    v[x] = 0;
    while(!qe.empty())
    {
        int u = qe.front();
        qe.pop();
        for(int i = 0; i < edge[u].size(); i++)
        {
            int x = edge[u][i];
            if(!vis[x])
            {
                vis[x] = 1;
                v[x] = v[u]+1;
                qe.push(x);
            }
        }
    }
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    deep[1] = 0;
    dfs(1, 0);
    bfs(1, va);
    bfs(x, vb);
    int ans = 0;
   /* for(int i = 1; i <= n; i++) cout<<deep[i]<<" ";
    cout<<endl;
    for(int i = 1; i <= n; i++) cout<<va[i]<<" ";
    cout<<endl;
    for(int i = 1; i <= n; i++) cout<<vb[i]<<" ";
    cout<<endl;*/
    for(int i = 1; i <= n; i++)
    {
        if(va[i] > vb[i])
        {
            //cout<<i<<endl;
            ans = max(ans, deep[i]);
            //cout<<ans<<endl;
        }
    }
    cout<<ans*2<<endl;
    return 0;
}
