#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 3505;

struct node
{
    int u, v, nx;
    node(){};
    node(int a, int b, int c)
    {
        u = a, v = b, nx = c;
    };
};
node edge[maxn];
int n, r, tot, cnt, tag, ans;
int road[maxn][maxn], walk[maxn][maxn];
int head[maxn], dfn[maxn], low[maxn], inst[maxn], vis[maxn];
stack<int> st;

void addedge(int u, int v)
{
    edge[++tot] = node(u, v, head[u]);
    head[u] = tot;
    edge[++tot] = node(v, u, head[v]);
    head[v] = tot;
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    inst[u] = 1;
    st.push(u);
    for(int i = head[u]; i; i = edge[i].nx)
    {
        int nx = edge[i].v;
        if(nx == fa) continue;
        if(!dfn[nx])
        {
            tarjan(nx, u);
            low[u] = min(low[nx], low[u]);
        }
        else if(inst[nx])
        {
            low[u] = min(dfn[nx], low[u]);
        }
    }
    if(dfn[u] == low[u])
    {
        tag++;
        while(true)
        {
            int x = st.top();
            st.pop();
            vis[x] = tag;
            inst[x] = 0;
            if(x == u) break;
        }
    }
}

void dfs(int u, int fa)
{
    int num = 0;
    inst[u] = 1;
    for(int i = head[u]; i; i = edge[i].nx)
    {
        num++;
       // cout<<u<<endl;
        int nx = edge[i].v;
        //cout<<u<<" "<<nx<<endl;
        if(nx == fa || inst[nx]) continue;
        dfs(nx, u);
        //cout<<u<<endl;
    }
    if(num == 1) ans++;
}

int main()
{
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= r; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        road[u][v] = road[v][u] = 1;
        addedge(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i]) tarjan(i, i);
    }
    //cout<<"here"<<endl;
    memset(head, 0, sizeof(head));
    memset(inst, 0, sizeof(inst));
    tot = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(road[i][j] && vis[i] != vis[j] && !walk[vis[i]][vis[j]])
            {
                walk[vis[i]][vis[j]] = 1;
                addedge(vis[i], vis[j]);
                //cout<<vis[i]<<" "<<vis[j]<<endl;
            }
        }
    }
    dfs(1, -1);
    cout<<(ans+1)/2<<endl;
    return 0;
}
