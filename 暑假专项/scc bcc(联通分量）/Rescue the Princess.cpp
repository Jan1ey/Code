//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>


using namespace std;
const int maxn = 200005;
const int maxe = 400005;

int n, m, k;
struct Edge
{
    int to, next;
    bool cut;
}edge[maxe*2];
int head[maxn], tot;
int sp = 20;
int pa[maxn][20], dep[maxn];
int scc[maxn];
bool vis[maxn];
vector<int> p[maxn];
vector<pair<int, int> > e;
int low[maxn], dfn[maxn], Stack[maxn];
int id, top;
int instack[maxn], fa[maxn], fa2[maxn];

int read()
{
    int x = 0,f = 1;
    char c = getchar();
    while (c<'0' || c>'9')
    {
        if (c == '-')
            f = -1;
    c = getchar();
    }
    while (c >= '0'&&c <= '9')
    {
        x = x * 10 + c - '0';
    c = getchar();
    }
    return x*f;
}

void add(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].cut = 0;
    head[u] = tot++;
}
void tarjan(int u, int pre)
{
    //int v;
    low[u] = dfn[u] = ++id;
    Stack[top++] = u;
    //instack[u] = true;
    //int son = 0;
    int pre_cnt = 0;
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre && pre_cnt == 0)
        {
            pre_cnt++;
            continue;
        }
        if(!dfn[v])
        {
            //son++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            //if(low[u] > low[v]) low[u] = low[v];
            if(low[v] > dfn[u])
                edge[i].cut = edge[i^1].cut = true;

        }
        else low[u] = min(low[u], dfn[v]);
    }
    //instack[u] = false;
    top--;
}

int find2(int x)
{
    if(x == fa2[x]) return x;
    return fa2[x] = find2(fa2[x]);
}

void union2(int a, int b)
{
    a = find2(a); b = find2(b);
    fa2[a] = b;
}

int find1(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find1(fa[x]);
}

void union1(int a, int b)
{
    a = find1(a), b = find1(b);
    fa[a] = b;
}

void dfs(int u, int la)
{
    //cout<<u<<" "<<la<<endl;
    pa[u][0] = la; dep[u] = dep[la]+1;
    for(int i = 1; i < sp; i++) pa[u][i] = pa[pa[u][i-1]][i-1];
    for(int i = 0; i < p[u].size(); i++)
    {
        int v = p[u][i];
        if(v == la) continue;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v]) swap(u, v);
    int t = dep[u]-dep[v];
    for(int i = 0; i < sp; i++) if(t&(1<<i)) u = pa[u][i];
    for(int i = sp-1; i >= 0; i--)
    {
        int uu = pa[u][i], vv = pa[v][i];
        if(uu != vv)
        {
            u = uu;
            v = vv;
        }
    }
    return u == v ? u : pa[u][0];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        n = read(), m = read(), k = read();
        e.clear();
        for(int i = 0; i <= n; i++)
        {
            vis[i] = dfn[i] = low[i] = instack[i] = 0;
            head[i] = -1;
            fa2[i] = fa[i] = i;
        }
        id = top = tot = 0;
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            u = read(), v = read();
            add(u, v), add(v, u);
        }
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, i);
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = edge[j].next){
                int v = edge[j].to;
                if(!edge[j].cut) union1(i, v);
                else e.push_back(make_pair(i, v));
                union2(i, v);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(fa[i] == i) scc[++cnt] = i;
        }
        for(int i = 0; i < e.size(); i ++)
        {
            if(e[i].first <= e[i].second) continue;
            int a = find1(e[i].first), b = find1(e[i].second);
            if(a == b) continue;
            p[a].push_back(b); p[b].push_back(a);
        }
        for(int i = 1; i <= n; i++)
        {
            int x = find2(scc[i]);
            if(!vis[x])
            {
                //cout<<x<<endl;
                vis[x] = 1;
                dep[scc[i]] = 0;
                dfs(scc[i], 0);
            }
        }
        for(int i = 1; i <= k; i++)
        {
            int w, u, v;
            w = read(), u = read(); v = read();
            int pw, pu, pv;
            pw = find2(w), pu = find2(u), pv = find2(v);
            if(pw != pu || pw != pv)
            {
                puts("No"); continue;
            }
            int fw = find1(w), fu = find1(u), fv = find1(v);
            if(dep[fu] > dep[fv]) swap(fu, fv);
           // cout<<fw<<" "<<fu<<" "<<fv<<endl;
            if(fw == fv || fu == fw)
            {
                puts("Yes");
                continue;
            }
            int l = lca(fu, fv);
         //   cout<<l<<endl;
         //   cout<<lca(fv,fw)<<" "<<lca(fu, fw)<<endl;
            if(lca(fv, fw) == fw && lca(fw, fu) == fu)
            {
                puts("Yes");
                continue;
            }
            if(lca(l, fw) == l && (lca(fv, fw) == fw || lca(fu, fw) == fw))
            {
                puts("Yes");
                continue;
            }
            puts("No");
        }
        for(int i = 1; i <= cnt; i ++) p[scc[i]].clear();
    }
    return 0;
}
